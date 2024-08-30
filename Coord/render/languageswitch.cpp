#include "languageswitch.h"
#include "ui_languageswitch.h"

LanguageSwitch::LanguageSwitch(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LanguageSwitch)
{
    ui->setupUi(this);
    this->InitLanguage();
}

void LanguageSwitch::InitLanguage()
{
    flickwindow = new FlickWindow(this);
    flickwindow->hide();

    this->setWindowTitle("Coord");
    connect(ui->widget, &BannaControl::Signal_LanguageChange, this, &LanguageSwitch::Slot_FlickWindow);

    ui->widgetTitle->setParentWidget(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->statusBar()->setSizeGripEnabled(false);//去掉底部三角
}

LanguageSwitch::~LanguageSwitch()
{
    delete ui;
}

void LanguageSwitch::Slot_FlickWindow(FLICKTYPE type)
{
    flickwindow->setFlickText(tr("Switching_success"));
    flickwindow->setFlickType(type);
    flickwindow->show();
}

bool LanguageSwitch::event(QEvent *event)
{
    if(event->type() == QEvent::LanguageChange)
    {
        ui->retranslateUi(this);
    }
    return QWidget::event(event);
}
