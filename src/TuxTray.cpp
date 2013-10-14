/*
 *System Tray Icon
 *Author: CodePandora
 */

#include "../includes/TuxTray.h"

TuxTray::TuxTray(QDialog *parent) : QDialog(parent)
{
  Ui::optionsDialog ui;
  ui.setupUi(this);

  tuxCopy = new TuxCopy();

  Ui::aboutDialog ui_about;
  aboutDialog = new QDialog();
  ui_about.setupUi(aboutDialog);
 
    createActions();
    createTrayIcon();
    setIcon();
    
    trayIcon->setVisible(true);

    if(trayIcon->isVisible() && QSystemTrayIcon::isSystemTrayAvailable())  
      trayIcon->setToolTip("TuxTransfer");
    else
      trayIcon->setToolTip("Invisible");

    trayIcon->show(); 
    
}

/// Hide and destroy the icon in the systray
TuxTray::~TuxTray()
{
    delete trayIcon;
    delete trayIconMenu;
    delete copyAction;
    delete options;
    delete about;
    delete quit;
}

void TuxTray::createActions()
{
    copyAction = new QAction(tr("&Copy"), this);
    connect(copyAction, SIGNAL(triggered()), tuxCopy, SLOT(showDialog()));

    options = new QAction(tr("&Options"), this);
    connect(options, SIGNAL(triggered()), this, SLOT(show()));
 
    about = new QAction(tr("&About"), this);
    connect(about, SIGNAL(triggered()), aboutDialog, SLOT(show()));
 
    quit = new QAction(tr("&Quit"), this);
    connect(quit, SIGNAL(triggered()), qApp, SLOT(quit()));
}

void TuxTray::createTrayIcon()
{
    trayIconMenu = new QMenu(this);
 
    trayIconMenu->addAction(copyAction);
    trayIconMenu->addSeparator();
    trayIconMenu->addAction(options);
    trayIconMenu->addAction(about);
    trayIconMenu->addSeparator();
    trayIconMenu->addAction(quit);
 
 
    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setContextMenu(trayIconMenu);
 
 
    connect(
            trayIcon,
            SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
            this,
            SLOT(trayIconClicked(QSystemTrayIcon::ActivationReason))
           );
}

void TuxTray::setIcon()
{
  QIcon icon;
  icon.addFile(QStringLiteral(":/icons/res/copyIcon.png"));
    trayIcon->setIcon(icon);
}

void TuxTray::trayIconClicked(QSystemTrayIcon::ActivationReason reason)
{
    if(reason == QSystemTrayIcon::Trigger)
        this->show();
}

void TuxTray::closeEvent(QCloseEvent *event)
{
    if (trayIcon->isVisible()) {
        trayIcon->showMessage(tr("Tux Transfer"),
        tr("Tux Transfer is running in the background..."));
        hide();
 
        event->ignore(); // Don't let the event propagate to the base class
    }
}
