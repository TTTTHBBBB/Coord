#include <QDebug>
#include <QTranslator>

#include "bannacontrol.h"
#include "ui_bannacontrol.h"


BannaControl::BannaControl(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BannaControl)
{
    ui->setupUi(this);
    this->initValue();
}

BannaControl::~BannaControl()
{
    delete ui;
}

void BannaControl::initValue()
{
    this->installEventFilter(this);

    this->setWindowFlags(Qt::FramelessWindowHint);
    changeImageTimer = new QTimer(this);
    connect(changeImageTimer, &QTimer::timeout , this, &BannaControl::Slot_changeImageTimer);
    changeImageTimer->setInterval(BannaSpace::INTERVAL_TIMER);
    changeImageTimer->start();

    buttonGroup.addButton(ui->pushButtonFirst);
    buttonGroup.addButton(ui->pushButtonSecond);
    buttonGroup.addButton(ui->pushButtonThird);
    buttonGroup.addButton(ui->pushButtonFourth);
    buttonGroup.addButton(ui->pushButtonFifth);

    connect(ui->pushButtonLeft, &QPushButton::clicked, this, &BannaControl::Slot_pushButtonLeft);
    connect(ui->pushButtonRight, &QPushButton::clicked, this, &BannaControl::Slot_pushButtonRight);

    ui->labelThird->raise();//将控件的层级提升到其他控件之上
    ui->labelFifth->lower();//将控件的层级降到其他的控件之下

    {
        BannaData bannaData;
        bannaData.LanguageType = CoordSpace::Japanese;
        bannaData.pushButton = ui->pushButtonFirst;
        bannaData.currentImageLabel = ui->labelFirst;
        bannaData.nextImageLabel = ui->labelSecond;
        bannaData.preImageLabel = ui->labelFifth;
        bannaData.proAnimation = new QPropertyAnimation(ui->labelFirst, BannaSpace::ANIMATION_GEOMETRY);
        bannaDataList.append(bannaData);
    }


    {
        BannaData bannaData;
        bannaData.LanguageType = CoordSpace::Spanish;
        bannaData.pushButton = ui->pushButtonSecond;
        bannaData.currentImageLabel = ui->labelSecond;
        bannaData.nextImageLabel = ui->labelThird;
        bannaData.preImageLabel = ui->labelFirst;
        bannaData.proAnimation = new QPropertyAnimation(ui->labelSecond, BannaSpace::ANIMATION_GEOMETRY);
        bannaDataList.append(bannaData);
    }


    {
        BannaData bannaData;
        bannaData.LanguageType = CoordSpace::Chinese;
        bannaData.pushButton = ui->pushButtonThird;
        bannaData.currentImageLabel = ui->labelThird;
        bannaData.nextImageLabel = ui->labelFourth;
        bannaData.preImageLabel = ui->labelSecond;
        bannaData.proAnimation = new QPropertyAnimation(ui->labelThird, BannaSpace::ANIMATION_GEOMETRY);
        bannaDataList.append(bannaData);
    }


    {
        BannaData bannaData;
        bannaData.LanguageType = CoordSpace::English;
        bannaData.pushButton = ui->pushButtonFourth;
        bannaData.currentImageLabel = ui->labelFourth;
        bannaData.nextImageLabel = ui->labelFifth;
        bannaData.preImageLabel = ui->labelThird;
        bannaData.proAnimation = new QPropertyAnimation(ui->labelFourth, BannaSpace::ANIMATION_GEOMETRY);
        bannaDataList.append(bannaData);
    }


    {
        BannaData bannaData;
        bannaData.LanguageType = CoordSpace::German;
        bannaData.pushButton = ui->pushButtonFifth;
        bannaData.currentImageLabel = ui->labelFifth;
        bannaData.nextImageLabel = ui->labelFirst;
        bannaData.preImageLabel = ui->labelFourth;
        bannaData.proAnimation = new QPropertyAnimation(ui->labelFifth, BannaSpace::ANIMATION_GEOMETRY);
        bannaDataList.append(bannaData);
    }

    for(int i = 0; i < bannaDataList.size(); i++)
    {//给每个控件添加事假过滤器，给每个动画设置持续时间，动画效果
        bannaDataList.at(i).currentImageLabel->installEventFilter(this);
        bannaDataList.at(i).proAnimation->setDuration(BannaSpace::ANIMATION_DURTION);
        bannaDataList.at(i).proAnimation->setEasingCurve(QEasingCurve::BezierSpline);
        animationGroup.addAnimation(bannaDataList.at(i).proAnimation);
    }

    QList<QString> listImagePath;
    listImagePath.append(BannaSpace::FIRST_IMAGE_PATH);
    listImagePath.append(BannaSpace::SECOND_IMAGE_PATH);
    listImagePath.append(BannaSpace::THIRD_IMAGE_PATH);
    listImagePath.append(BannaSpace::FOURTH_IMAGE_PATH);
    listImagePath.append(BannaSpace::FIFTH_IMAGE_PATH);
    this->addAnimationPixmap(listImagePath);

    ui->pushButtonLeft->raise();
    ui->pushButtonRight->raise();
}

// 为轮播图添加图片
void BannaControl::addAnimationPixmap(QList<QString> &listPixmap)
{
    if(listPixmap.size() != bannaDataList.size()) return;

    for(int i = 0; i < bannaDataList.size(); i++)
    {
        QString styleSheet = BannaSpace::STYLE_SHEET.arg(listPixmap.at(i));
        bannaDataList.at(i).currentImageLabel->setStyleSheet(styleSheet);
    }
}

