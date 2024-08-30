/********************************************************************************
** Form generated from reading UI file 'fileframe.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEFRAME_H
#define UI_FILEFRAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "ButtonEffect/glimmerbutton.h"
#include "CoordData/coordtreewidget.h"

QT_BEGIN_NAMESPACE

class Ui_FileFrame
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frametitle;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelTitle;
    CoordTreeWidget *frameobject;
    QVBoxLayout *verticalLayout_2;
    QFrame *framebtn;
    QHBoxLayout *horizontalLayout;
    GlimmerButton *pushButtonOpen;
    QSpacerItem *horizontalSpacer;
    GlimmerButton *pushButtonExpor;

    void setupUi(QWidget *FileFrame)
    {
        if (FileFrame->objectName().isEmpty())
            FileFrame->setObjectName(QString::fromUtf8("FileFrame"));
        FileFrame->resize(421, 615);
        verticalLayout = new QVBoxLayout(FileFrame);
        verticalLayout->setSpacing(10);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 5, 0, 0);
        frametitle = new QFrame(FileFrame);
        frametitle->setObjectName(QString::fromUtf8("frametitle"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frametitle->sizePolicy().hasHeightForWidth());
        frametitle->setSizePolicy(sizePolicy);
        frametitle->setMinimumSize(QSize(0, 40));
        frametitle->setFrameShape(QFrame::StyledPanel);
        frametitle->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frametitle);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        labelTitle = new QLabel(frametitle);
        labelTitle->setObjectName(QString::fromUtf8("labelTitle"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(labelTitle->sizePolicy().hasHeightForWidth());
        labelTitle->setSizePolicy(sizePolicy1);
        labelTitle->setMinimumSize(QSize(80, 0));

        horizontalLayout_2->addWidget(labelTitle);


        verticalLayout->addWidget(frametitle);

        frameobject = new CoordTreeWidget(FileFrame);
        frameobject->setObjectName(QString::fromUtf8("frameobject"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(frameobject->sizePolicy().hasHeightForWidth());
        frameobject->setSizePolicy(sizePolicy2);
        frameobject->setFrameShape(QFrame::StyledPanel);
        frameobject->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frameobject);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);

        verticalLayout->addWidget(frameobject);

        framebtn = new QFrame(FileFrame);
        framebtn->setObjectName(QString::fromUtf8("framebtn"));
        framebtn->setFrameShape(QFrame::StyledPanel);
        framebtn->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(framebtn);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(11, 11, -1, -1);
        pushButtonOpen = new GlimmerButton(framebtn);
        pushButtonOpen->setObjectName(QString::fromUtf8("pushButtonOpen"));
        pushButtonOpen->setMinimumSize(QSize(100, 60));

        horizontalLayout->addWidget(pushButtonOpen);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButtonExpor = new GlimmerButton(framebtn);
        pushButtonExpor->setObjectName(QString::fromUtf8("pushButtonExpor"));
        pushButtonExpor->setMinimumSize(QSize(100, 60));

        horizontalLayout->addWidget(pushButtonExpor);


        verticalLayout->addWidget(framebtn);


        retranslateUi(FileFrame);

        QMetaObject::connectSlotsByName(FileFrame);
    } // setupUi

    void retranslateUi(QWidget *FileFrame)
    {
        FileFrame->setWindowTitle(QCoreApplication::translate("FileFrame", "Form", nullptr));
        labelTitle->setText(QString());
        pushButtonOpen->setText(QString());
        pushButtonExpor->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FileFrame: public Ui_FileFrame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEFRAME_H
