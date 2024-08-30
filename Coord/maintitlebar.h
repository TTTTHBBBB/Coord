/*
 * 主标题栏，内含有窗体最大化，最小化，关闭
 * 以及窗口的Title，以及名称
*/
#ifndef MAINTITLEBAR_H
#define MAINTITLEBAR_H

#include <QMainWindow>
#include <QWidget>

#include "titlebar.h"
#include "MaskForm/maskform.h"
#include "render/languageswitch.h"

namespace Ui {
class MainTitleBar;
}

class MainTitleBar : public TitleBar
{
    Q_OBJECT

public:
    explicit MainTitleBar(QWidget *parent = nullptr);
    ~MainTitleBar();
    void InitTitle();
    void setCoordTitle();//适配主窗口

private slots:
    void Slot_pushButtonClose();
    void Slot_pushButtonMin();
    void Slot_pushButtonNormalMax();
    void Slot_Language();//语言切换

private:
    MaskForm *MaskWidget = nullptr ;
    LanguageSwitch  *LanguageWindow = nullptr;

private:
    Ui::MainTitleBar *ui;

};

#endif // MAINTITLEBAR_H
