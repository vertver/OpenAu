/********************************************************************************
** Form generated from reading UI file 'ExcDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXCDIALOG_H
#define UI_EXCDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_ExceptionDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QDialog *ExceptionDialog)
    {
        if (ExceptionDialog->objectName().isEmpty())
            ExceptionDialog->setObjectName(QStringLiteral("ExceptionDialog"));
        ExceptionDialog->resize(380, 277);
        buttonBox = new QDialogButtonBox(ExceptionDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(ExceptionDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 361, 16));
        label_2 = new QLabel(ExceptionDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 30, 351, 51));
        label_3 = new QLabel(ExceptionDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 80, 351, 81));

        retranslateUi(ExceptionDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ExceptionDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ExceptionDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ExceptionDialog);
    } // setupUi

    void retranslateUi(QDialog *ExceptionDialog)
    {
        ExceptionDialog->setWindowTitle(QApplication::translate("ExceptionDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("ExceptionDialog", "Please, press \"OK\" to accept exception or click \"Cancel\" to discard it.", nullptr));
        label_2->setText(QApplication::translate("ExceptionDialog", "Exception ", nullptr));
        label_3->setText(QApplication::translate("ExceptionDialog", "Description", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ExceptionDialog: public Ui_ExceptionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXCDIALOG_H
