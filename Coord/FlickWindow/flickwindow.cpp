#include <QPainter>
#include <QPen>
#include <QtMath>
#include <QPolygonF>
#include <QVector>

#include "flickwindow.h"
#include "ui_flickwindow.h"

FlickWindow::FlickWindow(QWidget *parent ,FLICKTYPE type)
    : QFrame(parent)
    , filcktype(type)
    , ui(new Ui::FlickWindow)
{
    ui->setupUi(this);
    this->Init();
}

void FlickWindow::Init()
{
    ui->frameBtn->installEventFilter(this);
    continueTime = new QTimer();
    continueTime->setInterval(1500);

    ShowAnimation = new QPropertyAnimation(this,"geometry");
    HideAnimation = new QPropertyAnimation(this,"geometry");

    if(QWidget *parentWidget = this->parentWidget())
    {
        int width = parentWidget->width();
        int height = 50;
        this->setFixedWidth(width);
        this->setFixedHeight(height);
        this->setGeometry(0,-height,width,height);

        //设置弹出动画
        ShowAnimation->setDuration(800);
        ShowAnimation->setStartValue(QRect(0,-height,width,height));
        ShowAnimation->setEndValue(QRect(0,0,width,height));
        ShowAnimation->setEasingCurve(QEasingCurve::OutBounce);

        //设置弹回动画
        HideAnimation->setDuration(800);
        HideAnimation->setStartValue(QRect(0,0,width,height));
        HideAnimation->setEndValue(QRect(0,-height,width,height));
        HideAnimation->setEasingCurve(QEasingCurve::InBounce);
    }

    connect(continueTime, &QTimer::timeout, this, &FlickWindow::Slot_timeout);
    connect(ShowAnimation, &QPropertyAnimation::finished, this,[=](){
        continueTime->start();
    });
    connect(HideAnimation, &QPropertyAnimation::finished, this,[=](){
        this->hide();
    });
}

void FlickWindow::setFlickWidth(int width)
{
    if(width <= 150) return ;
    this->setFixedWidth(width);
}

void FlickWindow::showEvent(QShowEvent *event)
{
    Q_UNUSED(event);
    if(ShowAnimation!=nullptr)
    {
        ShowAnimation->start();
    }
}

void FlickWindow::hideEvent(QHideEvent *event)
{
    Q_UNUSED(event);
    if(HideAnimation!=nullptr)
    {
        HideAnimation->start();
    }
}

void FlickWindow::Slot_timeout()
{
    continueTime->stop();
    if(HideAnimation!=nullptr)
    {
        HideAnimation->start();
    }
}

void FlickWindow::setFlickType(FLICKTYPE type)
{
    filcktype = type;
    update();
}

void FlickWindow::setFlickText(QString str)
{
    if(!str.isEmpty())
    {
        flicktext = str;
    }
}

void FlickWindow::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
    update();
}

int FlickWindow::getFontsize(QRectF rect)
{
    int fontSize = 30;
    QFont font("微软雅黑", fontSize);

    QFontMetrics metrics(font);
    QSize textSize = metrics.size(Qt::TextSingleLine, flicktext);

    while (textSize.width() > rect.width() || textSize.height() > rect.height())
    {
        fontSize--;
        if (fontSize <= 1) break;
        font.setPointSize(fontSize);
        metrics = QFontMetrics(font);
        textSize = metrics.size(Qt::TextSingleLine, flicktext);
    }

    return fontSize;
}

void FlickWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QFrame::paintEvent(event);
    int btnwidth = this->width() - ui->frameBtn->width() - 10;
    int btnheight = (this->height() - (ui->frameBtn->height())) / 2 ;
    ui->frameBtn->move(btnwidth,btnheight);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QRect titleRect = ui->frameTitle->rect();

    qreal textHeight = height() - 20;
    qreal textwidth = ui->frameText->width() - ui->frameBtn->width() - 10;
    QRectF textRect(ui->frameText->x()+15,ui->frameTitle->y()+10, textwidth, textHeight);
    int fontsize = getFontsize(textRect);

    QRect btnRect(ui->frameBtn->x()+10,(ui->frameBtn->height()-20)/2,20,20);

    switch (filcktype)
    {
        case FLICKTYPE::SUCCESS:
        {
            //绘制整体背景
            painter.setPen(Qt::NoPen);
            painter.setBrush(QColor(243,246,243));
            painter.drawRect(this->rect());

            //绘制标题区域背景
            painter.setBrush(QColor(51,170,127));
            painter.drawRect(titleRect);

            //绘制标题区图案
            QPen titlepen;
            titlepen.setStyle(Qt::SolidLine);
            titlepen.setColor(Qt::white);
            titlepen.setWidth(3);
            painter.setPen(titlepen);

            QPointF pointStart(10.0,25.0),pointCenter(20.0,35.0),pointEnd(titleRect.width()-10.0,10.0);
            painter.drawLine(pointStart,pointCenter);
            painter.drawLine(pointCenter,pointEnd);
            //绘制文字区
            painter.setPen(QPen(QColor(88,201,184)));
            painter.setFont(QFont("微软雅黑",fontsize));
            painter.drawText(textRect, Qt::AlignLeft | Qt::AlignVCenter, flicktext);

            //绘制按钮
            QPen pen;
            pen.setWidth(3);
            pen.setColor(QColor(45,128,96));
            pen.setStyle(Qt::SolidLine);
            painter.setPen(pen);

            QPoint topLeft = btnRect.topLeft();
            QPoint bottomRight = btnRect.bottomRight();
            QPoint topRight = btnRect.topRight();
            QPoint bottomLeft = btnRect.bottomLeft();

            painter.drawLine(topLeft,bottomRight);
            painter.drawLine(topRight,bottomLeft);

            break;
        }
        case FLICKTYPE::FAILD:
        {
            //绘制背景
            painter.setPen(Qt::NoPen);
            painter.setBrush(QColor(236,221,231));
            painter.drawRect(this->rect());

            //绘制标题区域背景
            painter.setBrush(QColor(255,88,102));
            painter.drawRect(titleRect);

            //绘制标题区域图标
            QPen titlepen;
            titlepen.setStyle(Qt::SolidLine);
            titlepen.setColor(Qt::white);
            titlepen.setWidth(3);
            painter.setPen(titlepen);
            //绘制圆形
            qreal radius = titleRect.width() - 14.0;
            qreal TopLeftX = (titleRect.width()-radius)/2.0;
            qreal TopLeftY = (titleRect.width()-radius)/2.0;
            painter.drawEllipse(QRectF(TopLeftX,TopLeftY,radius,radius));
            //绘制斜线
            QPointF start(TopLeftX+(radius-radius*qCos(M_PI/4.0))/2.0, TopLeftY+(radius+radius*qSin(M_PI/4.0))/2.0);
            QPointF end(TopLeftX+(radius+radius*qCos(M_PI/4.0))/2.0, TopLeftY+(radius-radius*qSin(M_PI/4.0))/2.0);
            painter.drawLine(start,end);

            //绘制文字区
            painter.setPen(QPen(QColor(237,73,103)));
            painter.setFont(QFont("微软雅黑",fontsize));
            painter.drawText(textRect, Qt::AlignLeft | Qt::AlignVCenter, flicktext);

            //绘制按钮
            QPen pen;
            pen.setWidth(3);
            pen.setColor(QColor(204,44,51));
            pen.setStyle(Qt::SolidLine);
            painter.setPen(pen);

            QPoint topLeft = btnRect.topLeft();
            QPoint bottomRight = btnRect.bottomRight();
            QPoint topRight = btnRect.topRight();
            QPoint bottomLeft = btnRect.bottomLeft();

            painter.drawLine(topLeft,bottomRight);
            painter.drawLine(topRight,bottomLeft);

            break;
        }
        case FLICKTYPE::WARNING:
        {
            //绘制整体背景
            painter.setPen(Qt::NoPen);
            painter.setBrush(QColor(237,240,229));
            painter.drawRect(this->rect());

            //绘制标题区域背景
            painter.setBrush(QColor(199,160,0));
            painter.drawRect(titleRect);

            //绘制标题区域图标
            painter.setBrush(Qt::white);
            // 计算感叹号的圆圈和直线部分的尺寸
            int length = qMin(ui->frameTitle->width(), ui->frameTitle->height());

            // 计算感叹号的圆圈和直线部分的尺寸
            qreal topMargin = 7.0; // 上边距
            qreal linetoradius = 3.0; //直线和圆形之间的距离
            qreal circleRadius = length / 12.0;//圆所占据矩形大小
            qreal lineWidth = length / 16.0; //竖线的宽度
            qreal lineHeight = length - topMargin*2 - circleRadius - linetoradius;

            // 直线的起点
            qreal lineX = (length - lineWidth)/ 2.0;
            qreal lineY = topMargin;
            // 圆圈所占矩形的起始位置
            qreal circleX = (length - circleRadius)/ 2.0;
            qreal circleY = topMargin + lineHeight + linetoradius;
            // 绘制感叹号的直线部分
            painter.drawRect(QRectF(lineX, lineY, lineWidth, lineHeight));
            // 绘制感叹号的圆圈部分
            painter.drawEllipse(QRectF(circleX, circleY, circleRadius, circleRadius));

            //绘制文字区
            painter.setPen(QPen(QColor(223,212,192)));
            painter.setFont(QFont("微软雅黑",fontsize));
            painter.drawText(textRect, Qt::AlignLeft | Qt::AlignVCenter, flicktext);

            //绘制按钮
            QPen pen;
            pen.setWidth(3);
            pen.setColor(QColor(147,123,114));
            pen.setStyle(Qt::SolidLine);
            painter.setPen(pen);

            QPoint topLeft = btnRect.topLeft();
            QPoint bottomRight = btnRect.bottomRight();
            QPoint topRight = btnRect.topRight();
            QPoint bottomLeft = btnRect.bottomLeft();

            painter.drawLine(topLeft,bottomRight);
            painter.drawLine(topRight,bottomLeft);

            break;
        }
        default:
            break;
    }

    //QWidget::paintEvent(event);
}

bool FlickWindow::eventFilter(QObject *watched, QEvent *event)
{
    if(watched == ui->frameBtn)
    {
        if(event->type() == QEvent::MouseButtonRelease)
        {
            //this->close();
            HideAnimation->start();
        }
    }
    return QObject::eventFilter(watched, event);
}

FlickWindow::~FlickWindow()
{
    delete ui;
}
