/*
 *Main Tux Transfer Execution File
 *Author: CodePandora
 *Version: 0.1
 */

#include "ui/copyDialog.h"
#include "src/TuxTray.h"

int main(int argc, char *argv[])
 {
     QApplication app(argc, argv);
     app.setAttribute(Qt::AA_DontShowIconsInMenus, false);    

     TuxTray *icon = new TuxTray;
      icon->show();

     return app.exec();
 }