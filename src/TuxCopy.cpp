#include "../includes/tuxCopy.h"

TuxCopy::TuxCopy(QDialog *parent) : QDialog(parent)
{
     copyDialog = new QDialog();
     ui_copy.setupUi(copyDialog);

     more = new QWidget(copyDialog);
     ui_more.setupUi(more);
   
     more->setGeometry(0,171,421,181);
     ui_copy.btnMore->setCheckable(true);
     more->setVisible(false);
	
     connect(ui_copy.btnMore, SIGNAL(toggled(bool)),this,SLOT(toggleMore(bool)));

     displayList(); //Display File List in More Panel
 
     QList<QStandardItem *>firstRow = prepareRow("/home/codepandora/cp.png","In Progress");  
     model->appendRow(firstRow);     

}

void TuxCopy::showDialog()
{
  copyDialog->show();
}

void TuxCopy::toggleMore(bool state)
{
  if(state)
	copyDialog->resize(419,350);
  else
	copyDialog->resize(419,170);
 
  more->setVisible(state);
}


void TuxCopy::displayList()
{
     model = new QStandardItemModel(0,2,this); 
     model->setHorizontalHeaderItem(0, new QStandardItem(QString("File")));
     model->setHorizontalHeaderItem(1, new QStandardItem(QString("Status")));
 
     ui_more.tableView->setModel(model);
}


QList<QStandardItem *> TuxCopy::prepareRow(const QString &first,const QString &second)
 {
     QList<QStandardItem *> rowItems;
     rowItems << new QStandardItem(first);
     rowItems << new QStandardItem(second);
     return rowItems;
 }