#include <QDateTime>
#include "coordchartgenerate.h"

QMap<QString, QVector<ChartDateBase*>> CoordChartGenerate::ExclMap;
QMap<QString ,QVector<ChartDateBase*>> CoordChartGenerate::ExclColMap;
QMap<QString ,QCustomPlot *> CoordChartGenerate::CoordCustomPlot;
const QVector<QColor> CoordChartGenerate::fluorescentColors = {
    QColor(250, 170, 20),  // 橙色
    QColor(111, 9, 176),   // 深紫色
    QColor(60, 168, 140),  // 荧光绿
    QColor(255, 105, 180), // 粉色
    QColor(0, 255, 255),   // 青色
    QColor(255, 0, 255),   // 品红
    QColor(0, 255, 0),     // 亮绿色
    QColor(255, 255, 0),   // 亮黄色
    QColor(255, 69, 0),    // 红色橙
    QColor(186, 85, 211),  // 深紫色
    QColor(0, 191, 255),   // 深天蓝色
    QColor(255, 20, 147),  // 深粉色
    QColor(255, 165, 0),   // 橙色
    QColor(255, 0, 0),     // 亮红色
    QColor(0, 0, 255),     // 亮蓝色
    QColor(144, 238, 144), // 亮绿黄色
    QColor(255, 192, 203)  // 浅粉色
};

CoordChartGenerate::CoordChartGenerate() {}

void CoordChartGenerate::ReadExcl(const QString& path)
{
    if(!ExclMap[path].isEmpty()) return;

    QXlsx::Document xlsx(path);
    if (!xlsx.load()) {
        return;
    }

    int rowCount = xlsx.dimension().rowCount();
    int colCount = xlsx.dimension().columnCount();

    if (rowCount < 2 || colCount < 2) {
        return;
    }

    //读取行索引和列索引
    ChartDateBase *ROW = new ChartDateBase();//存储第一行
    ROW->key = "#";
    ChartDateBase *COL = new ChartDateBase();//存储第一列
    COL->key = "#";
    for (int col = 2; col <= colCount; ++col)
    {
        QVariant header = xlsx.read(1, col);  // 读取第一行所有列
        ROW->addChild(header);
    }
    for(int row = 2; row <= rowCount; ++row)
    {
        QVariant header = xlsx.read(row, 1);  // 读取第一列所有行
        COL->addChild(header);
    }
    ExclMap[path].append(ROW);
    ExclMap[path].append(COL);

    //按行读取EXCL剩余所有内容
    for(int row = 2; row<=rowCount ;row++)
    {
        ChartDateBase *Item = new ChartDateBase();
        Item->key = xlsx.read(row,1);
        QVariant header;
        for(int col = 2; col<=colCount; col++)
        {
            header = xlsx.read(row,col);
            Item->addChild(header);
        }
        ExclMap[path].append(Item);
    }

    //按列读取EXCL剩余所有内容
    for(int col = 2; col <=colCount ;col++)
    {
        ChartDateBase *Item = new ChartDateBase();
        Item->key = xlsx.read(1,col);//列ID
        QVariant header;
        for(int row = 2; row<=rowCount; row++)
        {
            header = xlsx.read(row,col);
            Item->addChild(header);
        }
        ExclColMap[path].append(Item);
    }
}

void CoordChartGenerate::DrawmarkBrokenLine(const QString& path,QCustomPlot *customPlot)
{//绘制曲线图
    ReadExcl(path);
    if(ExclMap[path].isEmpty() || ExclColMap[path].isEmpty()) return ;
    customPlot->clearPlottables();
    customPlot->clearItems();

    QVector<ChartDateBase*> chartList = ExclMap[path];//存储图表中的所有数据
    qint32 count = chartList[1]->getSize();
    double bestmark = 0;
    QVector<double> x,y;
    QVector<double>tickers;
    QVector<QString>labels;

    for(int i=0; i < count; i++)
    {
        tickers.append(i+1);
        labels.append(chartList[1]->ValueList[i].toString());
    }

    for(int i=2; i<chartList.size(); i++)
    {//遍历每个同学的成绩
        ChartDateBase* data = chartList[i];
        double sum = 0;
        for(const auto &mark : data->ValueList)
        {//算每个同学的总分
            sum+=mark.toDouble();
        }
        x.append(i-1);//同学的ID
        y.append(sum);//同学的成绩
        bestmark = qMax(bestmark,sum);
    }

    customPlot->addGraph();
    customPlot->graph(0)->setData(x, y);
    customPlot->xAxis->setLabel("x");
    customPlot->yAxis->setLabel("y");
    customPlot->xAxis->setRange(1, count+1);
    customPlot->yAxis->setRange(0, bestmark);
    customPlot->yAxis->ticker()->setTickCount(count);
    QSharedPointer<QCPAxisTickerText> textTicket(new QCPAxisTickerText);
    textTicket->addTicks(tickers,labels);
    customPlot->xAxis->setTicker(textTicket);
    customPlot->xAxis->setTickLabelRotation(40);
    CoordCustomPlot[path] = customPlot;
}

