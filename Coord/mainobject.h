/*
 * 初始化类
*/

#ifndef MAINOBJECT_H
#define MAINOBJECT_H

#include <QObject>

class Cood;


class MainObject : public QObject
{
    Q_OBJECT
public:
    explicit MainObject(QObject *parent = 0);
    ~MainObject();

public :
    void setInit();//初始化
    void creatLanguage();
    void Setting();

private:
    Cood *m_coordwindow;

};

#endif // MAINOBJECT_H
