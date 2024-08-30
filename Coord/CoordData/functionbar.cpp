#include <QPainter>
#include <QStyleOption>

#include "functionbar.h"
#include "ui_functionbar.h"

FunctionBar::FunctionBar(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::FunctionBar)
{
    ui->setupUi(this);
    this->FunctionInit();
}

void FunctionBar::FunctionInit()
{
    this->MatchText();
    this->setStyleSheet("background-color: rgb(58,59,62);border:none;color:rgb(126,133,140)");

    btnList.append(ui->pushButtonChart);
    btnList.append(ui->pushButtonFile);
    btnList.append(ui->pushButtonColor);
    ui->pushButtonChart->setPress();

    ui->pushButtonChart->installEventFilter(this);
    ui->pushButtonColor->installEventFilter(this);
    ui->pushButtonFile->installEventFilter(this);

    connect(ui->filewidget, &FileFrame::signal_FlickWindow, this, &FunctionBar::slot_FlickWindow);
    connect(ui->filewidget, &FileFrame::signal_Filecreate, this, &FunctionBar::slot_Filecreate);
    connect(ui->filewidget, &FileFrame::signal_FileExpor, this, &FunctionBar::slot_FileExpor);
    connect(ui->chartwidget, &ChartFunctionFrame::Signal_broken, this, &FunctionBar::Slot_broken);
    connect(ui->chartwidget, &ChartFunctionFrame::Signal_column, this, &FunctionBar::Slot_column);
    connect(ui->chartwidget, &ChartFunctionFrame::Signal_curved, this, &FunctionBar::Slot_curved);
}

void FunctionBar::slot_FileExpor(const QString &path)
{
    emit signal_FileExpor(path);
}

void FunctionBar::Slot_broken()
{
    emit Signal_broken();
}

void FunctionBar::Slot_column()
{
    emit Signal_column();
}

void FunctionBar::Slot_curved()
{
    emit Signal_curved();
}

void FunctionBar::slot_Filecreate(const CoordTreeNode &node)
{
    emit signal_Filecreate(node);
}

void FunctionBar::slot_FlickWindow(const QString str, const FLICKTYPE type)
{
    emit signal_FlickWindow(str, type);
}

void FunctionBar::setbtnstyle(NormalButton * chosebtn)
{
    if(btnList.isEmpty()) return ;
    for(auto btn : btnList)
    {
        if(btn == chosebtn)
        {
            //chosebtn->setPress();
        }
        else{
            btn->setNormal();
        }
    }
}

bool FunctionBar::eventFilter(QObject *watched, QEvent *event)
{
    switch (event->type())
    {
        case QEvent::MouseButtonRelease:
        {
            if(watched == ui->pushButtonChart)
            {
                frametype = FRAMETYPE::COORDCHART;
                setbtnstyle(ui->pushButtonChart);
                ui->stackedWidget->setCurrentIndex(frametype);
                update();
            }
            else if(watched == ui->pushButtonColor)
            {
                frametype = FRAMETYPE::COORDCOLOR;
                setbtnstyle(ui->pushButtonColor);
                update();
            }
            else if(watched == ui->pushButtonFile)
            {
                frametype = FRAMETYPE::COORDOBJECT;
                setbtnstyle(ui->pushButtonFile);
                ui->stackedWidget->setCurrentIndex(frametype);
                update();
            }
            break;
        }
        default:
            break;
    }
    return QObject::eventFilter(watched, event);
}

FunctionBar::~FunctionBar()
{
    delete ui;
}

void FunctionBar::MatchText()
{
    ui->pushButtonChart->MatchText(tr("chart"));
    ui->pushButtonFile->MatchText(tr("file"));
    ui->pushButtonColor->MatchText(tr("coloredit"));
    ui->filewidget->MatcText();
    ui->chartwidget->MatcText();
}

bool FunctionBar::event(QEvent *event)
{
    if(event->type() == QEvent::LanguageChange)
    {
        this->retranslateUi();
    }
    return QWidget::event(event);
}

void FunctionBar::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter painter(this);
    style()->drawPrimitive(QStyle::PE_Frame,&opt,&painter,this);
}

void FunctionBar::retranslateUi()
{
    this->MatchText();
}
