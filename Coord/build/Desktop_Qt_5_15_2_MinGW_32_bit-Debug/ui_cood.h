/********************************************************************************
** Form generated from reading UI file 'cood.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COOD_H
#define UI_COOD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "CoordTab/mytabwidget.h"
#include "collapseanimation.h"
#include "maintitlebar.h"

QT_BEGIN_NAMESPACE

class Ui_Cood
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QFrame *shadeframe;
    QVBoxLayout *verticalLayout;
    MainTitleBar *widgetTitle;
    QHBoxLayout *horizontalLayout;
    CollapseAnimation *CollapseFrame;
    QSplitter *splitter;
    MyTabWidget *Tabwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Cood)
    {
        if (Cood->objectName().isEmpty())
            Cood->setObjectName(QString::fromUtf8("Cood"));
        Cood->resize(980, 607);
        centralwidget = new QWidget(Cood);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setSpacing(5);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(5, 5, 5, 5);
        shadeframe = new QFrame(centralwidget);
        shadeframe->setObjectName(QString::fromUtf8("shadeframe"));
        shadeframe->setFrameShape(QFrame::StyledPanel);
        shadeframe->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(shadeframe);
        verticalLayout->setSpacing(5);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widgetTitle = new MainTitleBar(shadeframe);
        widgetTitle->setObjectName(QString::fromUtf8("widgetTitle"));
        widgetTitle->setMinimumSize(QSize(0, 60));

        verticalLayout->addWidget(widgetTitle);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(5);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, 5, 5);
        CollapseFrame = new CollapseAnimation(shadeframe);
        CollapseFrame->setObjectName(QString::fromUtf8("CollapseFrame"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CollapseFrame->sizePolicy().hasHeightForWidth());
        CollapseFrame->setSizePolicy(sizePolicy);
        CollapseFrame->setMinimumSize(QSize(40, 500));
        CollapseFrame->setMaximumSize(QSize(350, 16777215));
        CollapseFrame->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        CollapseFrame->setFrameShape(QFrame::StyledPanel);
        CollapseFrame->setFrameShadow(QFrame::Raised);
        CollapseFrame->setLineWidth(0);

        horizontalLayout->addWidget(CollapseFrame);

        splitter = new QSplitter(shadeframe);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Vertical);
        Tabwidget = new MyTabWidget(splitter);
        Tabwidget->setObjectName(QString::fromUtf8("Tabwidget"));
        Tabwidget->setMinimumSize(QSize(900, 100));
        splitter->addWidget(Tabwidget);

        horizontalLayout->addWidget(splitter);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_2->addWidget(shadeframe);

        Cood->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(Cood);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Cood->setStatusBar(statusbar);

        retranslateUi(Cood);

        QMetaObject::connectSlotsByName(Cood);
    } // setupUi

    void retranslateUi(QMainWindow *Cood)
    {
        Cood->setWindowTitle(QCoreApplication::translate("Cood", "Cood", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Cood: public Ui_Cood {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COOD_H
