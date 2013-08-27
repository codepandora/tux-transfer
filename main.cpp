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
     QDialog *dialog = new QDialog;
     Ui::copyDialog ui;
     ui.setupUi(dialog);

     dialog->show();

     TuxTray *icon = new TuxTray;
     icon->show();

     return app.exec();
 }
