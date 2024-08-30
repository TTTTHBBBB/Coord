/*
 * 主窗口
 * 创建托盘系统
 * 绑定点击显示响应的页面之间的信号与槽
*/
#include <QDebug>
#include <Qpen>
#include <QRect>
#include <QIcon>
#include <QPainter>
#include <qmath.h>
#include <QGraphicsDropShadowEffect>

#include "cood.h"
#include "maintitlebar.h"
#include "ui_cood.h"
#include "Chart/qcustomplot.h"
#include "Chart/coordchartgenerate.h"

Cood::Cood(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Cood)
{
    ui->setupUi(this);
    this->initvalue();
}

Cood::~Cood()
{
    delete ui;
}

void Cood::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
}

void Cood::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
    if(flickwindow != nullptr)
    {
        flickwindow->setFlickWidth(this->width());
    }
    update();
}

void Cood::initvalue()
{
    //设置图标
    QIcon icon(":/images/title/title-white.png");
    this->setWindowIcon(icon);

    //创建托盘系统
    systemtray = new SystemTray(this);
    connect(systemtray->getShowWidget(), &QAction::toggled, this, &Cood::showNormal);
    connect(systemtray->getMinWidget(), &QAction::toggled, this, &Cood::showMinimized);

    //设置控件无边框
    ui->CollapseFrame->setFrameStyle(QFrame::NoFrame);
    //ui->ChartFrame->setFrameStyle(QFrame::NoFrame);

    //设置窗口样式
    ui->widgetTitle->setCoordTitle();
    ui->widgetTitle->setParentWidget(this);
    this->setWindowFlags(Qt::FramelessWindowHint);//设置窗口无边框
    this->setAttribute(Qt::WA_TranslucentBackground);//设置窗口半透明
    this->statusBar()->setSizeGripEnabled(false);//去掉底部三角

    //阴影
    QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect(this);
    effect->setOffset(0, 0);          //设置向哪个方向产生阴影效果(dx,dy)，(0,0)代表向四周发散
    effect->setColor(Qt::black);
    effect->setBlurRadius(20);        //设定阴影的模糊半径，数值越大越模糊
    ui->shadeframe->setGraphicsEffect(effect);

    //弹窗设置
    flickwindow = new FlickWindow(this);
    flickwindow->hide();
    connect(ui->CollapseFrame, &CollapseAnimation::signal_FlickWindow, this ,&Cood::slot_flickwindow);

    //Tabwidget
    ui->Tabwidget->setWindowFlags(Qt::FramelessWindowHint);
    ui->Tabwidget->setFixedIndex(0);
    connect(ui->CollapseFrame, &CollapseAnimation::signal_Filecreate, this, &Cood::slot_Filecreate);
    connect(ui->CollapseFrame, &CollapseAnimation::signal_FileExpor, this, &Cood::slot_FileExpor);

    //Chart
    connect(ui->CollapseFrame, &CollapseAnimation::Signal_broken, this, &Cood::Slot_broken);
    connect(ui->CollapseFrame, &CollapseAnimation::Signal_column, this, &Cood::Slot_column);
    connect(ui->CollapseFrame, &CollapseAnimation::Signal_curved, this, &Cood::Slot_curved);
}

void Cood::Slot_broken()
{
    if(Customnode == nullptr)
    {
        slot_flickwindow(tr("No_file_path_selected"), FLICKTYPE::FAILD);
        return ;
    }
    ui->Tabwidget->addTabBar(*Customnode);
    QCustomPlot *customplot = ui->Tabwidget->getCustomPlot(Customnode->filePath);
    CoordChartGenerate::DrawmarkBrokenLine(Customnode->filePath,customplot);
}

void Cood::Slot_column()
{
    if(Customnode == nullptr)
    {
        slot_flickwindow(tr("No_file_path_selected"), FLICKTYPE::FAILD);
        return ;
    }
    ui->Tabwidget->addTabBar(*Customnode);
    QCustomPlot *customplot = ui->Tabwidget->getCustomPlot(Customnode->filePath);
    CoordChartGenerate::DrawmarkBarLine(Customnode->filePath,customplot);
}

void Cood::Slot_curved()
{//曲线
    if(Customnode == nullptr)
    {
        slot_flickwindow(tr("No_file_path_selected"), FLICKTYPE::FAILD);
        return ;
    }
    ui->Tabwidget->addTabBar(*Customnode);
    QCustomPlot *customplot = ui->Tabwidget->getCustomPlot(Customnode->filePath);
    CoordChartGenerate::DrawmarkScatterLine(Customnode->filePath,customplot);
}

void Cood::slot_FileExpor(const QString &path)
{
    if(path.isEmpty())
    {
        slot_flickwindow(tr("File is Empty!"), FLICKTYPE::WARNING);
        return ;
    }
    bool signal = CoordChartGenerate::ExporExcl(path);
    if(signal == false)
    {
        slot_flickwindow(tr("Expor failed!"), FLICKTYPE::FAILD);
        return ;
    }else{
        slot_flickwindow(tr("Expor Success!"), FLICKTYPE::SUCCESS);
        return ;
    }

}

void Cood::slot_Filecreate(const CoordTreeNode &node)
{
    Customnode = &node;
    ui->Tabwidget->addTabBar(node);
}

void Cood::slot_flickwindow(const QString str, const FLICKTYPE type)
{
    flickwindow->setFlickText(str);
    flickwindow->setFlickType(type);
    flickwindow->show();
}

bool Cood::event(QEvent *event)
{
    if(event->type() == QEvent::LanguageChange)
    {
        this->retranslateUi();
    }
    return QWidget::event(event);
}

void Cood::retranslateUi()
{
    if(systemtray!=nullptr)
    {
        systemtray->MatchText();
    }
}

