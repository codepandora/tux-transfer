#include "ui/copyDialog.h"
#include "ui/copyMore.h"

int main(int argc, char *argv[])
 {

     QApplication app(argc, argv);
     QDialog *dialog = new QDialog;
     QWidget *more = new QWidget(dialog);

     Ui::copyDialog ui;
     ui.setupUi(dialog);

     Ui::copyMore ui_more;
     ui_more.setupUi(more);
     
     more->setGeometry(0,171,421,181);
     ui.btnMore->setCheckable(true);
     QObject::connect(ui.btnMore, SIGNAL(toggled(bool)),more,SLOT(setVisible(bool)));
     more->hide();     

     dialog->show();

     return app.exec();
 }
