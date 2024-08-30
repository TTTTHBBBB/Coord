#include "cood.h"
#include "globaldef.hpp"
#include "mainobject.h"
#include "render/globalapplication.h"

#include <QTranslator>
#include <QApplication>

int main(int argc, char *argv[])
{
    GlobalApplication a(argc, argv);
    //QApplication a(argc, argv);

    MainObject *mainObject = new MainObject();

    mainObject->Setting();
    mainObject->creatLanguage();
    mainObject->setInit();

    LOADQSS(CoordSpace::STYLE_QSS_FILE_PATH);

    return a.exec();
}
