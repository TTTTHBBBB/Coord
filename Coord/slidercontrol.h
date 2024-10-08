/*
 * 移动进度,控制轮播动画
*/
#ifndef SLIDERCONTROL_H
#define SLIDERCONTROL_H

#include <QWidget>
#include <QPainter>
#include <QLabel>
#include <QMap>

class NumberAnimation;

namespace Ui {
class SliderControl;
}

class SliderControl : public QWidget
{
    Q_OBJECT

public:
    explicit SliderControl(QWidget *parent = nullptr);
    ~SliderControl() override;

private slots:
    void SlotpushButtonLeft();
    void SlotpushButtonRight();

private:
    Ui::SliderControl *ui;
    int m_currentIndex;
    double m_currentLineWidth;
    NumberAnimation *m_numberAnimation = nullptr;
    QMap<int, QLabel*> m_labelPointMap;
private:
    void initValue();
    void drawEvent();
    void setupSelectCircle();
    void calculateLineWidth();
    void collectCentPoint();
    bool eventFilter(QObject *watched, QEvent *event) override;
private:
    const int LABEL_NUMBER = 5;//移动点的数量
    const int MIDDLE_LABLE = 2;
    const int EACH_LABEL_ANGEL = 30;
    const QColor LINEAR_COLOR = QColor(147, 212, 233, 0);
    const QColor PROGRESS_COLOR = QColor(2, 218, 227);
    const QString SMALL_GRAY_CIRCLE_PATH = ":/images/other/normal_gray.png";
    const QString SMALL_BLUE_CIRCLE_PATH = ":/images/other/hover_blue.png";
    const QString CENTER_CYAN_CIRCLE_PATH = ":/images/other/center_cyan.png";
};
#endif // SLIDERCONTROL_H
