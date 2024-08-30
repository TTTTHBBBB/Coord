#include <QPainter>
#include <QEvent>

#include "coordbtnbase.h"

CoordBtnBase::CoordBtnBase(QWidget * parent)
    :QPushButton(parent)
{

}

int CoordBtnBase::getFontsize(QRect rect,QString btnText)
{
    int fontSize = 30;
    QFont font("微软雅黑", fontSize);

    QFontMetrics metrics(font);
    QSize textSize = metrics.size(Qt::TextSingleLine, btnText);

    while (textSize.width() >= rect.width() -10 || textSize.height() >= rect.height()-10)
    {
        fontSize--;
        if (fontSize <= 1) break;
        font.setPointSize(fontSize);
        metrics = QFontMetrics(font);
        textSize = metrics.size(Qt::TextSingleLine, btnText);
    }
    return fontSize;
}

void CoordBtnBase::drawText(QRect rect, QPainter &painter,FEEDBACK type,QString str)
{
    if(str.isEmpty()) return ;

    int fontsize = this->getFontsize(rect,str);
    if(type == FEEDBACK::PRESS){//需要修正
        fontsize = qMax(1,fontsize- adjust);
    }
    painter.setFont(QFont("微软雅黑",fontsize));
    painter.drawText(rect,Qt::AlignCenter,str);
}



