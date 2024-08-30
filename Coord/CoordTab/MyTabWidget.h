#ifndef MYTABWIDGET_H
#define MYTABWIDGET_H

#include <QTabWidget>

#include "CoordData/coordtreenode.h"
#include "Chart/qcustomplot.h"
class MyTabWidget : public QTabWidget
{
    Q_OBJECT
public:
    explicit MyTabWidget(QWidget *parent = nullptr);

    void addTabBar(const CoordTreeNode &node);
    QCustomPlot* getCustomPlot(const QString path){return ChartMap[path];};
    bool indexValid(int index) const;
    void setFixedIndex(int index);

protected:
    virtual void showEvent(QShowEvent *event);
    virtual void resizeEvent(QResizeEvent *event);
    virtual bool eventFilter(QObject *watched, QEvent *event);

private:
    void initTabBar();

private slots:
    void Slot_TabClose(int index);

private:
    //保存不能拖出、没有关闭按钮的tab页（如主页）
    QList<QWidget*> fixedPage;
    QMap<QString,QString> IndexMap;
    QMap<QString,QCustomPlot*>ChartMap;
};

#endif // MYTABWIDGET_H
