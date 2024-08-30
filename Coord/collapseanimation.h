/*
 *折叠功能
*/

#ifndef COLLAPSEANIMATION_H
#define COLLAPSEANIMATION_H

#include <QWidget>
#include <QFrame>
#include <QPropertyAnimation>

#include "collapsewidget.h"
#include "globaldef.hpp"
#include "CoordData/coordtreenode.h"

namespace Ui {
class CollapseAnimation;
}

class CollapseAnimation : public QFrame
{
    Q_OBJECT

public:
    explicit CollapseAnimation(QWidget *parent = nullptr);
    ~CollapseAnimation();
    void InitAnimation();

public slots:
    void toggleFold(COLLSPSESTAUS type);
    void slot_FlickWindow(const QString str, const FLICKTYPE type);
    void slot_Filecreate(const CoordTreeNode &node);
    void slot_FileExpor(const QString &path);
    void Slot_broken();//绘制折线图
    void Slot_curved();//绘制曲线图
    void Slot_column();//绘制柱状图

signals:
    void signal_FlickWindow(const QString str, const FLICKTYPE type);
    void signal_Filecreate(const CoordTreeNode &node);
    void signal_FileExpor(const QString &path);
    void Signal_broken();//绘制折线图
    void Signal_curved();//绘制曲线图
    void Signal_column();//绘制柱状图

private:
    virtual void paintEvent(QPaintEvent *event);

private:
    QPropertyAnimation *FrameWorkAnimation = nullptr;

private:
    Ui::CollapseAnimation *ui;
};

#endif // COLLAPSEANIMATION_H
