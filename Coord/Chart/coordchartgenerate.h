#ifndef COORDCHARTGENERATE_H
#define COORDCHARTGENERATE_H

#include <QObject>

#include "globaldef.hpp"
#include "ChartDateBase.h"
#include "qcustomplot.h"
#include "QXlsx/header/xlsxdocument.h"
using namespace QXlsx;

class CoordChartGenerate : public QObject
{
    Q_OBJECT
public:
    explicit CoordChartGenerate();
    ~CoordChartGenerate();
    static void ReadExcl(const QString& path);
    static bool ExporExcl(const QString& path);
    static void DrawmarkBrokenLine(const QString& path,QCustomPlot *customPlot);//绘制曲线图
    static void DrawmarkBarLine(const QString& path,QCustomPlot *customPlot);//绘制柱状图
    static void DrawmarkScatterLine(const QString& path,QCustomPlot *customPlot);//绘制折线图

signals:
    void signal_FlickWindow(const QString str, const FLICKTYPE type);

private:
    static QMap<QString ,QVector<ChartDateBase*> > ExclMap;
    //存储从excl读取的每一行数据,第一个结点存储行索引，第二个结点数据存储列索引
    static QMap<QString ,QVector<ChartDateBase*> > ExclColMap;
    //存储从Excl读取的每一列数据，从第一个结点开始存储
    static const QVector<QColor> fluorescentColors;
    static QMap<QString ,QCustomPlot *> CoordCustomPlot;
};

#endif // COORDCHARTGENERATE_H
