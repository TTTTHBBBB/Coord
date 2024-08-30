#ifndef FUNCTIONBAR_H
/*
 * 工具栏
*/
#define FUNCTIONBAR_H

#include <QWidget>
#include <QFrame>
#include <QStackedWidget>

#include "coordtreenode.h"
#include "ButtonEffect/normalbutton.h"

namespace Ui {
class FunctionBar;
}

enum FRAMETYPE{
    COORDCHART,//图表管理
    COORDOBJECT,//项目管理
    COORDCOLOR
};

class FunctionBar : public QFrame
{
    Q_OBJECT

public:
    explicit FunctionBar(QWidget *parent = nullptr);
    void FunctionInit();
    ~FunctionBar();
    void MatchText();//设置控件文本
    void setbtnstyle(NormalButton * btn);

private:
    virtual bool event(QEvent *event);
    virtual void retranslateUi();
    virtual bool eventFilter(QObject *watched, QEvent *event);
    virtual void paintEvent(QPaintEvent *);

signals:
    void signal_FlickWindow(const QString str, const FLICKTYPE type);
    void signal_Filecreate(const CoordTreeNode &node);
    void signal_FileExpor(const QString &path);
    void Signal_broken();//绘制折线图
    void Signal_curved();//绘制曲线图
    void Signal_column();//绘制柱状图

public slots:
    void slot_FlickWindow(const QString str, const FLICKTYPE type);
    void slot_Filecreate(const CoordTreeNode &node);
    void slot_FileExpor(const QString &path);
    void Slot_broken();//绘制折线图
    void Slot_curved();//绘制曲线图
    void Slot_column();//绘制柱状图

private:
    QList<NormalButton *> btnList;
    FRAMETYPE frametype = FRAMETYPE::COORDCHART;

private:
    Ui::FunctionBar *ui;
};

#endif // FUNCTIONBAR_H
