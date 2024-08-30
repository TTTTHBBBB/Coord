#ifndef COOD_H
#define COOD_H

#include <QMainWindow>
#include "systemtray.h"

#include "FlickWindow/flickwindow.h"
#include "CoordData/coordtreenode.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Cood;
}
QT_END_NAMESPACE

class Cood : public QMainWindow
{
    Q_OBJECT

public:
    explicit Cood(QWidget *parent = nullptr);
    ~Cood();

private:
    Ui::Cood *ui;
    void initvalue();

    virtual void paintEvent(QPaintEvent *event);
    virtual void resizeEvent(QResizeEvent *event);
    virtual bool event(QEvent *event);
    virtual void retranslateUi();

public slots:
    void slot_flickwindow(const QString str, const FLICKTYPE type);
    void slot_Filecreate(const CoordTreeNode &node);
    void slot_FileExpor(const QString &path);
    void Slot_broken();//绘制折线图
    void Slot_curved();//绘制曲线图
    void Slot_column();//绘制柱状图

private:
    SystemTray *systemtray = nullptr;
    FlickWindow *flickwindow = nullptr;
    const CoordTreeNode *Customnode = nullptr;

};
#endif // COOD_H
