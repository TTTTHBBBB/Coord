/********************************************************************************
** Form generated from reading UI file 'functionbar.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FUNCTIONBAR_H
#define UI_FUNCTIONBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "ButtonEffect/normalbutton.h"
#include "CoordData/chartfunctionframe.h"
#include "CoordData/fileframe.h"

QT_BEGIN_NAMESPACE

class Ui_FunctionBar
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    NormalButton *pushButtonChart;
    NormalButton *pushButtonFile;
    NormalButton *pushButtonColor;
    QSpacerItem *horizontalSpacer;
    QStackedWidget *stackedWidget;
    ChartFunctionFrame *chartwidget;
    FileFrame *filewidget;

    void setupUi(QWidget *FunctionBar)
    {
        if (FunctionBar->objectName().isEmpty())
            FunctionBar->setObjectName(QString::fromUtf8("FunctionBar"));
        FunctionBar->resize(379, 540);
        verticalLayout = new QVBoxLayout(FunctionBar);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButtonChart = new NormalButton(FunctionBar);
        pushButtonChart->setObjectName(QString::fromUtf8("pushButtonChart"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButtonChart->sizePolicy().hasHeightForWidth());
        pushButtonChart->setSizePolicy(sizePolicy);
        pushButtonChart->setMinimumSize(QSize(70, 35));

        horizontalLayout->addWidget(pushButtonChart);

        pushButtonFile = new NormalButton(FunctionBar);
        pushButtonFile->setObjectName(QString::fromUtf8("pushButtonFile"));
        sizePolicy.setHeightForWidth(pushButtonFile->sizePolicy().hasHeightForWidth());
        pushButtonFile->setSizePolicy(sizePolicy);
        pushButtonFile->setMinimumSize(QSize(70, 35));

        horizontalLayout->addWidget(pushButtonFile);

        pushButtonColor = new NormalButton(FunctionBar);
        pushButtonColor->setObjectName(QString::fromUtf8("pushButtonColor"));
        sizePolicy.setHeightForWidth(pushButtonColor->sizePolicy().hasHeightForWidth());
        pushButtonColor->setSizePolicy(sizePolicy);
        pushButtonColor->setMinimumSize(QSize(70, 35));

        horizontalLayout->addWidget(pushButtonColor);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        stackedWidget = new QStackedWidget(FunctionBar);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy1);
        chartwidget = new ChartFunctionFrame();
        chartwidget->setObjectName(QString::fromUtf8("chartwidget"));
        stackedWidget->addWidget(chartwidget);
        filewidget = new FileFrame();
        filewidget->setObjectName(QString::fromUtf8("filewidget"));
        stackedWidget->addWidget(filewidget);

        verticalLayout->addWidget(stackedWidget);


        retranslateUi(FunctionBar);

        QMetaObject::connectSlotsByName(FunctionBar);
    } // setupUi

    void retranslateUi(QWidget *FunctionBar)
    {
        FunctionBar->setWindowTitle(QCoreApplication::translate("FunctionBar", "Form", nullptr));
        pushButtonChart->setText(QString());
        pushButtonFile->setText(QString());
        pushButtonColor->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FunctionBar: public Ui_FunctionBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FUNCTIONBAR_H
