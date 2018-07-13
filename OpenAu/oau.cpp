/////////////////////////////////
// VERTVER, 2018 (C)
// OpenAu, Open Audio Utility
// MIT-License
/////////////////////////////////
// oau.cpp:
// UI for Utility
/////////////////////////////////

#include "oau.h"
#include "main.h"
#include "ExcDialog.h"
#pragma comment(lib, "../x64/Debug/AuEngine.lib")

/***********************************************
* OAU():
* Constructor
***********************************************/
OAU::OAU(QWidget *parent) : QMainWindow(parent), ui(new Ui::OAU)
{
    ui->setupUi(this);
}

/***********************************************
* OpenAudioFile():
* Open any audio file at directory
***********************************************/
QString OAU::OpenAudioFile()
{
	return QFileDialog::getOpenFileName(this, tr("Open Audio"), NULL, tr("Audio Files (*.wav)"));
}

/***********************************************
* PlayAudioFile():
* Send current file to stream
***********************************************/
void OAU::PlayAudioFile(QString aFile)
{
	if (aFile.isEmpty())
	{
#ifdef DEBUG
		MessageBoxA(NULL, "The path string is empty", "Warning!", MB_OK | MB_ICONWARNING);
#endif
		Sleep(0);
	}
	else
		output.CreateOutput(aFile.toLocal8Bit());
}

/***********************************************
* ~OAU():
* Destructor
***********************************************/
OAU::~OAU()
{
    delete ui;
}

/***********************************************
* ExceptionTextThrow():
* ==UNUSED===
* Throw exception dialog with info (Qt)
***********************************************/
void OAU::ThrowExceptionDialog(QString szException, QString szDescription)
{
	ExceptionDialog* excd;
	excd->setWindowFlags(Qt::WindowStaysOnTopHint);
	excd->setWindowTitle("Application error");
	excd->show();
	excd->setTextToLabels(szException, szDescription);
}

/***********************************************
* OpenAudioFile():
* Open any audio file at directory
***********************************************/
void OAU::on_pushButton_clicked()
{
	PlayAudioFile(OpenAudioFile());
}
