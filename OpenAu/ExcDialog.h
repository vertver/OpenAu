/////////////////////////////////
// VERTVER, 2018 (C)
// OpenAu, Open Audio Utility
// MIT-License
/////////////////////////////////
// EcxDialog.h:
// Exception Dialog
/////////////////////////////////

#ifndef EXCXDIALOG_H
#define EXCXDIALOG_H

#include <QDialog>

namespace Ui 
{
class ExceptionDialog;
}

class ExceptionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ExceptionDialog(QWidget *parent = 0);
    ~ExceptionDialog();
	void setTextToLabels(QString sz1, QString sz2);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::ExceptionDialog* ui;
};

#endif // EXCXDIALOG_H
