#ifndef COORDTREENODE_H
#define COORDTREENODE_H

#include <QObject>
#include <QMap>
#include <QList>
#include <QString>
#include <QDebug>

#include "globaldef.hpp"

class CoordTreeNode : public QObject
{
    Q_OBJECT
public:
    CoordTreeNode(){};
    CoordTreeNode(const QString x,const QString y,FILETYPE type):filename(x),filePath(y),isFile(type){};
    ~CoordTreeNode(){
        qDeleteAll(children);
    };
    void addChild(CoordTreeNode* child) {
        children.append(child);
    }

    CoordTreeNode(const CoordTreeNode& other)
        :filename(other.filename),filePath(other.filePath),isFile(other.isFile)
    {
        for (CoordTreeNode* child : other.children) {
            children.append(new CoordTreeNode(*child));
        }
    }

    CoordTreeNode& operator=(const CoordTreeNode& other)
    {
        if(this == &other)
        {
            return *this;
        }

        qDeleteAll(children);
        children.clear();

        filename = other.filename;
        filePath = other.filePath;
        isFile = other.isFile;

        for (CoordTreeNode* child : other.children)
        {
            children.append(new CoordTreeNode(*child));
        }

        return *this;
    }


public:
    QString filename;  // 文件或目录的名称
    QString filePath;
    FILETYPE isFile;   // 标记节点是否为文件
    QList<CoordTreeNode*> children; // 子节点列表

};

#endif // COORDTREENODE_H