void CoordChartGenerate::DrawmarkBarLine(const QString& path,QCustomPlot *customPlot)
{
    ReadExcl(path);
    if(ExclMap[path].isEmpty() || ExclColMap[path].isEmpty()) return ;
    customPlot->clearPlottables();
    customPlot->clearItems();


    // 设置背景颜色
    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(90, 90, 90));
    gradient.setColorAt(0.38, QColor(105, 105, 105));
    gradient.setColorAt(1, QColor(70, 70, 70));
    customPlot->setBackground(QBrush(gradient));

    QVector<ChartDateBase*> chartList = ExclMap[path];//按行存储的数据
    QVector<ChartDateBase*> chartColList = ExclColMap[path];//按列存储的数据
    qint32 count = chartList[1]->getSize();
    QVector<double>tickers;
    QVector<QString>labels;

    for(int i=0; i < count; i++)
    {//读取Excl有多少行，每一行都是x的一个刻度
        tickers.append(i+1);
        labels.append(chartList[1]->ValueList[i].toString());
    }

    QList<QCPBars*> BarList;
    qint32 colcount = chartList[0]->getSize();
    for(int i=0; i<colcount; i++)
    {//读取有多少列，也就是有多少种数据
        QCPBars *bar = new QCPBars(customPlot->xAxis, customPlot->yAxis);
        QString name = chartList[0]->ValueList[i].toString();

        bar->setAntialiased(false);
        bar->setStackingGap(1);
        bar->setName(name);
        QColor color = fluorescentColors[i];
        bar->setPen(QPen(QColor(color).lighter(130)));
        bar->setBrush(color);
        if( i>0 )
        {
            bar->moveAbove(BarList[i-1]);
        }
        BarList.append(bar);
    }

    //按列读取每一行数据
    QList<QVector<double>> DataList;
    double bestnum = 0.0;
    for(int i=0; i<chartColList.size(); i++)
    {//遍历列
        ChartDateBase* data = chartColList[i];
        QVector<double> vector;
        double sum = 0.0;
        for(const auto &mark : data->ValueList)
        {//遍历行
            double data = mark.toDouble();
            vector.append(data);
            sum =qMax(data,sum);
        }
        bestnum += sum;
        DataList.append(vector);
    }

    if(DataList.size() != BarList.size())
    {
        return ;
    }

    for(int i=0; i<BarList.size(); i++)
    {
        BarList[i]->setData(tickers,DataList[i]);
    }

    // 按照行数定制x的刻度数量
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(tickers, labels);
    customPlot->xAxis->setTicker(textTicker);
    customPlot->xAxis->setTickLabelRotation(60);
    customPlot->xAxis->setSubTicks(false);
    customPlot->xAxis->setTickLength(0, 4);
    customPlot->xAxis->setRange(0, 8);
    customPlot->xAxis->setBasePen(QPen(Qt::white));
    customPlot->xAxis->setTickPen(QPen(Qt::white));
    customPlot->xAxis->grid()->setVisible(true);
    customPlot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    customPlot->xAxis->setTickLabelColor(Qt::white);
    customPlot->xAxis->setLabelColor(Qt::white);

    // prepare y axis:
    customPlot->yAxis->setRange(0, bestnum);
    customPlot->yAxis->setPadding(5);
    // customPlot->yAxis->setLabel("");
    customPlot->yAxis->setBasePen(QPen(Qt::white));
    customPlot->yAxis->setTickPen(QPen(Qt::white));
    customPlot->yAxis->setSubTickPen(QPen(Qt::white));
    customPlot->yAxis->grid()->setSubGridVisible(true);
    customPlot->yAxis->setTickLabelColor(Qt::white);
    customPlot->yAxis->setLabelColor(Qt::white);
    customPlot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
    customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    //customPlot->yAxis->setScaleType(QCPAxis::stLogarithmic);//对数尺度缩放

    customPlot->legend->setVisible(true);
    customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
    customPlot->legend->setBrush(QColor(255, 255, 255, 100));
    customPlot->legend->setBorderPen(Qt::NoPen);
    QFont legendFont;
    legendFont.setPointSize(10);
    customPlot->legend->setFont(legendFont);
    customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
    CoordCustomPlot[path] = customPlot;
}

