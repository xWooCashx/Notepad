/********************************************************************************
** Form generated from reading UI file 'tab.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAB_H
#define UI_TAB_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tab
{
public:
    QHBoxLayout *horizontalLayout;
    QPlainTextEdit *tekst;

    void setupUi(QWidget *Tab)
    {
        if (Tab->objectName().isEmpty())
            Tab->setObjectName(QStringLiteral("Tab"));
        Tab->resize(400, 300);
        horizontalLayout = new QHBoxLayout(Tab);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tekst = new QPlainTextEdit(Tab);
        tekst->setObjectName(QStringLiteral("tekst"));

        horizontalLayout->addWidget(tekst);


        retranslateUi(Tab);

        QMetaObject::connectSlotsByName(Tab);
    } // setupUi

    void retranslateUi(QWidget *Tab)
    {
        Tab->setWindowTitle(QApplication::translate("Tab", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tab: public Ui_Tab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAB_H
