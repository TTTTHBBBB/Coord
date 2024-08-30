/********************************************************************************
** Form generated from reading UI file 'chartfunctionframe.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHARTFUNCTIONFRAME_H
#define UI_CHARTFUNCTIONFRAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "ButtonEffect/glimmerbutton.h"
#include "ButtonEffect/glowbutton.h"

QT_BEGIN_NAMESPACE

class Ui_ChartFunctionFrame
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame_title;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QFrame *framework;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    GlimmerButton *btnbroken;
    GlimmerButton *btncurved;
    GlimmerButton *btncolumn;
    QHBoxLayout *horizontalLayout_4;
    GlimmerButton *btnscatter;
    GlimmerButton *btnheat;
    GlimmerButton *btnmotion;
    QHBoxLayout *horizontalLayout_3;
    GlowButton *btnzoom;
    QSpacerItem *verticalSpacer;
    QFrame *Coordframe;
    QVBoxLayout *verticalLayout_3;
    QLabel *Coordlabel;

    void setupUi(QWidget *ChartFunctionFrame)
    {
        if (ChartFunctionFrame->objectName().isEmpty())
            ChartFunctionFrame->setObjectName(QString::fromUtf8("ChartFunctionFrame"));
        ChartFunctionFrame->resize(319, 536);
        verticalLayout = new QVBoxLayout(ChartFunctionFrame);
        verticalLayout->setSpacing(10);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 5, 0, 5);
        frame_title = new QFrame(ChartFunctionFrame);
        frame_title->setObjectName(QString::fromUtf8("frame_title"));
        frame_title->setMinimumSize(QSize(0, 40));
        frame_title->setFrameShape(QFrame::StyledPanel);
        frame_title->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_title);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(frame_title);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(label);


        verticalLayout->addWidget(frame_title);

        framework = new QFrame(ChartFunctionFrame);
        framework->setObjectName(QString::fromUtf8("framework"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(framework->sizePolicy().hasHeightForWidth());
        framework->setSizePolicy(sizePolicy1);
        framework->setFrameShape(QFrame::StyledPanel);
        framework->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(framework);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, -1, -1, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btnbroken = new GlimmerButton(framework);
        btnbroken->setObjectName(QString::fromUtf8("btnbroken"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(btnbroken->sizePolicy().hasHeightForWidth());
        btnbroken->setSizePolicy(sizePolicy2);
        btnbroken->setMinimumSize(QSize(0, 60));
        btnbroken->setMaximumSize(QSize(16777215, 60));

        horizontalLayout->addWidget(btnbroken);

        btncurved = new GlimmerButton(framework);
        btncurved->setObjectName(QString::fromUtf8("btncurved"));
        sizePolicy2.setHeightForWidth(btncurved->sizePolicy().hasHeightForWidth());
        btncurved->setSizePolicy(sizePolicy2);
        btncurved->setMinimumSize(QSize(0, 60));
        btncurved->setMaximumSize(QSize(16777215, 60));

        horizontalLayout->addWidget(btncurved);

        btncolumn = new GlimmerButton(framework);
        btncolumn->setObjectName(QString::fromUtf8("btncolumn"));
        sizePolicy2.setHeightForWidth(btncolumn->sizePolicy().hasHeightForWidth());
        btncolumn->setSizePolicy(sizePolicy2);
        btncolumn->setMinimumSize(QSize(0, 60));
        btncolumn->setMaximumSize(QSize(16777215, 60));

        horizontalLayout->addWidget(btncolumn);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        btnscatter = new GlimmerButton(framework);
        btnscatter->setObjectName(QString::fromUtf8("btnscatter"));
        sizePolicy2.setHeightForWidth(btnscatter->sizePolicy().hasHeightForWidth());
        btnscatter->setSizePolicy(sizePolicy2);
        btnscatter->setMinimumSize(QSize(0, 60));
        btnscatter->setMaximumSize(QSize(16777215, 60));

        horizontalLayout_4->addWidget(btnscatter);

        btnheat = new GlimmerButton(framework);
        btnheat->setObjectName(QString::fromUtf8("btnheat"));
        sizePolicy2.setHeightForWidth(btnheat->sizePolicy().hasHeightForWidth());
        btnheat->setSizePolicy(sizePolicy2);
        btnheat->setMinimumSize(QSize(0, 60));
        btnheat->setMaximumSize(QSize(16777215, 60));

        horizontalLayout_4->addWidget(btnheat);

        btnmotion = new GlimmerButton(framework);
        btnmotion->setObjectName(QString::fromUtf8("btnmotion"));
        sizePolicy2.setHeightForWidth(btnmotion->sizePolicy().hasHeightForWidth());
        btnmotion->setSizePolicy(sizePolicy2);
        btnmotion->setMinimumSize(QSize(0, 60));
        btnmotion->setMaximumSize(QSize(16777215, 60));

        horizontalLayout_4->addWidget(btnmotion);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        btnzoom = new GlowButton(framework);
        btnzoom->setObjectName(QString::fromUtf8("btnzoom"));
        sizePolicy2.setHeightForWidth(btnzoom->sizePolicy().hasHeightForWidth());
        btnzoom->setSizePolicy(sizePolicy2);
        btnzoom->setMinimumSize(QSize(0, 60));
        btnzoom->setMaximumSize(QSize(16777215, 60));

        horizontalLayout_3->addWidget(btnzoom);


        verticalLayout_2->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        Coordframe = new QFrame(framework);
        Coordframe->setObjectName(QString::fromUtf8("Coordframe"));
        sizePolicy2.setHeightForWidth(Coordframe->sizePolicy().hasHeightForWidth());
        Coordframe->setSizePolicy(sizePolicy2);
        Coordframe->setFrameShape(QFrame::StyledPanel);
        Coordframe->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(Coordframe);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        Coordlabel = new QLabel(Coordframe);
        Coordlabel->setObjectName(QString::fromUtf8("Coordlabel"));

        verticalLayout_3->addWidget(Coordlabel);


        verticalLayout_2->addWidget(Coordframe);


        verticalLayout->addWidget(framework);


        retranslateUi(ChartFunctionFrame);

        QMetaObject::connectSlotsByName(ChartFunctionFrame);
    } // setupUi

    void retranslateUi(QWidget *ChartFunctionFrame)
    {
        ChartFunctionFrame->setWindowTitle(QCoreApplication::translate("ChartFunctionFrame", "Form", nullptr));
        label->setText(QString());
        btnbroken->setText(QString());
        btncurved->setText(QString());
        btncolumn->setText(QString());
        btnscatter->setText(QString());
        btnheat->setText(QString());
        btnmotion->setText(QString());
        btnzoom->setText(QString());
        Coordlabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ChartFunctionFrame: public Ui_ChartFunctionFrame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHARTFUNCTIONFRAME_H
