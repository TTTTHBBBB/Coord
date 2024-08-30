/*
 *文件树
*/
#ifndef COORDTREEWIDGET_H
#define COORDTREEWIDGET_H

#include <QObject>
#include <QWidget>
#include <QTreeWidget>
#include <QVector>
#include <QPair>

#include "globaldef.hpp"
#include "CoordData/coordtreenode.h"

class CoordTreeWidget : public QTreeWidget
{
    Q_OBJECT
public:
    explicit CoordTreeWidget(QWidget *parent = nullptr);
    void TreeWidgetInit();
    QTreeWidgetItem* addTreeItem(QTreeWidgetItem *parentItem,QString name,FILETYPE TYPE = FILETYPE::COORDFILE);
    void ReadTreeNode(const CoordTreeNode& node);
    void MatchText();
    void ClearTree();//添加之前需要调用

private:
    void onItemDoubleClicked(QTreeWidgetItem *item, int column);
    void onItemExpanded(QTreeWidgetItem *item);
    void onItemCollapsed(QTreeWidgetItem *item);

signals:
    void signal_Filecreate(const CoordTreeNode &node);

private:
    QVector<QTreeWidgetItem*> listItem;
    QVector<QPair<QString,FILETYPE> > textList;
    QMap<QTreeWidgetItem*,CoordTreeNode> DateBase;
    QTreeWidgetItem *topItem = nullptr;
    QTreeWidgetItem *parentItem = nullptr;

    const QColor NormalColor = QColor(58,59,62);//普通
    const QColor pressColor = QColor(81,82,84);//单击
    const QColor DbpressColor = QColor(35,36,39);//双击

    const QString OpenPath = ":/images/png/file_open.svg";
    const QString ClosePath = ":/images/png/file_close.svg";
    const QString TextPath = ":/images/png/text.svg";
};

#endif // COORDTREEWIDGET_H
