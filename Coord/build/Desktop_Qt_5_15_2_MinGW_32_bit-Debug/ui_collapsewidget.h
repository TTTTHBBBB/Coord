/********************************************************************************
** Form generated from reading UI file 'collapsewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COLLAPSEWIDGET_H
#define UI_COLLAPSEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CollapseWidget
{
public:

    void setupUi(QWidget *CollapseWidget)
    {
        if (CollapseWidget->objectName().isEmpty())
            CollapseWidget->setObjectName(QString::fromUtf8("CollapseWidget"));
        CollapseWidget->resize(200, 351);

        retranslateUi(CollapseWidget);

        QMetaObject::connectSlotsByName(CollapseWidget);
    } // setupUi

    void retranslateUi(QWidget *CollapseWidget)
    {
        CollapseWidget->setWindowTitle(QCoreApplication::translate("CollapseWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CollapseWidget: public Ui_CollapseWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLLAPSEWIDGET_H
