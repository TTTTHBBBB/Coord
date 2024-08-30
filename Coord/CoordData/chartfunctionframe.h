/*
 * 图表功能
*/
#ifndef CHARTFUNCTIONFRAME_H
#define CHARTFUNCTIONFRAME_H

#include <QWidget>
#include <QFrame>

#include <QPushButton>

namespace Ui {
class ChartFunctionFrame;
}

class ChartFunctionFrame : public QWidget
{
    Q_OBJECT

public:
    explicit ChartFunctionFrame(QWidget *parent = nullptr);
    ~ChartFunctionFrame(){};
    void framInit();
    void MatcText();//重刷文本

signals:
    void Signal_broken();//绘制折线图
    void Signal_curved();//绘制曲线图
    void Signal_column();//绘制柱状图

public slots:
    void Slot_broken();//绘制折线图
    void Slot_curved();//绘制曲线图
    void Slot_column();//绘制柱状图

private:
    //virtual bool eventFilter(QObject *watched, QEvent *event);
    //virtual void resizeEvent(QResizeEvent *event);

private:
    Ui::ChartFunctionFrame *ui;
};

#endif // CHARTFUNCTIONFRAME_H
