/*
 *System Tray Header File
 *Author:CodePandora
 */

#ifndef TUX_TRAY_H
#define TUX_TRAY_H

#include <QDialog> 
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
#include <QCloseEvent>
#include "../ui/optionsDialog.h"
#include "../ui/aboutDialog.h"
#include "../includes/tuxCopy.h"
#include "../includes/tuxMove.h"
 
class TuxTray : public QDialog
{
    Q_OBJECT
 
 
public:
    explicit TuxTray(QDialog *parent = 0);
    ~TuxTray();
 
 
private:
    void createActions();
    void createTrayIcon();
    void setIcon();
    void closeEvent(QCloseEvent *); // Overriding the window's close event
 
 
    QSystemTrayIcon *trayIcon;
    QMenu *trayIconMenu;
    QDialog *aboutDialog;
    QDialog *optionsDialog;
    TuxCopy *tuxCopy;
    TuxMove *tuxMove;    

    QAction *copyAction;
    QAction *moveAction;
    QAction *options;
    QAction *about;
    QAction *quit;
 
private slots:
    void trayIconClicked(QSystemTrayIcon::ActivationReason);
};

#endif
