/********************************************************************************
** Form generated from reading UI file 'maintitlebar.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINTITLEBAR_H
#define UI_MAINTITLEBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainTitleBar
{
public:
    QHBoxLayout *horizontalLayout_2;
    QFrame *frameBorder;
    QHBoxLayout *horizontalLayout;
    QLabel *labelTitleName;
    QPushButton *pushButtonLanguage;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonMin;
    QPushButton *pushButtonNormalMax;
    QPushButton *pushButtonClose;

    void setupUi(QWidget *MainTitleBar)
    {
        if (MainTitleBar->objectName().isEmpty())
            MainTitleBar->setObjectName(QString::fromUtf8("MainTitleBar"));
        MainTitleBar->resize(658, 50);
        horizontalLayout_2 = new QHBoxLayout(MainTitleBar);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        frameBorder = new QFrame(MainTitleBar);
        frameBorder->setObjectName(QString::fromUtf8("frameBorder"));
        frameBorder->setFrameShape(QFrame::StyledPanel);
        frameBorder->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frameBorder);
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(9, 9, 9, 9);
        labelTitleName = new QLabel(frameBorder);
        labelTitleName->setObjectName(QString::fromUtf8("labelTitleName"));
        labelTitleName->setMinimumSize(QSize(85, 25));
        labelTitleName->setMaximumSize(QSize(85, 25));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(11);
        font.setBold(true);
        labelTitleName->setFont(font);
        labelTitleName->setPixmap(QPixmap(QString::fromUtf8(":/images/title/Log-white.png")));
        labelTitleName->setScaledContents(true);

        horizontalLayout->addWidget(labelTitleName);

        pushButtonLanguage = new QPushButton(frameBorder);
        pushButtonLanguage->setObjectName(QString::fromUtf8("pushButtonLanguage"));
        pushButtonLanguage->setMinimumSize(QSize(20, 20));
        pushButtonLanguage->setMaximumSize(QSize(20, 20));

        horizontalLayout->addWidget(pushButtonLanguage);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButtonMin = new QPushButton(frameBorder);
        pushButtonMin->setObjectName(QString::fromUtf8("pushButtonMin"));
        pushButtonMin->setMinimumSize(QSize(20, 20));
        pushButtonMin->setMaximumSize(QSize(20, 20));

        horizontalLayout->addWidget(pushButtonMin);

        pushButtonNormalMax = new QPushButton(frameBorder);
        pushButtonNormalMax->setObjectName(QString::fromUtf8("pushButtonNormalMax"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButtonNormalMax->sizePolicy().hasHeightForWidth());
        pushButtonNormalMax->setSizePolicy(sizePolicy);
        pushButtonNormalMax->setMinimumSize(QSize(20, 20));
        pushButtonNormalMax->setMaximumSize(QSize(20, 20));

        horizontalLayout->addWidget(pushButtonNormalMax);

        pushButtonClose = new QPushButton(frameBorder);
        pushButtonClose->setObjectName(QString::fromUtf8("pushButtonClose"));
        pushButtonClose->setMinimumSize(QSize(20, 20));
        pushButtonClose->setMaximumSize(QSize(20, 20));

        horizontalLayout->addWidget(pushButtonClose);


        horizontalLayout_2->addWidget(frameBorder);


        retranslateUi(MainTitleBar);

        QMetaObject::connectSlotsByName(MainTitleBar);
    } // setupUi

    void retranslateUi(QWidget *MainTitleBar)
    {
        MainTitleBar->setWindowTitle(QCoreApplication::translate("MainTitleBar", "Form", nullptr));
        labelTitleName->setText(QString());
        pushButtonLanguage->setText(QString());
        pushButtonMin->setText(QString());
        pushButtonNormalMax->setText(QString());
        pushButtonClose->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainTitleBar: public Ui_MainTitleBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINTITLEBAR_H
