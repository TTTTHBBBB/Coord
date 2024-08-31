#include "coordtreewidget.h"

CoordTreeWidget::CoordTreeWidget(QWidget *parent)
    :QTreeWidget(parent)
{
    this->TreeWidgetInit();
}

void CoordTreeWidget::TreeWidgetInit()
{
    this->setStyleSheet(
        "QTreeWidget{"
        "   background-color: rgb(58, 59, 62);"
        "}"
        "QTreeWidget::item:selected {"
        "   background-color: rgb(58, 59, 62);"
        "}"
        "QTreeWidget::item:hover {"
        "   background-color: rgb(81, 82, 84);"
        "}"
        "QTreeWidget::item:focus {"
        "   background-color: rgb(35, 36, 39);"
        "}"
        "QTreeWidget::item:selected:!active {"
        "   background-color: rgb(58, 59, 62);"
        "}"
        "QTreeWidget::item {"
        "   color: white;"
        "}"
        );

    this->setFrameStyle(QFrame::NoFrame);
    this->setHeaderHidden(true);

    connect(this, &QTreeWidget::itemDoubleClicked, this, &CoordTreeWidget::onItemDoubleClicked);
    connect(this, &QTreeWidget::itemExpanded, this, &CoordTreeWidget::onItemExpanded);
    connect(this, &QTreeWidget::itemCollapsed, this, &CoordTreeWidget::onItemCollapsed);
    this->MatchText();
}

void CoordTreeWidget::onItemCollapsed(QTreeWidgetItem *item)
{//折叠事件
    item->setIcon(0,QIcon(ClosePath));
}

void CoordTreeWidget::onItemExpanded(QTreeWidgetItem *item)
{//展开事件
    item->setIcon(0,QIcon(OpenPath));
}

void CoordTreeWidget::MatchText()
{//重刷文本
    if(listItem.size() != textList.size()) return ;

    for(int i = 0; i< listItem.size(); i++)
    {
        QString name = textList[i].first;
        listItem[i]->setText(0,name);
    }
}

QTreeWidgetItem* CoordTreeWidget::addTreeItem(QTreeWidgetItem *parentItem,QString name,FILETYPE TYPE)
{
    if(name.isEmpty() || parentItem == nullptr) return nullptr;

    QTreeWidgetItem *item = new QTreeWidgetItem();
    if(TYPE == FILETYPE::COORDFILE)
    {
        item->setIcon(0,QIcon(ClosePath));
        item->setText(0,name);
        item->setBackground(0,NormalColor);
    }
    else if(TYPE == FILETYPE::COORDTEXT)
    {
        item->setIcon(0,QIcon(TextPath));
        item->setText(0,name);
        item->setBackground(0,NormalColor);
    }
    parentItem->addChild(item);
    listItem.append(item);
    textList.append({name,TYPE});

    return item;
}

void CoordTreeWidget::ReadTreeNode(const CoordTreeNode& rote,QTreeWidgetItem *parentItem)
{//层节点都是目录
    if(rote.isFile == FILETYPE::COORDROTE)
    {//根节点
        topItem->setText(0,rote.filename);
        this->addTopLevelItem(topItem);
        parentItem = topItem;
    }else if(rote.isFile == FILETYPE::COORDFILE)
    {//子目录节点
        parentItem = addTreeItem(parentItem,rote.filename,rote.isFile);
    }

    if(parentItem == nullptr) return ;
    DateBase[parentItem] = rote;

    for(auto node = rote.children.constBegin(); node != rote.children.constEnd(); node++)
    {
        CoordTreeNode* childNode = *node;
        if(childNode->isFile == FILETYPE::COORDFILE)
        {
            ReadTreeNode(*childNode,parentItem);
        }else if(childNode->isFile == FILETYPE::COORDTEXT)
        {
            QTreeWidgetItem *Childitem = addTreeItem(parentItem,childNode->filename,childNode->isFile);
            DateBase[Childitem] = *childNode;
        }
    }
}
void CoordTreeWidget::onItemDoubleClicked(QTreeWidgetItem *item, int column)
{//双击事件
    Q_UNUSED(column);
    for(int i = 0; i<listItem.size(); i++)
    {
        if(listItem[i] == item )
        {
            if(textList[i].second == FILETYPE::COORDFILE && item->childCount() > 0)
            {
                item->setExpanded(item->isExpanded());
            }
            emit signal_Filecreate(DateBase[item]);
        }
    }
}

void CoordTreeWidget::ClearTree()
{
    this->clear();
    this->setColumnCount(1);
    listItem.clear();
    textList.clear();
    topItem = new QTreeWidgetItem();
    topItem->setIcon(0,QIcon(ClosePath));
    parentItem = new QTreeWidgetItem();
}
