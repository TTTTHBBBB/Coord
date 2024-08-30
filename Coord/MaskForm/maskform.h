/*
 *遮罩功能
*/
#ifndef MASKFORM_H
#define MASKFORM_H

#include <QWidget>


class MaskForm : public QWidget
{
    Q_OBJECT
public:
    MaskForm(QWidget *parent = nullptr);
    ~MaskForm();

    void InstallWidget(QWidget *widget);//注册需要显示在遮罩中的窗口
    void setTopWidget(QWidget *widget);//设置顶层窗口
    void setMaskColor(const QColor &color,float opacuty);//设置遮罩的透明度和颜色

private:
    void init();
    virtual void showEvent(QShowEvent *event);
    virtual bool eventFilter(QObject *watched, QEvent *event);

private:
    QWidget *m_topWidget;    //顶层窗口，设置遮罩颜色、透明度
    QWidget *m_widget;       //遮罩中显示的窗口
};

#endif // MASKFORM_H
