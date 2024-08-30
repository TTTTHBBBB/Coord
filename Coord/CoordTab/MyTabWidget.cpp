#include <QApplication>
#include <QMouseEvent>
#include <QPixmap>
#include <QMimeData>
#include <QPainter>
#include <QCursor>
#include <QDrag>
#include <QDebug>

#include "MyTabWidget.h"

MyTabWidget::MyTabWidget(QWidget *parent)
    : QTabWidget(parent)
{
    this->initTabBar();
}

void MyTabWidget::addTabBar(const CoordTreeNode &node)
{
    QString path = node.filePath;
    QCustomPlot *customPlot = nullptr;
    int index = 0;
    if(IndexMap[path].isEmpty())
    {
        customPlot = new QCustomPlot(this);
        index = addTab(customPlot,node.filename);
        IndexMap[path] = QString::number(index);
        ChartMap[path] = customPlot;
    }
    else {
        customPlot = ChartMap[path];
        index = this->addTab(customPlot,node.filename);
        IndexMap[path] = QString::number(index);
    }
    this->setCurrentIndex(index);
    int count = this->count() > 2 ? this->count() : 3 ;
    setStyleSheet(QString("QTabBar::tab{height:30;width:%1}").arg(this->width()/count));
}

void MyTabWidget::showEvent(QShowEvent *event)
{
    QTabWidget::showEvent(event);
    //初始化时把已有的设置为close释放
    for(int index=0;index<this->count();index++)
    {
        QWidget *page=this->widget(index);
        if(page)
            page->setAttribute(Qt::WA_DeleteOnClose);
    }
}

void MyTabWidget::initTabBar()
{
    this->setAttribute(Qt::WA_StyledBackground);
    this->installEventFilter(this);
    //this->setTabShape(QTabWidget::Triangular);
    this->setTabPosition(QTabWidget::North);
    this->setMovable(true);
    this->setTabsClosable(true);
    connect(this,&QTabWidget::tabCloseRequested,this,&MyTabWidget::Slot_TabClose);
}

void MyTabWidget::Slot_TabClose(int index)
{
    if(indexValid(index))
    {
        QWidget *page=this->widget(index);
        if(!page||fixedPage.contains(page))
            return;
        removeTab(index);
        page->close();
    }
}

void MyTabWidget::setFixedIndex(int index)
{
    if(indexValid(index))
    {
        QWidget *page=this->widget(index);
        if(page&&!fixedPage.contains(page))
        {
            fixedPage.push_back(page);
            //不显示关闭按钮，替换为nullptr
            tabBar()->setTabButton(index, QTabBar::RightSide, nullptr);
        }
    }
}

bool MyTabWidget::indexValid(int index) const
{
    if(index<0||index>=this->count())
        return false;
    return true;
}

void MyTabWidget::resizeEvent(QResizeEvent *event)
{
    QTabWidget::resizeEvent(event);
    int count = this->count() > 2 ? this->count() : 3 ;
    setStyleSheet(QString("QTabBar::tab{height:30;width:%1}").arg(this->width()/count));
}

bool MyTabWidget::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::Resize)
    {
        int count = this->count() > 2 ? this->count() : 3 ;
        setStyleSheet(QString("QTabBar::tab{height:30;width:%1}").arg(this->width()/count));
    }
    return QTabWidget::eventFilter(obj, event);
}
