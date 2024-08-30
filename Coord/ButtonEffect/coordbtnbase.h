/*
 * 按钮基类
*/

#ifndef COORDBTNBASE_H
#define COORDBTNBASE_H

#include <QObject>
#include <QWidget>
#include <QPushButton>

#include "globaldef.hpp"

class CoordBtnBase : public QPushButton
{
    Q_OBJECT
public:
    explicit CoordBtnBase(QWidget *parent = nullptr);
    void CoordBtnInit();

    virtual void MatchText(const QString str) =0;
    void setadjust(const int x) { adjust = x ;};

    void drawText(QRect rect, QPainter &painter,FEEDBACK type = FEEDBACK::RELESS,QString str ="");
    int getFontsize(QRect rect,QString btnText);

private:
    int adjust = 1;
};

#endif // COORDBTNBASE_H
