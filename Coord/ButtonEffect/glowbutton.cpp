#include <QPainter>
#include <QPainterPath>

#include "glowbutton.h"

GlowButton::GlowButton(QWidget *parent)
    : CoordBtnBase(parent)
{
    this->CoordBtnInit();
}

void GlowButton::CoordBtnInit()
{
    this->installEventFilter(this);
    connect(&animTimer, &QTimer::timeout, this, &GlowButton::updateAnimation);
    animTimer.start(15);
    offset = 0;
}

void GlowButton::setIiterals(QPainter &painter)
{
    if(matchtext.isEmpty()) return ;
    painter.save();
    QPainterPath path;
    path.addRoundedRect(this->borderRect(), borderRadius, borderRadius);
    painter.setClipPath(path);
    painter.setPen(fontColor);

    drawText(this->rect(),painter,PressorReless,matchtext);
    painter.restore();
}

QRect GlowButton::borderRect() const
{
    int btn_x = borderWidth;
    int btn_y = borderWidth;
    int btn_width = width() - borderWidth * 2;
    int btn_height = height() - borderWidth * 2;

    return QRect(btn_x, btn_y, btn_width, btn_height);
}

void GlowButton::drawForeground(QPainter &painter)
{
    painter.save();
    pixmap = getForegroundPixmap();

    QRect leftRect(0, 0, width() - offset, height());
    QRect rightRect(width() - offset, 0, offset, height());

    QPixmap leftPixmap = pixmap.copy(leftRect);
    QPixmap rightPixmap = pixmap.copy(rightRect);

    painter.drawPixmap(0, 0, rightPixmap);
    painter.drawPixmap(offset, 0, leftPixmap);
    painter.restore();
}

QPixmap GlowButton::getForegroundPixmap() const
{//绘制渐变色背景，背景是透明的，后续的绘制会覆盖整个背景只留下预先设置的边框
    QPixmap pixmap(this->width(), this->height());
    pixmap.fill(Qt::transparent);

    QPainter painter(&pixmap);
    painter.setPen(Qt::NoPen);
    painter.setRenderHint(QPainter::Antialiasing);

    QLinearGradient gradient(0, 0,this->width(), 0);
    gradient.setColorAt(0, QColor(0, 164, 128, 230));
    gradient.setColorAt(0.166, QColor(13, 88, 166, 230));
    gradient.setColorAt(0.333, QColor(118, 8, 170, 230));
    gradient.setColorAt(0.5, QColor(255, 144, 0, 230));
    gradient.setColorAt(0.666, QColor(255, 255, 0, 230));
    gradient.setColorAt(0.833, QColor(165, 239, 0, 230));
    gradient.setColorAt(1, QColor(83, 223, 0, 230));

    painter.setBrush(gradient);
    painter.drawRect(0, 0, width(), height());

    painter.end();
    return pixmap;
}

void GlowButton::animForwardRun()
{
    animTimer.start();
}

void GlowButton::updateAnimation()
{
    if (animTimer.isActive()) {
        offset += 2;
        if (offset > width()) {
            offset = 0;
        }
        update();
    }
}

void GlowButton::showEvent(QShowEvent *event)
{
    QPushButton::showEvent(event);
    animTimer.start();
}

bool GlowButton::eventFilter(QObject *watched, QEvent *event)
{
    switch (event->type())
    {
        case QEvent::Enter:
        {
            animTimer.start();
            break;
        }
        case QEvent::Leave:
        {
            animTimer.stop();
            break;
        }
        case QEvent::MouseButtonPress:
        {
            PressorReless = FEEDBACK::PRESS;
            update();
            break;
        }
        case QEvent::MouseButtonRelease:
        {
            PressorReless = FEEDBACK::RELESS;
            update();
            break;
        }
        default:
            break;
    }
    return QObject::eventFilter(watched, event);
}

void GlowButton::setParams(int border_radius, int border_width, const QColor &font_color)
{
    this->borderRadius = border_radius;
    this->borderWidth = border_width;
    this->fontColor = font_color;
}

void GlowButton::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
    this->update();
}

void GlowButton::paintEvent(QPaintEvent *event)
{
    QPushButton::paintEvent(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QPainterPath path;
    path.addRoundedRect(this->borderRect(), borderRadius, borderRadius);
    path.addRoundedRect(0, 0, this->width(), this->height(), borderRadius, borderRadius);
    painter.setClipPath(path);

    if(this->width()<=10||this->height()<=10) return ;

    drawForeground(painter);
    setIiterals(painter);
}
