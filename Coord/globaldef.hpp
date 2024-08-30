/*
 * 配置规范
*/

#ifndef GLOBALDEF_HPP
#define GLOBALDEF_HPP
#include <QString>
#include <QDebug>
#include <QFile>
#include <QApplication>
#include <QDir>
#include <QWidget>
#include <QSettings>
#include <QStandardPaths>

#ifndef LOADQSS
//加载指定文件的样式表
#define LOADQSS(qssFile)                        \
{                                               \
    QFile file(qssFile);                        \
    file.open(QFile::ReadOnly);                 \
    if(file.isOpen())                           \
    {                                           \
       qApp->setStyleSheet(file.readAll());    \
       file.close();                           \
    }                                           \
}
#endif

#ifndef SAFEDELETE
//安全的删除一个指针并设置其值为nullpttr防止悬空指针
#define SAFEDELETE(pointer) \
{                           \
    if(pointer)             \
    {                       \
        delete pointer;     \
    }                       \
    pointer = nullptr;          \
}
#endif

enum WidgetTabType
{
    TAB_BANNA,
    TAB_CYLINDER,
    TAB_PROGRESS,
    TAB_FRAME,
    TAB_LIST,
    TAB_CUSTOM_PLOT,
    TAB_MOVE_BUTTON,
    TAB_TABLE_WIDGET,
    TAB_SLIDER,
    TAB_PROCESS,
    TAB_OPENGL,
    TAB_MAX,

};

//弹窗规范
enum FLICKTYPE{
    WARNING,
    SUCCESS,
    FAILD,
};

//鼠标状态
enum MOUSETYPE{
    ENTER,
    LEAVE,
    COORDPRESS,
    COORDRELESS,
    theDragIn,
    theDragOut,//鼠标超出区域
    COORDNORMAL
};

//反馈规范
enum FEEDBACK{
    PRESS,//单击，按压
    RELESS,
    NORMAL,
    DBPRESS//双击
};

//文件类型
enum FILETYPE{
    COORDFILE,
    COORDTEXT,
    COORDROTE//根目录
};

//图表类型
enum CHARTYPE{
    COORDBROKEN = 0,
    COORDCURVED = 1,
    COORDCOLUMN = 2
};

class GlobalApplication;
#define CoordApp static_cast<GlobalApplication*>(QCoreApplication::instance())

namespace CoordSpace
{
    const QString STYLE_QSS_FILE_PATH = ":/images/Style/stylesheet.qss";
    const QString LOGO_PATH = ":/images/title/title-black.png";

    const int INT_DOUBLE_TIMES = 2;
    const float FLOAT_DOUBLE_TIMES = 2.0f;

    //配置规范
    const QString LANGUAGE = "anguageCombo";
    const QString Chinese = "Chinese";
    const QString English = "English";
    const QString Japanese = "Japaese";
    const QString Spanish = "spanish";
    const QString German = "german";

    //配置文件路径
    const QString desktopPath = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    const QString DEPLOYSPATH = desktopPath + QDir::separator() + "Coord";
    const QString SETTINGPATH = DEPLOYSPATH + QDir::separator() + "setting.ini";

    const QString LAGUAGUEN = ":/translate/Language_EN.qm";
    const QString LAGUAGUCN = ":/translate/Language_CN.qm";
    const QString LAGUAGUJA = ":/translate/Language_JA.qm";


    // 根据控件位置获取控件中心点位置
    inline QPoint GetCenterPosition(const QWidget *controlWidget)
    {
        QPoint centerPos;
        if(nullptr != controlWidget)
        {
            centerPos.setX(controlWidget->x() + controlWidget->width() / INT_DOUBLE_TIMES);
            centerPos.setY(controlWidget->y() + controlWidget->height() / INT_DOUBLE_TIMES);
        }
        return centerPos;
    }

    // 获取控件中心点位置
    inline QPointF GetCenterPoint(const QWidget *controlWidget)
    {
        QPointF centerPoint;
        if(nullptr != controlWidget)
        {
            centerPoint.setX(controlWidget->width() / 2.0);
            centerPoint.setY(controlWidget->height() / 2.0);
        }
        return centerPoint;
    }

    // 获取图片中心点位置
    inline QPointF GetCenterPoint(const QImage &image)
    {
        QPointF centerPoint;
        centerPoint.setX(image.width() / 2.0);
        centerPoint.setY(image.height() / 2.0);
        return centerPoint;
    }

    inline QString getLanguage()
    {
        QString Path = "";
        QSettings setting(CoordSpace::SETTINGPATH, QSettings::IniFormat);
        QString language = setting.value(CoordSpace::LANGUAGE).toString();
        if(language == CoordSpace::Chinese)
        {
            Path = CoordSpace::LAGUAGUCN;
        }
        else if(language == CoordSpace::English)
        {
            Path = CoordSpace::LAGUAGUEN;
        }
        else if(language == CoordSpace::Japanese)
        {
            Path = CoordSpace::LAGUAGUJA;
        }
        return Path;
    }

    inline void setLanguage(QString language)
    {
        QSettings setting(CoordSpace::SETTINGPATH, QSettings::IniFormat);
        setting.setValue(CoordSpace::LANGUAGE, language);
    }
}
#endif // GLOBALDEF_HPP
