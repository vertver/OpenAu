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
	AuEngine::Input input;
	AuEngine::Output output;

    ui->setupUi(this);
	statusBar()->showMessage(tr(output.GetOutputDevice()));	
	output.CreateOutput("I:\\Beliver (44.1-24 flac vs mp3 320).wav");

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
void OAU::ThrowExceptionDialog(std::string szException, std::string szDescription)
{
	ExceptionDialog* excd;
	excd->setWindowFlags(Qt::WindowStaysOnTopHint);
	excd->setWindowTitle("Application error");
	excd->show();
	excd->setTextToLabels(szException, szDescription);
}