// 每3S进行一次动画操作
void BannaControl::Slot_changeImageTimer()
{
    if(animationGroup.state() != QParallelAnimationGroup::Running)
    {
        this->setNextAnimation();
    }
}

// 向左移动
void BannaControl::Slot_pushButtonLeft()
{
    if(animationGroup.state() != QParallelAnimationGroup::Running)
    {
        this->setPreAnimation();
    }
}

// 向右移动
void BannaControl::Slot_pushButtonRight()
{
    if(animationGroup.state() != QParallelAnimationGroup::Running)
    {
        this->setNextAnimation();
    }
}

// 获取最右边的Label的Index，坐标判断
int BannaControl::getMaxGeometryIndex(const QList<BannaData> &listData)
{
    int maxPosX = 0;
    int maxIndex = 0;
    for(int i = 0; i < listData.size(); i++)
    {
        int geometryX = listData.at(i).currentImageLabel->geometry().x();
        if(maxPosX < geometryX)
        {
            maxPosX = geometryX;
            maxIndex = i;
        }
    }
    return maxIndex;
}

// 图层排序
void BannaControl::sortGeometry(const bool &isNextFlage)
{
    /******************************************
     * 思路：
     * 将五张图片进行排序，根据其移动后的位置
     * 来确定哪个图层在上，哪个图层在下
     * lower函数 将图层沉下去
     * raise函数 将图层浮上来
     * *****************************************/
    QList<BannaData>listData = bannaDataList;
    QLabel *topImageLabel = nullptr;
    int countNumber = 0;
    while(!listData.isEmpty())
    {
        int index = getMaxGeometryIndex(listData);
        if(index < listData.size())
        {
            switch (countNumber)
            {
            case BannaSpace::SORT_FIRST:
            {
                listData.at(index).currentImageLabel->lower();
                break;
            }
            case BannaSpace::SORT_SECOND:
            {
                if(isNextFlage)
                {
                    topImageLabel = listData.at(index).currentImageLabel;
                    listData.at(index).pushButton->setChecked(true);
                }
                listData.at(index).currentImageLabel->raise();
                break;
            }
            case BannaSpace::SORT_THIRD:
            {
                listData.at(index).currentImageLabel->raise();
                break;
            }
            case BannaSpace::SORT_FOURTH:
            {
                if(!isNextFlage)
                {
                    topImageLabel = listData.at(index).currentImageLabel;
                    listData.at(index).pushButton->setChecked(true);
                }
                listData.at(index).currentImageLabel->lower();
                break;
            }
            case BannaSpace::SORT_FIFTH:
            {
                if(!isNextFlage)
                {
                    listData.at(index).currentImageLabel->raise();
                }
                else
                {
                    listData.at(index).currentImageLabel->lower();
                }
                break;
            }
            }
            listData.removeAt(index);
        }
        countNumber++;
    }

    if(topImageLabel)
    {
        topImageLabel->raise();
    }
    ui->pushButtonLeft->raise();
    ui->pushButtonRight->raise();
}

// 设置向右移动动画
void BannaControl::setNextAnimation()
{
    for(int i = 0; i < bannaDataList.size(); i++)
    {
        bannaDataList.at(i).proAnimation->setStartValue(bannaDataList.at(i).currentImageLabel->geometry());
        bannaDataList.at(i).proAnimation->setEndValue(bannaDataList.at(i).preImageLabel->geometry());
    }
    animationGroup.start();
    this->sortGeometry(true);
}

// 设置向左移动动画
void BannaControl::setPreAnimation()
{
    for(int i = 0; i < bannaDataList.size(); i++)
    {
        bannaDataList.at(i).proAnimation->setStartValue(bannaDataList.at(i).currentImageLabel->geometry());
        bannaDataList.at(i).proAnimation->setEndValue(bannaDataList.at(i).nextImageLabel->geometry());
    }
    animationGroup.start();
    this->sortGeometry(false);
}

//获取中心Label
int BannaControl::getCenterGeometryIndex()
{
    int CenterPosX = 0;
    int CenterIndex = 0;
    for(int i = 0; i < bannaDataList.size(); i++)
    {
        int geometryX = bannaDataList.at(i).currentImageLabel->geometry().width();
        if(CenterPosX < geometryX)
        {
            CenterPosX = geometryX;
            CenterIndex = i;
        }
    }
    return CenterIndex;
}

bool BannaControl::eventFilter(QObject *watched, QEvent *event)
{
    if(!bannaDataList.isEmpty())
    {
        int index = getCenterGeometryIndex();
        QLabel *CenterLabel = bannaDataList[index].currentImageLabel;
        QString Language = bannaDataList[index].LanguageType;
        if(watched == CenterLabel)
        {
            switch (event->type()) {
            case QEvent::Enter:
            {
                changeImageTimer->stop();
                break;
            }
            case QEvent::Leave:
            {
                changeImageTimer->start();
                break;
            }
            case QEvent::MouseButtonDblClick:
            {
                CoordApp->switchApplicationLanguage(Language);
                emit Signal_LanguageChange(FLICKTYPE::SUCCESS);
                break;
            }
            default:
                break;
            }
        }
    }
    return QObject::eventFilter(watched, event);
}

