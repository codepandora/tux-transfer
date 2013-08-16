#include "ui/aboutDialog.h"

int main(int argc, char *argv[])
 {
     QApplication app(argc, argv);
     QDialog *dialog = new QDialog;
     Ui::aboutDialog ui;
     ui.setupUi(dialog);

     dialog->show();
     return app.exec();
 }
