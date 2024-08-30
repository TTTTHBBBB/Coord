#include "collapsewidget.h"
#include "ui_collapsewidget.h"

CollapseWidget::CollapseWidget(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::CollapseWidget)
{
    ui->setupUi(this);
    this->initAnimation();
}

void CollapseWidget::initAnimation()
{
    //线段绘制动画
    m_showLineAnimation = new QPropertyAnimation(this,"showLine");
    m_showLineAnimation->setDuration(1000);
    m_showLineAnimation->setEasingCurve(QEasingCurve::InOutBack);

    //线段取消动画
    m_cancelLineAnimation = new QPropertyAnimation(this,"cancelLine");
    m_cancelLineAnimation->setDuration(1000);
    m_cancelLineAnimation->setEasingCurve(QEasingCurve::InOutBack);

    //样式绘制动画
    m_radiusAnimation = new QPropertyAnimation(this,"radius");
    m_radiusAnimation->setDuration(1000);
    m_radiusAnimation->setStartValue(0);
    m_radiusAnimation->setEndValue(qMax(height(),width())*2);
    m_radiusAnimation->setEasingCurve(QEasingCurve::InOutBack);

    //样式取消动画
    m_cancleRadiusAnimation = new QPropertyAnimation(this,"cancleRadius");
    m_cancleRadiusAnimation->setDuration(1000);
    m_cancleRadiusAnimation->setStartValue(qMax(height(),width())*2);
    m_cancleRadiusAnimation->setEndValue(0);
    m_cancleRadiusAnimation->setEasingCurve(QEasingCurve::InOutBack);

    TYPE = COLLSPSESTAUS::SYSTOLIC;
    ANIMATIONTYPE = STATUS::INITIALIZATION;

    connect(m_cancelLineAnimation, &QPropertyAnimation::finished, this, &CollapseWidget::drawDisplayAnimation);
    connect(m_cancleRadiusAnimation, &QPropertyAnimation::finished, this, &CollapseWidget::drawShowAnimation);

}

void CollapseWidget::drawShowAnimation()
{
    ANIMATIONTYPE = STATUS::LINESHOW;
    m_showLineAnimation->start();
    update();
}

void CollapseWidget::drawDisplayAnimation()
{
    ANIMATIONTYPE = STATUS::RADIUSSHOW;
    m_radiusAnimation->start();
    update();
}

void CollapseWidget::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);

    int parentwidth = width();
    int parentheight = height();
    int calibre = qMin(parentwidth, parentheight) - 10;

    // 计算画笔宽度
    int penWidth = 4; // 画笔宽度

    // 计算调整后的圆形矩形大小
    int adjustedCalibre = calibre - penWidth; // 减去画笔宽度的一半

    btnrect.setTopLeft(QPointF((parentwidth - adjustedCalibre) / 2, (parentheight - adjustedCalibre) / 2));
    btnrect.setBottomRight(QPointF((parentwidth + adjustedCalibre) / 2, (parentheight + adjustedCalibre) / 2));

    pointTop = QPoint(parentwidth / 2, (parentheight - adjustedCalibre) / 2 - penWidth/2 );
    pointBottom = QPoint(parentwidth / 2, (parentheight + adjustedCalibre) / 2 + penWidth/2);

    initLine = height()/2-adjustedCalibre/2-penWidth;

    //设置绘制线段
    m_showLineAnimation->setStartValue(0);
    m_showLineAnimation->setEndValue(height()/2-adjustedCalibre/2-penWidth);

    //设置取消线段
    m_cancelLineAnimation->setStartValue(height()/2-adjustedCalibre/2-penWidth);
    m_cancelLineAnimation->setEndValue(0);
}

void CollapseWidget::startAnimation()
{
    ANIMATIONTYPE = STATUS::RADIUSDISPLAY;
    m_cancleRadiusAnimation->start();
    update();
}

void CollapseWidget::displayAnimation()
{
    ANIMATIONTYPE = STATUS::LINEDISPLAY;
    m_cancelLineAnimation->start();
    update();
}

void CollapseWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPen pen;
    pen.setStyle(Qt::SolidLine);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // 绘制样式
    pen.setWidth(3); // 调整样式画笔宽度
    pen.setColor(QColor(0, 170, 128));
    painter.setPen(pen);

    QPointF topCenter(width()/2,0);
    QPointF bottomCenter(width()/2,height());
    QPointF StarTopEllipse(pointTop);//上半区绘制
    QPointF CancleTopEllipse(pointTop);
    QPointF StartEllipse(pointBottom);//下半区绘制
    QPointF CancleEllips(pointBottom);

    if(ANIMATIONTYPE == STATUS::INITIALIZATION)
    {
        //上半区
        StarTopEllipse.setY(initLine);
        painter.drawLine(topCenter, StarTopEllipse);
        //下半区
        StartEllipse.setY(height()-initLine);
        painter.drawLine(StartEllipse,bottomCenter);
    }
    else if(ANIMATIONTYPE == STATUS::LINESHOW)
    {//创建
        //上半区
        StarTopEllipse.setY(showLine);
        painter.drawLine(topCenter, StarTopEllipse);
        //下半区
        StartEllipse.setY(height()-showLine);
        painter.drawLine(StartEllipse,bottomCenter);
    }
    else if(ANIMATIONTYPE == STATUS::LINEDISPLAY)
    {
        //上半区
        CancleTopEllipse.setY(cancelLine);
        painter.drawLine(topCenter, CancleTopEllipse);
        //下半区
        CancleEllips.setY(height()-cancelLine);
        painter.drawLine(CancleEllips,bottomCenter);
    }

    if(ANIMATIONTYPE == STATUS::RADIUSSHOW || ANIMATIONTYPE == STATUS::RADIUSDISPLAY)
    {
        qreal amendment = 0;
        ANIMATIONTYPE == STATUS::RADIUSSHOW ? amendment = radius : amendment = cancleRadius;

        painter.setPen(Qt::NoPen);
        painter.setBrush(QColor(64,65,66));
        painter.drawEllipse(QPointF(0,0), amendment, amendment);
        painter.drawEllipse(QPointF(width(),height()), amendment, amendment);
    }

    //绘制按钮
    pen.setWidth(4); // 画笔宽度
    pen.setColor(QColor(10, 238, 167));
    QBrush brush(QColor(0, 170, 128));
    painter.setBrush(brush);
    painter.setPen(pen);
    // 绘制圆形
    painter.drawEllipse(btnrect);

}

void CollapseWidget::mousePressEvent(QMouseEvent *event)
{
    m_pressPos = event->pos();
    update();
}

void CollapseWidget::mouseReleaseEvent(QMouseEvent * event)
{
    QPoint releasePos = event->pos();
    QPainterPath path;
    path.addEllipse(btnrect);

    if(path.contains(m_pressPos) && path.contains(releasePos))
    {
        if(TYPE == COLLSPSESTAUS::SYSTOLIC)
        {//当前状态是收缩，此时需要扩展
            displayAnimation();
            emit signal_btnClicked(COLLSPSESTAUS::EXPAND);
            TYPE = COLLSPSESTAUS::EXPAND;
        }else
        {
            startAnimation();
            emit signal_btnClicked(COLLSPSESTAUS::SYSTOLIC);
            TYPE = COLLSPSESTAUS::SYSTOLIC;
        }
    }
}

CollapseWidget::~CollapseWidget()
{
    delete ui;
}
