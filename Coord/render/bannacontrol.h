/*
 * 动态多语音切换功能
 * 包括轮播图
*/

#ifndef BANNACONTROL_H
#define BANNACONTROL_H

#include <QWidget>
#include <QPushButton>
#include <QParallelAnimationGroup>
#include <QPropertyAnimation>
#include <QButtonGroup>
#include <QLabel>
#include <QTimer>

#include "globaldef.hpp"
#include "globalapplication.h"

namespace Ui {
class BannaControl;
}

namespace BannaSpace
{
const int INTERVAL_TIMER = 3000;
const int ANIMATION_DURTION = 200;
const QByteArray ANIMATION_GEOMETRY = "geometry";
const QString STYLE_SHEET = "border-image:url(%1)";
const QString FIRST_IMAGE_PATH = ":/images/country/Jap.jpg";
const QString SECOND_IMAGE_PATH = ":/images/country/hindi-flag.png";
const QString THIRD_IMAGE_PATH = ":/images/country/Chinese.jpg";
const QString FOURTH_IMAGE_PATH = ":/images/country/english-flag.png";
const QString FIFTH_IMAGE_PATH = ":/images/country/french-flag.png";

enum SortWidget
{
    SORT_FIRST,
    SORT_SECOND,
    SORT_THIRD,
    SORT_FOURTH,
    SORT_FIFTH,
};

}

// 使用双向链表思想
typedef struct BannaData
{
    QPushButton *pushButton;
    QLabel *currentImageLabel;
    QLabel *nextImageLabel;
    QLabel *preImageLabel;
    QPropertyAnimation *proAnimation;
    QString LanguageType = "";

} BannaData;

class BannaControl : public QWidget
{
    Q_OBJECT

public:
    explicit BannaControl(QWidget *parent = 0);
    ~BannaControl();
private slots:
    void Slot_changeImageTimer();
    void Slot_pushButtonLeft();
    void Slot_pushButtonRight();

private:
    void initValue();
    void setNextAnimation();
    void setPreAnimation();
    int getMaxGeometryIndex(const QList<BannaData> &listData);
    void sortGeometry(const bool &isNextFlage);
    void addAnimationPixmap(QList<QString> &listPixmap);
    int getCenterGeometryIndex();

    virtual bool eventFilter(QObject *watched, QEvent *event);

signals:
    void Signal_LanguageChange(FLICKTYPE TYPE = FLICKTYPE::FAILD);//弹窗提示

private:
    Ui::BannaControl *ui;
    QTimer *changeImageTimer = nullptr;
    QList<BannaData> bannaDataList;
    QButtonGroup buttonGroup;
    QParallelAnimationGroup animationGroup;

};

#endif // BANNACONTROL_H
