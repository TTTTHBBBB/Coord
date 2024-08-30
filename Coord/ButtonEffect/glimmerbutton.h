/*
 * 微光按钮
*/
#ifndef GLIMMERBUTTON_H
#define GLIMMERBUTTON_H

#include <QObject>
#include <QEvent>
#include <QWidget>
#include <QPushButton>
#include <QPropertyAnimation>

#include "globaldef.hpp"
#include "ButtonEffect/coordbtnbase.h"

class GlimmerButton : public CoordBtnBase
{
    Q_OBJECT
    Q_PROPERTY(int showradius READ getshowradius WRITE setshowradius)
    Q_PROPERTY(int displayradius READ getdisplayradius WRITE setdisplayradius)

public:
    explicit GlimmerButton(QWidget * obj = nullptr);
    virtual void MatchText(const QString str){ matchtext=str; this->update(); };
    void CoordBtnInit();

private:
    int getshowradius()const {return showradius;}
    void setshowradius(qreal x){showradius = x; update();}

    int getdisplayradius()const {return displayradius;}
    void setdisplayradius(qreal x){displayradius = x; update();}

    virtual void paintEvent(QPaintEvent *event);
    virtual bool eventFilter(QObject *watched, QEvent *event);

    void startAnimation(MOUSETYPE type = MOUSETYPE::LEAVE);

private:
    QString matchtext = "";
    QPropertyAnimation *EnterAnimation = nullptr;
    QPropertyAnimation *LeaveAnimation = nullptr;
    MOUSETYPE type = MOUSETYPE::LEAVE;
    qreal showradius;
    qreal displayradius;
    FEEDBACK PressorReless = FEEDBACK::RELESS;
};

#endif // GLIMMERBUTTON_H
