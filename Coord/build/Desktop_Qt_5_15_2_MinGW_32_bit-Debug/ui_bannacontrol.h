/********************************************************************************
** Form generated from reading UI file 'bannacontrol.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BANNACONTROL_H
#define UI_BANNACONTROL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BannaControl
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QLabel *labelFirst;
    QLabel *labelSecond;
    QLabel *labelFourth;
    QLabel *labelFifth;
    QLabel *labelThird;
    QPushButton *pushButtonLeft;
    QPushButton *pushButtonRight;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonFirst;
    QPushButton *pushButtonSecond;
    QPushButton *pushButtonThird;
    QPushButton *pushButtonFourth;
    QPushButton *pushButtonFifth;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *BannaControl)
    {
        if (BannaControl->objectName().isEmpty())
            BannaControl->setObjectName(QString::fromUtf8("BannaControl"));
        BannaControl->resize(800, 410);
        BannaControl->setMinimumSize(QSize(800, 410));
        BannaControl->setMaximumSize(QSize(800, 410));
        verticalLayout = new QVBoxLayout(BannaControl);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(BannaControl);
        widget->setObjectName(QString::fromUtf8("widget"));
        labelFirst = new QLabel(widget);
        labelFirst->setObjectName(QString::fromUtf8("labelFirst"));
        labelFirst->setGeometry(QRect(20, 100, 320, 200));
        labelSecond = new QLabel(widget);
        labelSecond->setObjectName(QString::fromUtf8("labelSecond"));
        labelSecond->setGeometry(QRect(70, 70, 400, 250));
        labelFourth = new QLabel(widget);
        labelFourth->setObjectName(QString::fromUtf8("labelFourth"));
        labelFourth->setGeometry(QRect(330, 70, 400, 250));
        labelFifth = new QLabel(widget);
        labelFifth->setObjectName(QString::fromUtf8("labelFifth"));
        labelFifth->setGeometry(QRect(470, 100, 320, 200));
        labelThird = new QLabel(widget);
        labelThird->setObjectName(QString::fromUtf8("labelThird"));
        labelThird->setGeometry(QRect(150, 50, 480, 300));
        pushButtonLeft = new QPushButton(widget);
        pushButtonLeft->setObjectName(QString::fromUtf8("pushButtonLeft"));
        pushButtonLeft->setGeometry(QRect(20, 180, 48, 48));
        pushButtonRight = new QPushButton(widget);
        pushButtonRight->setObjectName(QString::fromUtf8("pushButtonRight"));
        pushButtonRight->setGeometry(QRect(740, 180, 48, 48));

        verticalLayout->addWidget(widget);

        frame = new QFrame(BannaControl);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMinimumSize(QSize(0, 60));
        frame->setMaximumSize(QSize(16777215, 60));
        frame->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border-image: url(:/images/other/normal_gray.png);\n"
"}\n"
"\n"
"QPushButton:checked\n"
"{\n"
"border-image: url(:/images/other/hover_blue.png);\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButtonFirst = new QPushButton(frame);
        pushButtonFirst->setObjectName(QString::fromUtf8("pushButtonFirst"));
        pushButtonFirst->setMinimumSize(QSize(20, 20));
        pushButtonFirst->setMaximumSize(QSize(20, 20));
        pushButtonFirst->setCheckable(true);

        horizontalLayout->addWidget(pushButtonFirst);

        pushButtonSecond = new QPushButton(frame);
        pushButtonSecond->setObjectName(QString::fromUtf8("pushButtonSecond"));
        pushButtonSecond->setMinimumSize(QSize(20, 20));
        pushButtonSecond->setMaximumSize(QSize(20, 20));
        pushButtonSecond->setCheckable(true);

        horizontalLayout->addWidget(pushButtonSecond);

        pushButtonThird = new QPushButton(frame);
        pushButtonThird->setObjectName(QString::fromUtf8("pushButtonThird"));
        pushButtonThird->setMinimumSize(QSize(20, 20));
        pushButtonThird->setMaximumSize(QSize(20, 20));
        pushButtonThird->setCheckable(true);
        pushButtonThird->setChecked(true);

        horizontalLayout->addWidget(pushButtonThird);

        pushButtonFourth = new QPushButton(frame);
        pushButtonFourth->setObjectName(QString::fromUtf8("pushButtonFourth"));
        pushButtonFourth->setMinimumSize(QSize(20, 20));
        pushButtonFourth->setMaximumSize(QSize(20, 20));
        pushButtonFourth->setCheckable(true);

        horizontalLayout->addWidget(pushButtonFourth);

        pushButtonFifth = new QPushButton(frame);
        pushButtonFifth->setObjectName(QString::fromUtf8("pushButtonFifth"));
        pushButtonFifth->setMinimumSize(QSize(20, 20));
        pushButtonFifth->setMaximumSize(QSize(20, 20));
        pushButtonFifth->setCheckable(true);

        horizontalLayout->addWidget(pushButtonFifth);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(frame);


        retranslateUi(BannaControl);

        QMetaObject::connectSlotsByName(BannaControl);
    } // setupUi

    void retranslateUi(QWidget *BannaControl)
    {
        BannaControl->setWindowTitle(QCoreApplication::translate("BannaControl", "Form", nullptr));
        labelFirst->setText(QString());
        labelSecond->setText(QString());
        labelFourth->setText(QString());
        labelFifth->setText(QString());
        labelThird->setText(QString());
        pushButtonLeft->setText(QString());
        pushButtonRight->setText(QString());
        pushButtonFirst->setText(QString());
        pushButtonSecond->setText(QString());
        pushButtonThird->setText(QString());
        pushButtonFourth->setText(QString());
        pushButtonFifth->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class BannaControl: public Ui_BannaControl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BANNACONTROL_H
