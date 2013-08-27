/*
 *System Tray Icon
 *Author: CodePandora
 */

#include "TuxTray.h"
#include "../ui/optionsDialog.h"
#include "../ui/aboutDialog.h"

TuxTray::TuxTray(QWidget * parent) : QWidget(parent),ui(new Ui::TuxTray)
{

    //initialize icon properties
    systrayMenu         = new QMenu();
    copyMenu		= new QMenu();

    actionMenuAbout	        = new QAction(this);
    actionMenuQuit		= new QAction(this);
    actionOptions		= new QAction(this);
   
    /* *****  Set menu text ***** */
    actionMenuAbout->setText("About");
    actionMenuQuit->setText("Quit");
    actionOptions->setText("Options");
    copyMenu->setTitle("Copy/Move");
    
    setToolTip("Tux Transfer");
    
    setIcon(QIcon(":/logo/res/tux-transfer.png"));
   
    //connect the action
  //connect(&timerCheckSetTooltip, &QTimer::timeout, this, &TuxTray::checkSetTooltip);
    
    connect(actionMenuQuit, &QAction::triggered, this, &TuxTray::hide);
    //connect(actionMenuQuit, &QAction::triggered, this, &TuxTray::quit);
    //    connect(actionMenuAbout, &QAction::triggered, this, &TuxTray::showHelp);
    // connect(actionOptions, &QAction::triggered, this, &TuxTray::showOptions);
   
    //display the icon
   
    systrayMenu->addMenu(copyMenu);
    systrayMenu->addAction(actionOptions);
    systrayMenu->addAction(actionMenuAbout);
    systrayMenu->addAction(actionMenuQuit);

    systrayMenu->insertSeparator(actionOptions);
    
    setContextMenu(systrayMenu);
    // updateTuxTray();

    show();
}

/// Hide and destroy the icon in the systray
TuxTray::~TuxTray()
{
    delete actionMenuQuit;
    delete actionMenuAbout;
    delete actionOptions;
    delete systrayMenu;
    delete copyMenu;
}


/* **show a message linked to the systray icon** 
void TuxTray::showSystrayMessage(const QString& text)
{
    showMessage(tr("Information"),text,QSystemTrayIcon::Information,0);
}

*/
