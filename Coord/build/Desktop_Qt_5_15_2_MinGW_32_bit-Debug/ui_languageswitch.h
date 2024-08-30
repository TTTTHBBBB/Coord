/********************************************************************************
** Form generated from reading UI file 'languageswitch.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LANGUAGESWITCH_H
#define UI_LANGUAGESWITCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "maintitlebar.h"
#include "render/bannacontrol.h"

QT_BEGIN_NAMESPACE

class Ui_LanguageSwitch
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QFrame *frameBackground;
    QVBoxLayout *verticalLayout_2;
    MainTitleBar *widgetTitle;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    BannaControl *widget;
    QSpacerItem *horizontalSpacer_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LanguageSwitch)
    {
        if (LanguageSwitch->objectName().isEmpty())
            LanguageSwitch->setObjectName(QString::fromUtf8("LanguageSwitch"));
        LanguageSwitch->resize(991, 470);
        LanguageSwitch->setMinimumSize(QSize(0, 0));
        LanguageSwitch->setMaximumSize(QSize(16777215, 470));
        centralwidget = new QWidget(LanguageSwitch);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        frameBackground = new QFrame(centralwidget);
        frameBackground->setObjectName(QString::fromUtf8("frameBackground"));
        frameBackground->setFrameShape(QFrame::StyledPanel);
        frameBackground->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frameBackground);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widgetTitle = new MainTitleBar(frameBackground);
        widgetTitle->setObjectName(QString::fromUtf8("widgetTitle"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widgetTitle->sizePolicy().hasHeightForWidth());
        widgetTitle->setSizePolicy(sizePolicy);
        widgetTitle->setMinimumSize(QSize(0, 0));
        widgetTitle->setMaximumSize(QSize(16777215, 70));

        verticalLayout_2->addWidget(widgetTitle);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        widget = new BannaControl(frameBackground);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(800, 410));
        widget->setMaximumSize(QSize(800, 410));

        horizontalLayout->addWidget(widget);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout);


        verticalLayout->addWidget(frameBackground);

        LanguageSwitch->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(LanguageSwitch);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        LanguageSwitch->setStatusBar(statusbar);

        retranslateUi(LanguageSwitch);

        QMetaObject::connectSlotsByName(LanguageSwitch);
    } // setupUi

    void retranslateUi(QMainWindow *LanguageSwitch)
    {
        LanguageSwitch->setWindowTitle(QCoreApplication::translate("LanguageSwitch", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LanguageSwitch: public Ui_LanguageSwitch {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LANGUAGESWITCH_H
