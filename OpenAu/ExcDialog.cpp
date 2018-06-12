/////////////////////////////////
// VERTVER, 2018 (C)
// OpenAu, Open Audio Utility
// MIT-License
/////////////////////////////////
// EcxDialog.cpp:
// Exception Dialog
/////////////////////////////////

#include "ExcDialog.h"
#include "ui_ExcDialog.h"

ExceptionDialog::ExceptionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExceptionDialog)
{
    ui->setupUi(this);
}

ExceptionDialog::~ExceptionDialog()
{
    delete ui;
}

void ExceptionDialog::on_buttonBox_accepted()
{

}

void ExceptionDialog::setTextToLabels(std::string sz1, std::string sz2)
{
	Ui::ExceptionDialog* ui;
	ui->label_2->setText(sz1.c_str());
	ui->label_3->setText(sz2.c_str());
}
