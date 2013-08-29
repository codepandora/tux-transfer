#include "ui/copyDialog.h"

int main(int argc, char *argv[])
 {
     QApplication app(argc, argv);
     QDialog *dialog = new QDialog;
     Ui::copyDialog ui;
     ui.setupUi(dialog);

     dialog->show();
     return app.exec();
 }
