/*
 * 语言切换窗口
*/

#ifndef LANGUAGESWITCH_H
#define LANGUAGESWITCH_H

#include <QMainWindow>

#include "globaldef.hpp"

#include "FlickWindow/flickwindow.h"
#include "render/bannacontrol.h"

namespace Ui {
class LanguageSwitch;
}

class LanguageSwitch : public QMainWindow
{
    Q_OBJECT

public:
    explicit LanguageSwitch(QWidget *parent = nullptr);
    ~LanguageSwitch();
    void InitLanguage();

public slots:
    void Slot_FlickWindow(FLICKTYPE TYPE);

private:
    virtual bool event(QEvent *event);
    FlickWindow * flickwindow = nullptr;

private:
    Ui::LanguageSwitch *ui;
};

#endif // LANGUAGESWITCH_H
