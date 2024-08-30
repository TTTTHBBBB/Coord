#include <QApplication>
#include <QDebug>

#include "maskform.h"

MaskForm::MaskForm(QWidget *parent)
    : QWidget(parent)
    ,m_topWidget(nullptr)
    ,m_widget(nullptr)
{
    init();
}

MaskForm::~MaskForm()
{

}

void MaskForm::InstallWidget(QWidget *widget)
{
    if(widget == nullptr)
    {
        return;
    }
    //监控显示窗口事件
    widget->installEventFilter(this);
    m_widget = widget;

    connect(m_widget, &QWidget::destroyed, this, [=](){
        m_widget = nullptr;});
}

void MaskForm::setMaskColor(const QColor &color, float opacity)
{
    if(!color.isValid())
    {
        return;
    }

    QPalette palette = this->palette();
    //通常指窗口部件的背景色
    palette.setColor(QPalette::Window,color);
    this->setPalette(palette);

    setWindowOpacity(opacity);
}

void MaskForm::setTopWidget(QWidget *widget)
{
    //设置遮罩父窗口
    if(widget == nullptr)
    {
        return;
    }
    m_topWidget = widget;
}

void MaskForm::init()
{
    installEventFilter(this);
    setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);
    setMaskColor(QColor(0,0,0),0.6f);

    //1.返回具有键盘输入焦点的顶级窗口,如果没有应用程序窗口具有焦点，则返回0.
    //2.但是即使没有焦点，也可能有一个活动窗口。例如一个窗口没有小部件接收关键事件。
    m_topWidget = QApplication::activeWindow();
}

void MaskForm::showEvent(QShowEvent *event)
{
    Q_UNUSED(event);
    //确定显示的位置
    this->setGeometry(m_topWidget->geometry());
}

bool MaskForm::eventFilter(QObject *watched, QEvent *event)
{
    if(watched == m_widget)
    {
        if(event->type() == QEvent::Show)
        {
            this->show();
        }

        if(event->type() == QEvent::Hide)
        {
            this->hide();
        }
    }
    if(watched == this)
    {
        if(event->type() == QEvent::MouseButtonPress
            || event->type() == QEvent::MouseButtonRelease )
        {
            m_widget->raise();
        }
    }
    return QObject::eventFilter(watched, event);
}

