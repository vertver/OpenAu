/********************************************************************************
** Form generated from reading UI file 'oau.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OAU_H
#define UI_OAU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OAU
{
public:
    QAction *actionOpen;
    QAction *actionOpen_Files_at_directory;
    QAction *actionFiles_at_buffer;
    QAction *actionSave;
    QAction *actionSave_as;
    QAction *actionSave_all;
    QAction *actionClose_without_saving;
    QAction *actionClose;
    QAction *actionClose_and_save_files;
    QAction *actionExit;
    QAction *actionRedo;
    QAction *actionUndo;
    QAction *actionUndo_all;
    QAction *actionRedo_all;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionDelete;
    QAction *actionAt_all_files;
    QAction *actionAt_selected_file;
    QAction *actionPreferences;
    QAction *actionLimit_to_3dBFS;
    QAction *actionLimitt_to_0dbFS;
    QAction *actionFast_high_freq_boost;
    QAction *actionFast_LowFreq_Boost;
    QAction *actionVST;
    QAction *actionSpectral_view;
    QAction *actionAmplitude_view;
    QAction *actionWaveform_view;
    QAction *actionStatusBar_info;
    QAction *actionAbout_OpenAu;
    QAction *actionAbout_us;
    QAction *actionHelp;
    QWidget *centralWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuSelect;
    QMenu *menuEffects;
    QMenu *menuExport;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *OAU)
    {
        if (OAU->objectName().isEmpty())
            OAU->setObjectName(QStringLiteral("OAU"));
        OAU->resize(1000, 700);
        OAU->setBaseSize(QSize(1000, 700));
        QPalette palette;
        QBrush brush(QColor(145, 145, 145, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(163, 0, 57, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(16, 16, 17, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush2);
        QBrush brush3(QColor(21, 21, 21, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush3);
        QBrush brush4(QColor(208, 208, 208, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush4);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush4);
        QBrush brush5(QColor(25, 25, 25, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush5);
        palette.setBrush(QPalette::Active, QPalette::Window, brush5);
        QBrush brush6(QColor(18, 18, 18, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush5);
        OAU->setPalette(palette);
        actionOpen = new QAction(OAU);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionOpen_Files_at_directory = new QAction(OAU);
        actionOpen_Files_at_directory->setObjectName(QStringLiteral("actionOpen_Files_at_directory"));
        actionFiles_at_buffer = new QAction(OAU);
        actionFiles_at_buffer->setObjectName(QStringLiteral("actionFiles_at_buffer"));
        actionSave = new QAction(OAU);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave_as = new QAction(OAU);
        actionSave_as->setObjectName(QStringLiteral("actionSave_as"));
        actionSave_all = new QAction(OAU);
        actionSave_all->setObjectName(QStringLiteral("actionSave_all"));
        actionClose_without_saving = new QAction(OAU);
        actionClose_without_saving->setObjectName(QStringLiteral("actionClose_without_saving"));
        actionClose = new QAction(OAU);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        actionClose_and_save_files = new QAction(OAU);
        actionClose_and_save_files->setObjectName(QStringLiteral("actionClose_and_save_files"));
        actionExit = new QAction(OAU);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionRedo = new QAction(OAU);
        actionRedo->setObjectName(QStringLiteral("actionRedo"));
        actionUndo = new QAction(OAU);
        actionUndo->setObjectName(QStringLiteral("actionUndo"));
        actionUndo_all = new QAction(OAU);
        actionUndo_all->setObjectName(QStringLiteral("actionUndo_all"));
        actionRedo_all = new QAction(OAU);
        actionRedo_all->setObjectName(QStringLiteral("actionRedo_all"));
        actionCopy = new QAction(OAU);
        actionCopy->setObjectName(QStringLiteral("actionCopy"));
        actionPaste = new QAction(OAU);
        actionPaste->setObjectName(QStringLiteral("actionPaste"));
        actionDelete = new QAction(OAU);
        actionDelete->setObjectName(QStringLiteral("actionDelete"));
        actionAt_all_files = new QAction(OAU);
        actionAt_all_files->setObjectName(QStringLiteral("actionAt_all_files"));
        actionAt_selected_file = new QAction(OAU);
        actionAt_selected_file->setObjectName(QStringLiteral("actionAt_selected_file"));
        actionPreferences = new QAction(OAU);
        actionPreferences->setObjectName(QStringLiteral("actionPreferences"));
        actionLimit_to_3dBFS = new QAction(OAU);
        actionLimit_to_3dBFS->setObjectName(QStringLiteral("actionLimit_to_3dBFS"));
        actionLimitt_to_0dbFS = new QAction(OAU);
        actionLimitt_to_0dbFS->setObjectName(QStringLiteral("actionLimitt_to_0dbFS"));
        actionFast_high_freq_boost = new QAction(OAU);
        actionFast_high_freq_boost->setObjectName(QStringLiteral("actionFast_high_freq_boost"));
        actionFast_LowFreq_Boost = new QAction(OAU);
        actionFast_LowFreq_Boost->setObjectName(QStringLiteral("actionFast_LowFreq_Boost"));
        actionVST = new QAction(OAU);
        actionVST->setObjectName(QStringLiteral("actionVST"));
        actionSpectral_view = new QAction(OAU);
        actionSpectral_view->setObjectName(QStringLiteral("actionSpectral_view"));
        actionAmplitude_view = new QAction(OAU);
        actionAmplitude_view->setObjectName(QStringLiteral("actionAmplitude_view"));
        actionWaveform_view = new QAction(OAU);
        actionWaveform_view->setObjectName(QStringLiteral("actionWaveform_view"));
        actionStatusBar_info = new QAction(OAU);
        actionStatusBar_info->setObjectName(QStringLiteral("actionStatusBar_info"));
        actionAbout_OpenAu = new QAction(OAU);
        actionAbout_OpenAu->setObjectName(QStringLiteral("actionAbout_OpenAu"));
        actionAbout_us = new QAction(OAU);
        actionAbout_us->setObjectName(QStringLiteral("actionAbout_us"));
        actionHelp = new QAction(OAU);
        actionHelp->setObjectName(QStringLiteral("actionHelp"));
        centralWidget = new QWidget(OAU);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(0, 0, 71, 71));
        QPalette palette1;
        QBrush brush7(QColor(139, 139, 139, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush7);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush8(QColor(29, 194, 131, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush8);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush5);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush5);
        QBrush brush9(QColor(4, 4, 4, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush9);
        QBrush brush10(QColor(41, 41, 41, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush10);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush7);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush5);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush5);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush9);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush10);
        QBrush brush11(QColor(164, 166, 168, 96));
        brush11.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush11);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush10);
        pushButton->setPalette(palette1);
        pushButton->setFlat(false);
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(0, 70, 71, 71));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush7);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Active, QPalette::BrightText, brush8);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush5);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush5);
        palette2.setBrush(QPalette::Active, QPalette::Shadow, brush9);
        palette2.setBrush(QPalette::Active, QPalette::AlternateBase, brush10);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush7);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::BrightText, brush8);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush5);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush5);
        palette2.setBrush(QPalette::Inactive, QPalette::Shadow, brush9);
        palette2.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush10);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush11);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::BrightText, brush8);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush5);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush5);
        palette2.setBrush(QPalette::Disabled, QPalette::Shadow, brush9);
        palette2.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush10);
        pushButton_2->setPalette(palette2);
        pushButton_2->setFlat(false);
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(0, 210, 71, 71));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush7);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Active, QPalette::BrightText, brush8);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush5);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush5);
        palette3.setBrush(QPalette::Active, QPalette::Shadow, brush9);
        palette3.setBrush(QPalette::Active, QPalette::AlternateBase, brush10);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush7);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::BrightText, brush8);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush5);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush5);
        palette3.setBrush(QPalette::Inactive, QPalette::Shadow, brush9);
        palette3.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush10);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush11);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::BrightText, brush8);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush5);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush5);
        palette3.setBrush(QPalette::Disabled, QPalette::Shadow, brush9);
        palette3.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush10);
        pushButton_3->setPalette(palette3);
        pushButton_3->setFlat(false);
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(0, 140, 71, 71));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush7);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Active, QPalette::BrightText, brush8);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush5);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush5);
        palette4.setBrush(QPalette::Active, QPalette::Shadow, brush9);
        palette4.setBrush(QPalette::Active, QPalette::AlternateBase, brush10);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush7);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::BrightText, brush8);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush5);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush5);
        palette4.setBrush(QPalette::Inactive, QPalette::Shadow, brush9);
        palette4.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush10);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush11);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::BrightText, brush8);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush5);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush5);
        palette4.setBrush(QPalette::Disabled, QPalette::Shadow, brush9);
        palette4.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush10);
        pushButton_4->setPalette(palette4);
        pushButton_4->setFlat(false);
        OAU->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(OAU);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1000, 20));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuSelect = new QMenu(menuEdit);
        menuSelect->setObjectName(QStringLiteral("menuSelect"));
        menuEffects = new QMenu(menuBar);
        menuEffects->setObjectName(QStringLiteral("menuEffects"));
        menuExport = new QMenu(menuBar);
        menuExport->setObjectName(QStringLiteral("menuExport"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        OAU->setMenuBar(menuBar);
        mainToolBar = new QToolBar(OAU);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        OAU->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(OAU);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        OAU->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuEffects->menuAction());
        menuBar->addAction(menuExport->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionOpen_Files_at_directory);
        menuFile->addAction(actionFiles_at_buffer);
        menuFile->addSeparator();
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_as);
        menuFile->addAction(actionSave_all);
        menuFile->addSeparator();
        menuFile->addAction(actionClose);
        menuFile->addAction(actionClose_without_saving);
        menuFile->addAction(actionClose_and_save_files);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuEdit->addAction(actionRedo);
        menuEdit->addAction(actionUndo);
        menuEdit->addAction(actionUndo_all);
        menuEdit->addSeparator();
        menuEdit->addSeparator();
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionPaste);
        menuEdit->addAction(actionDelete);
        menuEdit->addSeparator();
        menuEdit->addAction(menuSelect->menuAction());
        menuEdit->addSeparator();
        menuEdit->addAction(actionPreferences);
        menuSelect->addAction(actionAt_all_files);
        menuSelect->addAction(actionAt_selected_file);
        menuEffects->addAction(actionLimit_to_3dBFS);
        menuEffects->addAction(actionLimitt_to_0dbFS);
        menuEffects->addAction(actionFast_high_freq_boost);
        menuEffects->addAction(actionFast_LowFreq_Boost);
        menuEffects->addSeparator();
        menuEffects->addAction(actionVST);
        menuExport->addAction(actionSpectral_view);
        menuExport->addAction(actionAmplitude_view);
        menuExport->addSeparator();
        menuExport->addAction(actionWaveform_view);
        menuExport->addAction(actionStatusBar_info);
        menuHelp->addAction(actionHelp);
        menuHelp->addSeparator();
        menuHelp->addAction(actionAbout_OpenAu);
        menuHelp->addAction(actionAbout_us);

        retranslateUi(OAU);

        QMetaObject::connectSlotsByName(OAU);
    } // setupUi

    void retranslateUi(QMainWindow *OAU)
    {
        OAU->setWindowTitle(QApplication::translate("OAU", "Open Audio Utility 0.1a", nullptr));
        actionOpen->setText(QApplication::translate("OAU", "Open file...", nullptr));
        actionOpen_Files_at_directory->setText(QApplication::translate("OAU", "Open files at directory...", nullptr));
        actionFiles_at_buffer->setText(QApplication::translate("OAU", "Open file of buffer", nullptr));
        actionSave->setText(QApplication::translate("OAU", "Save", nullptr));
        actionSave_as->setText(QApplication::translate("OAU", "Save as...", nullptr));
        actionSave_all->setText(QApplication::translate("OAU", "Save all files...", nullptr));
        actionClose_without_saving->setText(QApplication::translate("OAU", "Close without saving", nullptr));
        actionClose->setText(QApplication::translate("OAU", "Close", nullptr));
        actionClose_and_save_files->setText(QApplication::translate("OAU", "Close and save files...", nullptr));
        actionExit->setText(QApplication::translate("OAU", "Exit", nullptr));
        actionRedo->setText(QApplication::translate("OAU", "Redo", nullptr));
        actionUndo->setText(QApplication::translate("OAU", "Undo", nullptr));
        actionUndo_all->setText(QApplication::translate("OAU", "Undo all", nullptr));
        actionRedo_all->setText(QApplication::translate("OAU", "Redo all", nullptr));
        actionCopy->setText(QApplication::translate("OAU", "Copy ", nullptr));
        actionPaste->setText(QApplication::translate("OAU", "Paste", nullptr));
        actionDelete->setText(QApplication::translate("OAU", "Delete", nullptr));
        actionAt_all_files->setText(QApplication::translate("OAU", "At all files", nullptr));
        actionAt_selected_file->setText(QApplication::translate("OAU", "At selected file", nullptr));
        actionPreferences->setText(QApplication::translate("OAU", "Preferences", nullptr));
        actionLimit_to_3dBFS->setText(QApplication::translate("OAU", "Limit to -3dBFS", nullptr));
        actionLimitt_to_0dbFS->setText(QApplication::translate("OAU", "Limit to -0dBFS", nullptr));
        actionFast_high_freq_boost->setText(QApplication::translate("OAU", "Fast HighFreq Boost ", nullptr));
        actionFast_LowFreq_Boost->setText(QApplication::translate("OAU", "Fast LowFreq Boost", nullptr));
        actionVST->setText(QApplication::translate("OAU", "VST", nullptr));
        actionSpectral_view->setText(QApplication::translate("OAU", "Spectral view", nullptr));
        actionAmplitude_view->setText(QApplication::translate("OAU", "Amplitude view", nullptr));
        actionWaveform_view->setText(QApplication::translate("OAU", "Waveform view", nullptr));
        actionStatusBar_info->setText(QApplication::translate("OAU", "StatusBar info", nullptr));
        actionAbout_OpenAu->setText(QApplication::translate("OAU", "About OpenAu...", nullptr));
        actionAbout_us->setText(QApplication::translate("OAU", "About us...", nullptr));
        actionHelp->setText(QApplication::translate("OAU", "Help", nullptr));
        pushButton->setText(QApplication::translate("OAU", "PushButton", nullptr));
        pushButton_2->setText(QApplication::translate("OAU", "PushButton", nullptr));
        pushButton_3->setText(QApplication::translate("OAU", "PushButton", nullptr));
        pushButton_4->setText(QApplication::translate("OAU", "PushButton", nullptr));
        menuFile->setTitle(QApplication::translate("OAU", "File", nullptr));
        menuEdit->setTitle(QApplication::translate("OAU", "Edit", nullptr));
        menuSelect->setTitle(QApplication::translate("OAU", "Select", nullptr));
        menuEffects->setTitle(QApplication::translate("OAU", "Effects", nullptr));
        menuExport->setTitle(QApplication::translate("OAU", "View", nullptr));
        menuHelp->setTitle(QApplication::translate("OAU", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OAU: public Ui_OAU {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OAU_H
