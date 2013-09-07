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
 
    QAction *options;
    QAction *about;
    QAction *quit;
 
private slots:
    void trayIconClicked(QSystemTrayIcon::ActivationReason);
};

#endif
