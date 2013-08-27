/*
 *System Tray Header File
 *Author:CodePandora
 */

#ifndef TUX_TRAY_H
#define TUX_TRAY_H


#include <QWidget> 
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
#include <QCloseEvent>
 
class QMenu; //Forward declaring the QMenu class
 
 
namespace Ui 
{
    class TuxTray;
}
 
 
class TuxTray : public QWidget
{
    Q_OBJECT
 
 
public:
    explicit TuxTray(QWidget *parent = 0);
    ~TuxTray();
 
 
private:
    void createActions();
    void createTrayIcon();
    void setIcon();
    void closeEvent(QCloseEvent *); // Overriding the window's close event
 
 
    Ui::TuxTray *ui;
 
 
    QSystemTrayIcon *trayIcon;
    QMenu *trayIconMenu;
 
 
    QAction *open;
    QAction *close;
 
 
private slots:
    void trayIconClicked(QSystemTrayIcon::ActivationReason);
};

#endif
