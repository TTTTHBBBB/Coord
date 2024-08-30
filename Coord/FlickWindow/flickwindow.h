/*
 *弹窗功能
*/

#ifndef FLICKWINDOW_H
#define FLICKWINDOW_H

#include <QWidget>
#include <QTimer>
#include <QPropertyAnimation>
#include <QFrame>

#include "globaldef.hpp"

namespace Ui {
class FlickWindow;
}

class FlickWindow : public QFrame
{
    Q_OBJECT

public:
    explicit FlickWindow(QWidget *parent = nullptr,FLICKTYPE type = FLICKTYPE::FAILD);
    ~FlickWindow();
    void setFlickType(FLICKTYPE type);
    void setFlickText(QString str);
    void setFlickWidth(int width);
    int getFontsize(QRectF rect);
    void Init();

private:
    virtual void paintEvent(QPaintEvent *event);
    virtual void resizeEvent(QResizeEvent *event);
    virtual bool eventFilter(QObject *watched, QEvent *event);
    virtual void showEvent(QShowEvent *event);
    virtual void hideEvent(QHideEvent *event);

private slots:
    void Slot_timeout();

private:
    FLICKTYPE filcktype;
    QString flicktext = "THB ^0^";
    QTimer *continueTime = nullptr;
    QPropertyAnimation * ShowAnimation = nullptr;
    QPropertyAnimation * HideAnimation = nullptr;

private:
    Ui::FlickWindow *ui;
};

#endif // FLICKWINDOW_H