void CoordChartGenerate::DrawmarkScatterLine(const QString& path,QCustomPlot *customPlot)
{
    ReadExcl(path);
    if(ExclMap[path].isEmpty() || ExclColMap[path].isEmpty()) return ;
    customPlot->clearPlottables();
    customPlot->clearItems();

    QVector<ChartDateBase*> chartList = ExclMap[path];//存储图表中的所有数据
    qint32 count = chartList[1]->getSize();
    double bestmark = 0;
    QVector<double> x,y;
    QVector<double>tickers;
    QVector<QString>labels;

    for(int i=0; i < count; i++)
    {
        tickers.append(i+1);
        labels.append(chartList[1]->ValueList[i].toString());
    }

    for(int i=2; i<chartList.size(); i++)
    {//遍历每个同学的成绩
        ChartDateBase* data = chartList[i];
        double sum = 0;
        for(const auto &mark : data->ValueList)
        {//算每个同学的总分
            sum+=mark.toDouble();
        }
        x.append(i-1);//同学的ID
        y.append(sum);//同学的成绩
        bestmark = qMax(bestmark,sum);
    }


    customPlot->addGraph();
    //customPlot->graph()->setLineStyle(QCPGraph::lsLine);
    QPen pen;
    pen.setColor(QColor(255, 200, 20, 200));
    pen.setStyle(Qt::DashLine);
    pen.setWidthF(2.5);
    customPlot->graph()->setPen(pen);
    customPlot->graph()->setBrush(QBrush(QColor(255,200,20,70)));
    // 设置数据
    customPlot->graph()->setData(x, y);

    //设置标题
    //customPlot->plotLayout()->insertRow(0);
    //customPlot->plotLayout()->addElement(0, 0, new QCPTextElement(customPlot, , QFont("sans", 12, QFont::Bold)));

    //设置x轴刻度标签
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(tickers, labels);
    customPlot->xAxis->setTicker(textTicker);
    customPlot->xAxis->setTickLabelRotation(60);
    customPlot->xAxis->setSubTicks(false);
    customPlot->xAxis->setTickLength(0, 4);

    //设置可见轴
    customPlot->xAxis2->setVisible(true);
    customPlot->yAxis2->setVisible(true);
    customPlot->xAxis2->setTickLabels(false);
    customPlot->yAxis2->setTickLabels(false);
    customPlot->xAxis2->setTicks(false);
    customPlot->yAxis2->setTicks(false);
    customPlot->xAxis2->setSubTicks(false);
    customPlot->yAxis2->setSubTicks(false);
    //设置范围
    customPlot->xAxis->setRange(1, count+1);
    customPlot->yAxis->setRange(0, bestmark);


    QFont legendFont;
    legendFont.setPointSize(10);
    customPlot->legend->setFont(legendFont);
    customPlot->legend->setIconSize(50, 20);
    customPlot->legend->setVisible(true);
    customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignLeft | Qt::AlignTop);
    CoordCustomPlot[path] = customPlot;
}

bool CoordChartGenerate::ExporExcl(const QString& directoryPath)
{
    QDir dir(directoryPath);
    if (!dir.exists()) {
        if (!dir.mkpath(".")) {
            return false;
        }
    }
    if(CoordCustomPlot.isEmpty())
    {
        return false;
    }
    for(auto customPlot : CoordCustomPlot)
    {
        QString timestamp = QDateTime::currentDateTime().toString("yyyyMMddHHmmss");
        QString jpgPath = directoryPath + '/' + timestamp +".jpg";
        QString pdfPath = directoryPath + '/' + timestamp +".pdf";
        QString pngPath = directoryPath + '/' + timestamp +".png";
        customPlot->saveJpg(jpgPath, 1024, 768);
        customPlot->savePdf(pdfPath, 1024, 768);
        customPlot->savePng(pngPath, 1024, 768);
    }
    return true;
}

CoordChartGenerate::~CoordChartGenerate()
{
    for (auto& itemList : ExclMap) {
        qDeleteAll(itemList);
    }
    ExclMap.clear();
}
