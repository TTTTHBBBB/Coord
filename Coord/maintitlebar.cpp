/*
 * 主标题栏，内含有窗体最大化，最小化，关闭
 * 以及窗口的Title，以及名称
*/

#include "maintitlebar.h"
#include "ui_maintitlebar.h"

MainTitleBar::MainTitleBar(QWidget *parent)
    : TitleBar(parent)
    , ui(new Ui::MainTitleBar)
{
    ui->setupUi(this);
    this->InitTitle();
}

void MainTitleBar::InitTitle()
{
    this->setAttribute(Qt::WA_StyledBackground);

    ui->pushButtonLanguage->hide();
    ui->pushButtonMin->hide();
    ui->pushButtonNormalMax->hide();

    connect(ui->pushButtonClose, &QPushButton::clicked, this, &MainTitleBar::Slot_pushButtonClose);
}

void MainTitleBar::setCoordTitle()
{
    MaskWidget = new MaskForm(this);
    LanguageWindow = new LanguageSwitch(nullptr);
    LanguageWindow->hide();

    ui->pushButtonLanguage->show();
    ui->pushButtonMin->show();
    ui->pushButtonNormalMax->show();

    ui->pushButtonNormalMax->setStyleSheet("QPushButton{border-image: url(:/images/png/normal_normal.png);}"
                                           "QPushButton:hover{border-image: url(:/images/png/normal_hover.png);}");
    connect(ui->pushButtonNormalMax, &QPushButton::clicked, this, &MainTitleBar::Slot_pushButtonNormalMax);
    connect(ui->pushButtonMin, &QPushButton::clicked, this, &MainTitleBar::Slot_pushButtonMin);
    connect(ui->pushButtonLanguage, &QPushButton::clicked, this, &MainTitleBar::Slot_Language);

}

MainTitleBar::~MainTitleBar()
{
    delete ui;
}

void MainTitleBar::Slot_pushButtonClose()
{
    if(parentWidget != nullptr)
    {
        parentWidget->close();
    }
}

void MainTitleBar::Slot_pushButtonMin()
{
    if(parentWidget != nullptr)
    {
        parentWidget->showMinimized();
    }
}

void MainTitleBar::Slot_pushButtonNormalMax()
{
    if(parentWidget == nullptr) return;

    if (parentWidget->isMaximized())
    {
        parentWidget->showNormal();
        ui->pushButtonNormalMax->setStyleSheet("QPushButton{border-image: url(:/images/png/normal_normal.png);}"
                                               "QPushButton:hover{border-image: url(:/images/png/normal_hover.png);}");
    }
    else
    {
        parentWidget->showMaximized();
        ui->pushButtonNormalMax->setStyleSheet("QPushButton{border-image: url(:/images/png/max_normal.png);}"
                                               "QPushButton:hover{border-image: url(:/images/png/max_hover.png);}");
    }
}

void MainTitleBar::Slot_Language()
{
    if(MaskWidget == nullptr || LanguageWindow == nullptr) return ;

    MaskWidget->setTopWidget(this->parentWidget);
    MaskWidget->InstallWidget(LanguageWindow);
    LanguageWindow->show();
}
