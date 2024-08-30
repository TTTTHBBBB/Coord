#include <QPainter>
#include <QtMath>
#include <QDebug>

#include "glimmerbutton.h"

GlimmerButton::GlimmerButton(QWidget * parent)
    :CoordBtnBase(parent)
{
    this->CoordBtnInit();
}

void GlimmerButton::CoordBtnInit()
{
    setAttribute(Qt::WA_StyledBackground);
    this->installEventFilter(this);

    EnterAnimation = new QPropertyAnimation(this,"showradius");
    EnterAnimation->setDuration(600);
    EnterAnimation->setEasingCurve(QEasingCurve::InOutBack);

    LeaveAnimation = new QPropertyAnimation(this,"displayradius");
    LeaveAnimation->setDuration(600);
    LeaveAnimation->setEasingCurve(QEasingCurve::InOutBack);
}

void GlimmerButton::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    int borderwidth = 2;
    QRect borderRect = this->rect().adjusted(1,1,-1,-1);
    QPen pen;

    if(borderRect.width()<=0 || borderRect.height()<=0 || !borderRect.isValid()) return ;

    switch (type)
    {
        case MOUSETYPE::LEAVE:
        {
            //绘制背景颜色
            painter.setBrush(QColor(0,0,0));
            painter.setPen(Qt::NoPen);
            painter.drawRect(this->rect());

            //绘制消失动画
            painter.setBrush(QColor(0,170,107));
            QPointF pointf((this->width()-displayradius)/2.0,this->height()-displayradius/2.0);
            painter.drawEllipse(pointf,displayradius,displayradius);

            //绘制边框
            pen.setColor(QColor(0,170,107));
            pen.setStyle(Qt::SolidLine);
            pen.setWidth(borderwidth);
            painter.setPen(pen);
            painter.setBrush(Qt::NoBrush);
            painter.drawRect(borderRect);

            break;
        }
        case MOUSETYPE::ENTER:
        {
            //绘制背景颜色
            painter.setBrush(QColor(0,170,107));
            painter.setPen(Qt::NoPen);
            painter.drawRect(this->rect());

            //绘制出现动画
            painter.setBrush(QColor(0,0,0));
            QPointF pointf((this->width()-showradius)/2.0,this->height()-showradius/2.0);
            painter.drawEllipse(pointf,showradius,showradius);

            //绘制文本
            pen.setColor(QColor(0,170,107));
            pen.setStyle(Qt::SolidLine);
            pen.setWidth(borderwidth);
            painter.setPen(pen);
            painter.setBrush(Qt::NoBrush);

            break;
        }
    default:
        break;
    }

    //文本绘制
   if(matchtext.isEmpty()) return ;
   drawText(borderRect,painter,PressorReless,matchtext);
}

void GlimmerButton::startAnimation(MOUSETYPE type)
{
    qreal match = qMax(this->width(),this->height());
    qreal radius = std::sqrt(match*match*2);

    if(EnterAnimation == nullptr || LeaveAnimation == nullptr) return ;

    switch (type)
    {
        case MOUSETYPE::ENTER:
        {
            EnterAnimation->setStartValue(0);
            EnterAnimation->setEndValue(radius);
            EnterAnimation->start();
            break;
        }
        case MOUSETYPE::LEAVE:
        {
            LeaveAnimation->setStartValue(radius);
            LeaveAnimation->setEndValue(0);
            LeaveAnimation->start();
            break;
        }
        default:
            break;
    }
    update();
}

bool GlimmerButton::eventFilter(QObject *watched, QEvent *event)
{
    switch (event->type() )
    {
        case QEvent::Enter:
        {
            type = MOUSETYPE::ENTER;
            startAnimation(MOUSETYPE::ENTER);
            break;
        }
        case QEvent::Leave:
        {
            type = MOUSETYPE::LEAVE;
            startAnimation(MOUSETYPE::LEAVE);
            break;
        }
        case QEvent::MouseButtonPress:
        {
            PressorReless = FEEDBACK::PRESS;
            update();
            break;
        }
        case QEvent::MouseButtonRelease:
        {
            PressorReless = FEEDBACK::RELESS;
            update();
            break;
        }
    default:
        break;
    }
    return QObject::eventFilter(watched, event);
}
