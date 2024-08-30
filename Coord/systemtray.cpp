/*
 * 系统托盘
*/

#include "systemtray.h"
#include "globaldef.hpp"
#include <QDebug>
#include <QIcon>
#include <QUrl>
#include <QDesktopServices>

SystemTray::SystemTray(QWidget * parent)
    :QSystemTrayIcon(parent)
{
    this->createAction();//创建菜单托盘
    this->addAction();//菜单添加事件
}

SystemTray::~SystemTray()
{

}

void SystemTray::addAction()
{//添加菜单
    myMenu->addAction(showWidget);
    myMenu->addAction(minWidget);
    myMenu->addAction(aboutSoftWare);
    myMenu->addAction(exitSoftWare);
}

void SystemTray::createAction()
{
    myMenu = new QMenu();
    showWidget = new QAction(this);
    minWidget = new QAction(this);
    aboutSoftWare = new QAction(this);
    exitSoftWare = new QAction(this);

    MatchText();

    this->setIcon(QIcon(CoordSpace::LOGO_PATH));
    this->setToolTip(tr("Coord"));

    connect(exitSoftWare, &QAction::triggered, qApp, &QApplication::quit);
    connect(aboutSoftWare, &QAction::triggered, this, &SystemTray::aboutSlot);

    this->setContextMenu(myMenu);
    this->show();
}

void SystemTray::MatchText()
{
    showWidget->setText(tr("Display_Window"));
    minWidget->setText(tr("Hide_window"));
    aboutSoftWare->setText(tr("About_the_software"));
    exitSoftWare->setText(tr("Exit_Software"));
}

// 获取关于事件
QAction *SystemTray::getAboutSoftWare() const
{
    return aboutSoftWare;
}

// 关于软件
void SystemTray::aboutSlot()
{
    QDesktopServices::openUrl(QUrl("xxx"));
}

// 获取最小化事件
QAction *SystemTray::getMinWidget() const
{
    return minWidget;
}

// 获取显示事件
QAction *SystemTray::getShowWidget() const
{
    return showWidget;
}

