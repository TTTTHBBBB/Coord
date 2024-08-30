#ifndef CHARTDATEBASE_H
#define CHARTDATEBASE_H

#include <QObject>
#include <QMap>
#include <QList>
#include <QString>
#include <QDebug>

#include "globaldef.hpp"

class ChartDateBase : public QObject
{
    Q_OBJECT
public:
    // 默认构造函数
    ChartDateBase() : size(0) {}

    // 析构函数
    ~ChartDateBase() override = default;

    // 添加子节点
    void addChild(const QVariant& child) {
        ValueList.append(child);
    }

    // 拷贝构造函数
    ChartDateBase(const ChartDateBase& other)
        : key(other.key), size(other.size), ValueList(other.ValueList){}

    // 赋值操作符
    ChartDateBase& operator=(const ChartDateBase& other) {
        if (this != &other) {
            key = other.key;
            size = other.size;
            ValueList = other.ValueList;
        }
        return *this;
    }

    // 清空函数
    void clear() {
        ValueList.clear();
        size = 0;
    }

    // 获取大小
    quint32 getSize() const { return ValueList.size(); }

public:
    QVariant key;  // 第一行的每一列，索引
    quint32 size = 0;//行数
    QList<QVariant> ValueList; // 按行存储每一列数据
};

#endif // CHARTDATEBASE_H
