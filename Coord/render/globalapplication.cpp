#include <QDebug>

#include "globalapplication.h"

GlobalApplication::GlobalApplication(int &argc, char **argv)
    : QApplication(argc, argv)
    ,m_pTranslator(nullptr)
{

}

bool GlobalApplication::notify(QObject* obj, QEvent* event)
{
    return QApplication::notify(obj, event);
}


void GlobalApplication::switchApplicationLanguage(QString Language)
{
    if (Q_NULLPTR != m_pTranslator)
    {
        qApp->removeTranslator(m_pTranslator);
        delete m_pTranslator;
        m_pTranslator = Q_NULLPTR;
    }

    m_pTranslator = new QTranslator;
    CoordSpace::setLanguage(Language);
    QString Path = CoordSpace::getLanguage();

    if(m_pTranslator->load(Path))
    {
        qApp->installTranslator(m_pTranslator);
    }
}


GlobalApplication::~GlobalApplication()
{

}


