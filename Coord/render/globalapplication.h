/*
 * 自定义QApplication
 * 协助完成动态多语言切换
*/

#ifndef GLOBALAPPLICATION_H
#define GLOBALAPPLICATION_H

#include <QObject>
#include <QTimer>
#include <QApplication>
#include <QTranslator>

#include "globaldef.hpp"
class GlobalApplication : public QApplication
{
    Q_OBJECT
public:
    GlobalApplication(int &argc, char **argv);
    //构造函数的参数与main()函数保持一致，**必须使用引用传值**
    ~GlobalApplication();
    void switchApplicationLanguage(QString Type);
    virtual bool notify(QObject* obj, QEvent* event);

private:
    QTranslator * m_pTranslator = nullptr;
};

#endif // GLOBALAPPLICATION_H
