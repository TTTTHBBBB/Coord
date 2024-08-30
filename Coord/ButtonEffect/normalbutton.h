/*
 *普通按钮，没有特殊动画效果
*/
#ifndef NORMALBUTTON_H
#define NORMALBUTTON_H

#include <QObject>
#include <QWidget>

#include "ButtonEffect/coordbtnbase.h"


class NormalButton : public CoordBtnBase
{
    Q_OBJECT
public:
    explicit NormalButton(QWidget * obj = nullptr);
    void CoordBtnInit();
    virtual void MatchText(const QString str){ matchtext=str; this->update(); };
    void setNormal(){PressorReless = FEEDBACK::NORMAL;update();};
    void setPress(){PressorReless = FEEDBACK::PRESS;update();};
    void setfeedback(const FEEDBACK type){ PressorReless = type; update();};
    void setHoverColor(const QColor color) {hovercolor = color;};
    void setBackgroundColor(const QColor color) {backgroundcolor = color;};
    void sethoverfontColor(const QColor color) {hoverfontColor = color;};
    void setfontclor(const QColor color) {fontclor = color;};
    void settopborder(const QColor color) {topbordercolor = color;};

private:
    virtual void paintEvent(QPaintEvent *event);
    virtual bool eventFilter(QObject *watched, QEvent *event);

private:
    FEEDBACK PressorReless = FEEDBACK::NORMAL;
    QString matchtext = "";
    QColor hovercolor = QColor(58,59,62);//选中颜色
    QColor backgroundcolor = QColor(81,82,84);//正常背景颜色
    QColor hoverfontColor = QColor(7,169,98);//字体悬浮颜色
    QColor fontclor = QColor(Qt::white);//正常颜色字体
    QColor topbordercolor = QColor(7,169,98);//上边框颜色
    MOUSETYPE EnterorLeave = MOUSETYPE::LEAVE;
};

#endif // NORMALBUTTON_H
