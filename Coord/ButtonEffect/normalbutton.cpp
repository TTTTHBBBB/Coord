#include <QEvent>
#include <QPaintEvent>
#include <QPainter>
#include "normalbutton.h"

NormalButton::NormalButton(QWidget * parent)
    :CoordBtnBase(parent)
{
    this->CoordBtnInit();
}

void NormalButton::CoordBtnInit()
{
    this->installEventFilter(this);
}

bool NormalButton::eventFilter(QObject *watched, QEvent *event)
{
    switch (event->type())
    {
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
        case QEvent::Enter:
        {
            EnterorLeave = MOUSETYPE::ENTER;
            update();
            break;
        }
        case QEvent::Leave:
        {
            EnterorLeave = MOUSETYPE::LEAVE;
            update();
            break;
        }
        default:
            break;
    }
    return QObject::eventFilter(watched, event);
}

void NormalButton::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setPen(Qt::NoPen);
    painter.setRenderHint(QPainter::Antialiasing);

    switch (PressorReless)
    {//绘制背景
        case FEEDBACK::RELESS:
        {//选中情况
            painter.setBrush(hovercolor);
            painter.drawRect(this->rect());
            break;
        }
        case FEEDBACK::NORMAL:
        {//正常
            painter.setBrush(backgroundcolor);
            painter.drawRect(this->rect());
            break;
        }
    default:
        break;
    }

    QPen pen;
    pen.setStyle(Qt::SolidLine);

    switch (EnterorLeave)
    {
        case MOUSETYPE::LEAVE:
        {
            pen.setColor(fontclor);
            painter.setPen(pen);
            drawText(this->rect(), painter, PressorReless, matchtext);
            break;
        }
        case MOUSETYPE::ENTER:
        {
            QLine line(this->rect().topLeft(),this->rect().topRight());
            pen.setWidth(3);
            pen.setBrush(topbordercolor);
            painter.setPen(pen);
            painter.drawLine(line);

            pen.setColor(hoverfontColor);
            drawText(this->rect(), painter, PressorReless, matchtext);
            break;
        }
        default:
            break;
    }

}
