/*
 *System Tray Icon
 *Author: CodePandora
 */

#include "TuxTray.h"
#include "../ui/optionsDialog.h"
#include "../ui/aboutDialog.h"

TuxTray::TuxTray(QDialog *parent) : QDialog(parent)
{
  Ui::optionsDialog ui;
  ui.setupUi(this);
 
    createActions();
    createTrayIcon();
    setIcon();
    
    trayIcon->setVisible(true);

    if(trayIcon->isVisible() && QSystemTrayIcon::isSystemTrayAvailable())  
      trayIcon->setToolTip("Visible");
    else
      trayIcon->setToolTip("Invisible");

    trayIcon->show(); 
}

/// Hide and destroy the icon in the systray
TuxTray::~TuxTray()
{
    delete trayIcon;
    delete trayIconMenu;
    delete open;
    delete close;
}

void TuxTray::createActions()
{
    open = new QAction(tr("&Open"), this);
    connect(open, SIGNAL(triggered()), this, SLOT(show()));
 
 
    close = new QAction(tr("&Quit"), this);
    connect(close, SIGNAL(triggered()), qApp, SLOT(quit()));
}

void TuxTray::createTrayIcon()
{
    trayIconMenu = new QMenu(this);
 
 
    trayIconMenu->addAction(open);
    trayIconMenu->addSeparator();
    trayIconMenu->addAction(close);
 
 
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
        tr("Tux Transfer is now running..."));
        hide();
 
        event->ignore(); // Don't let the event propagate to the base class
    }
}
