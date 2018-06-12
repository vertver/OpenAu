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

namespace Ui { class OAU; }

class OAU : public QMainWindow
{
    Q_OBJECT

public:
    explicit OAU(QWidget *parent = nullptr);
    ~OAU();
	void ThrowExceptionDialog(std::string szException, std::string szDescription);

private:
    Ui::OAU *ui;
};


#endif // OAU_H
