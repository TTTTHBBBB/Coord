/*
 *伸缩按钮动画
*/

#ifndef COLLAPSEWIDGET_H
#define COLLAPSEWIDGET_H

#include <QWidget>
#include <QFrame>
#include <QPropertyAnimation>
#include <QMouseEvent>
#include <QPen>
#include <QDebug>
#include <QPainter>
#include <QPainterPath>

namespace Ui {
class CollapseWidget;
}

enum STATUS{
   LINESHOW,
   LINEDISPLAY,
   RADIUSSHOW,
   RADIUSDISPLAY,
   INITIALIZATION
};

enum COLLSPSESTAUS{
    EXPAND,
    SYSTOLIC,
};

class CollapseWidget : public QFrame
{
    Q_OBJECT
    //Line
    Q_PROPERTY(qreal showLine READ getshowLine WRITE setshowLine)
    Q_PROPERTY(qreal cancelLine READ getcancelLine WRITE setcancelLine)

    //background
    Q_PROPERTY(qreal radius READ getRadius WRITE setRadius)
    Q_PROPERTY(qreal cancleRadius READ getcancleRadius WRITE setcancleRadius)

public:
    explicit CollapseWidget(QWidget *parent = nullptr);
    ~CollapseWidget();
    void initAnimation();

private:
    virtual void paintEvent(QPaintEvent *event);
    virtual void resizeEvent(QResizeEvent *event);
    virtual void mousePressEvent(QMouseEvent *);
    virtual void mouseReleaseEvent(QMouseEvent *);

    qreal getRadius()const {return radius;}
    void setRadius(qreal x){radius = x; update();}
    qreal getcancleRadius()const {return cancleRadius;}
    void setcancleRadius(qreal x){cancleRadius = x; update();};

    qreal getshowLine()const{return showLine;}
    void setshowLine(qreal line){showLine = line;update();};
    qreal getcancelLine()const{return cancelLine;}
    void setcancelLine(qreal line){cancelLine = line;update();};

    void startAnimation();
    void displayAnimation();

private slots:
    void drawShowAnimation();//绘制显示的动画
    void drawDisplayAnimation();//绘制取消时的动画

signals:
    void signal_btnClicked(COLLSPSESTAUS type);

private:
    STATUS ANIMATIONTYPE;
    QRectF btnrect;
    QPointF pointTop,pointBottom;
    QPoint m_pressPos;
    COLLSPSESTAUS TYPE;

    qreal showLine,cancelLine,initLine;
    QPropertyAnimation *m_showLineAnimation = nullptr;
    QPropertyAnimation *m_cancelLineAnimation = nullptr;

    qreal radius,cancleRadius;
    QPropertyAnimation *m_radiusAnimation = nullptr;
    QPropertyAnimation *m_cancleRadiusAnimation = nullptr;

private:
    Ui::CollapseWidget *ui;
};

#endif // COLLAPSEWIDGET_H
