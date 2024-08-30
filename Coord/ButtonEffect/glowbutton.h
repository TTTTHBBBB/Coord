/*
 * 流光按钮
*/
#ifndef GLOWBUTTON_H
#define GLOWBUTTON_H

#include <QObject>
#include <QEvent>
#include <QWidget>
#include <QPushButton>
#include <QTimer>
#include <QPropertyAnimation>

#include "ButtonEffect/coordbtnbase.h"

class GlowButton : public CoordBtnBase
{
    Q_OBJECT
public:
    explicit GlowButton(QWidget *parent = nullptr);
    virtual void MatchText(const QString str){ matchtext=str; this->update(); };
    void CoordBtnInit();
    void setIiterals(QPainter &painter);
    QRect borderRect() const ;
    void setParams(int border_radius, int border_width, const QColor &font_color);
    void drawForeground(QPainter &painter);
    QPixmap getForegroundPixmap() const;
    void animForwardRun();

private slots:
    void updateAnimation();

private:
    virtual void paintEvent(QPaintEvent *event);
    virtual void showEvent(QShowEvent *event);
    virtual bool eventFilter(QObject *watched, QEvent *event);
    virtual void resizeEvent(QResizeEvent *event);

private:
    QString matchtext = "";
    int borderWidth;
    int borderRadius;
    QColor fontColor;
    QPixmap pixmap;
    int offset;
    int animMsecs;
    QTimer animTimer;
    FEEDBACK PressorReless = FEEDBACK::RELESS;
};

#endif // GLOWBUTTON_H
