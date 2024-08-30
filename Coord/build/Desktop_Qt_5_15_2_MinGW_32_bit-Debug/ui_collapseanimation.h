/********************************************************************************
** Form generated from reading UI file 'collapseanimation.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COLLAPSEANIMATION_H
#define UI_COLLAPSEANIMATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QWidget>
#include "CoordData/functionbar.h"
#include "collapsewidget.h"

QT_BEGIN_NAMESPACE

class Ui_CollapseAnimation
{
public:
    QHBoxLayout *horizontalLayout;
    CollapseWidget *FrameAnimation;
    FunctionBar *widgetWork;

    void setupUi(QWidget *CollapseAnimation)
    {
        if (CollapseAnimation->objectName().isEmpty())
            CollapseAnimation->setObjectName(QString::fromUtf8("CollapseAnimation"));
        CollapseAnimation->resize(253, 619);
        CollapseAnimation->setMaximumSize(QSize(16777215, 16777215));
        horizontalLayout = new QHBoxLayout(CollapseAnimation);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        FrameAnimation = new CollapseWidget(CollapseAnimation);
        FrameAnimation->setObjectName(QString::fromUtf8("FrameAnimation"));
        FrameAnimation->setMinimumSize(QSize(40, 0));
        FrameAnimation->setMaximumSize(QSize(50, 16777215));
        FrameAnimation->setStyleSheet(QString::fromUtf8(""));
        FrameAnimation->setFrameShape(QFrame::StyledPanel);
        FrameAnimation->setFrameShadow(QFrame::Raised);
        FrameAnimation->setLineWidth(1);

        horizontalLayout->addWidget(FrameAnimation);

        widgetWork = new FunctionBar(CollapseAnimation);
        widgetWork->setObjectName(QString::fromUtf8("widgetWork"));
        widgetWork->setFrameShape(QFrame::StyledPanel);
        widgetWork->setFrameShadow(QFrame::Raised);

        horizontalLayout->addWidget(widgetWork);


        retranslateUi(CollapseAnimation);

        QMetaObject::connectSlotsByName(CollapseAnimation);
    } // setupUi

    void retranslateUi(QWidget *CollapseAnimation)
    {
        CollapseAnimation->setWindowTitle(QCoreApplication::translate("CollapseAnimation", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CollapseAnimation: public Ui_CollapseAnimation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLLAPSEANIMATION_H
