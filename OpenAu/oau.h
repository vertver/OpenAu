/////////////////////////////////
// VERTVER, 2018 (C)
// OpenAu, Open Audio Utility
// MIT-License
/////////////////////////////////
// oau.h:
// header for oau.cpp
/////////////////////////////////

#ifndef OAU_H
#define OAU_H

#include <exception>
#include <QApplication>
#include <QMainWindow>
#include "ui_oau.h"
#include <QMessageBox>
#include <math.h>
#include "../AuEngine/AuEngine.h"

#define	MAX_NUM_ARGVS 128

extern "C"
{
#if (defined (_WIN32) && defined(_MSC_VER))
	typedef class AuEngine::Output eOutput;
	typedef class AuEngine::Input eInput;
	typedef class AuEngine::FileSystem eFS;
#endif
}

namespace Ui { class OAU; }

class OAU : public QMainWindow
{
    Q_OBJECT

public:
    explicit OAU(QWidget *parent = nullptr);
    ~OAU();
	void ThrowExceptionDialog(QString szException, QString szDescription);

private:
    Ui::OAU *ui;
};


#endif // OAU_H
