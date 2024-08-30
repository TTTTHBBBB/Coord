/********************************************************************************
** Form generated from reading UI file 'flickwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FLICKWINDOW_H
#define UI_FLICKWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FlickWindow
{
public:
    QHBoxLayout *horizontalLayout;
    QFrame *frameTitle;
    QFrame *frameText;
    QFrame *frameBtn;

    void setupUi(QWidget *FlickWindow)
    {
        if (FlickWindow->objectName().isEmpty())
            FlickWindow->setObjectName(QString::fromUtf8("FlickWindow"));
        FlickWindow->resize(907, 50);
        FlickWindow->setMinimumSize(QSize(150, 50));
        FlickWindow->setMaximumSize(QSize(16777215, 50));
        horizontalLayout = new QHBoxLayout(FlickWindow);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        frameTitle = new QFrame(FlickWindow);
        frameTitle->setObjectName(QString::fromUtf8("frameTitle"));
        frameTitle->setMinimumSize(QSize(50, 50));
        frameTitle->setMaximumSize(QSize(50, 50));
        frameTitle->setFrameShape(QFrame::StyledPanel);
        frameTitle->setFrameShadow(QFrame::Raised);

        horizontalLayout->addWidget(frameTitle);

        frameText = new QFrame(FlickWindow);
        frameText->setObjectName(QString::fromUtf8("frameText"));
        frameText->setFrameShape(QFrame::StyledPanel);
        frameText->setFrameShadow(QFrame::Raised);

        horizontalLayout->addWidget(frameText);

        frameBtn = new QFrame(FlickWindow);
        frameBtn->setObjectName(QString::fromUtf8("frameBtn"));
        frameBtn->setMinimumSize(QSize(50, 50));
        frameBtn->setMaximumSize(QSize(50, 50));
        frameBtn->setFrameShape(QFrame::StyledPanel);
        frameBtn->setFrameShadow(QFrame::Raised);

        horizontalLayout->addWidget(frameBtn);


        retranslateUi(FlickWindow);

        QMetaObject::connectSlotsByName(FlickWindow);
    } // setupUi

    void retranslateUi(QWidget *FlickWindow)
    {
        FlickWindow->setWindowTitle(QCoreApplication::translate("FlickWindow", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FlickWindow: public Ui_FlickWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FLICKWINDOW_H
