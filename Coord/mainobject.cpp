/*
 * 初始化类
*/
#include "globaldef.hpp"
#include "mainobject.h"
#include "cood.h"
#include "splashscreen.h"

#include <QSettings>
#include <QDebug>
#include <QTranslator>

MainObject::MainObject(QObject *parent) :
    QObject(parent)
{
}

MainObject::~MainObject()
{
    delete m_coordwindow;
}

void MainObject::Setting()
{
    QDir dir(CoordSpace::DEPLOYSPATH);
    if(!dir.exists())
    {
        dir.mkpath(CoordSpace::DEPLOYSPATH);
    }
    QFile file(CoordSpace::SETTINGPATH);
    if(!file.exists())
    {
        QSettings setting(CoordSpace::SETTINGPATH,QSettings::IniFormat);
        setting.setValue(CoordSpace::LANGUAGE,CoordSpace::Chinese);
    }
}

void MainObject::creatLanguage()
{//多语言初始化
    QString path = CoordSpace::getLanguage();
    QTranslator *translator = new QTranslator(this);
    if(translator->load(path))
    {
        qApp->installTranslator(translator);
    }
    QApplication::instance()->processEvents();
}


void MainObject::setInit()
{//创建闪屏
    SplashScreen::getInstance()->setStagePercent(0,tr("Initialize_the_application"));
    m_coordwindow = new Cood(nullptr);
    m_coordwindow->setWindowTitle(tr("Coord"));
    SplashScreen::getInstance()->setStart(m_coordwindow, tr("Coord"), QString(":/images/title/title-black.png"));
    SplashScreen::getInstance()->setStagePercent(40, tr("Initialize_the_main_interface"));
    SplashScreen::getInstance()->setStagePercent(80, tr("Loading_interface"));
    SplashScreen::getInstance()->setStagePercent(100, tr("Loading_complete"));
    SplashScreen::getInstance()->setFinish();

    m_coordwindow->showNormal();
}
