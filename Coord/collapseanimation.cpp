#include <QPainter>
#include <QDebug>

#include "collapseanimation.h"
#include "ui_collapseanimation.h"

CollapseAnimation::CollapseAnimation(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::CollapseAnimation)
{
    ui->setupUi(this);

    this->setWindowFlag(Qt::FramelessWindowHint);
    this->InitAnimation();
}

void CollapseAnimation::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    setFixedWidth(ui->FrameAnimation->width() + ui->widgetWork->width());
}

void CollapseAnimation::InitAnimation()
{
    ui->widgetWork->setFixedWidth(0);
    ui->widgetWork->setFrameStyle(QFrame::NoFrame);
    ui->FrameAnimation->setFrameStyle(QFrame::NoFrame);

    FrameWorkAnimation = new QPropertyAnimation(ui->widgetWork,"minimumWidth",this);
    FrameWorkAnimation->setDuration(2000);
    FrameWorkAnimation->setEasingCurve(QEasingCurve::OutCurve);

    connect(ui->FrameAnimation, &CollapseWidget::signal_btnClicked, this, &CollapseAnimation::toggleFold);
    connect(FrameWorkAnimation, &QPropertyAnimation::finished, this,[=](){
        ui->widgetWork->MatchText();
    });

    //弹窗设置
    connect(ui->widgetWork, &FunctionBar::signal_FlickWindow,this , &CollapseAnimation::slot_FlickWindow);
    //Tab添加
    connect(ui->widgetWork, &FunctionBar::signal_Filecreate, this, &CollapseAnimation::slot_Filecreate);

    //图表控制
    connect(ui->widgetWork, &FunctionBar::Signal_broken, this, &CollapseAnimation::Slot_broken);
    connect(ui->widgetWork, &FunctionBar::Signal_column, this, &CollapseAnimation::Slot_column);
    connect(ui->widgetWork, &FunctionBar::Signal_curved, this, &CollapseAnimation::Slot_curved);
    connect(ui->widgetWork, &FunctionBar::signal_FileExpor, this, &CollapseAnimation::slot_FileExpor);
}

void CollapseAnimation::slot_FileExpor(const QString &path)
{
    emit signal_FileExpor(path);
}

void CollapseAnimation::Slot_broken()
{
    emit Signal_broken();
}

void CollapseAnimation::Slot_column()
{
    emit Signal_column();
}

void CollapseAnimation::Slot_curved()
{
    emit Signal_curved();
}

void CollapseAnimation::slot_Filecreate(const CoordTreeNode &node)
{
    emit signal_Filecreate(node);
}

void CollapseAnimation::slot_FlickWindow(const QString str, const FLICKTYPE type)
{
    emit signal_FlickWindow(str, type);
}

void CollapseAnimation::toggleFold(COLLSPSESTAUS type)
{
    if(type == COLLSPSESTAUS::EXPAND)
    {
        FrameWorkAnimation->setStartValue(0);
        FrameWorkAnimation->setEndValue(250);
    }
    else if(type == COLLSPSESTAUS::SYSTOLIC)
    {
        FrameWorkAnimation->setStartValue(250);
        FrameWorkAnimation->setEndValue(0);
    }
    FrameWorkAnimation->start();
}

CollapseAnimation::~CollapseAnimation()
{
    delete ui;
}
