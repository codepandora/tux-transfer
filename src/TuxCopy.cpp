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

     connect(ui_copy.btnCancel, SIGNAL(clicked()),copyDialog,SLOT(close()));
	
     connect(ui_copy.btnMore, SIGNAL(toggled(bool)),this,SLOT(toggleMore(bool)));

     elapsed=0;

     displayList(); //Display File List in More Panel 

}

void TuxCopy::showDialog()
{
  QFileDialog srcDialog(this);
  srcDialog.setFileMode(QFileDialog::ExistingFiles);
  QStringList srcList;
  if(srcDialog.exec())
  {
    srcList = srcDialog.selectedFiles();
    //QMessageBox msg;
    //msg.setText(srcList.at(0));
    //msg.exec();
  }


  QFileDialog destDialog(this);
  destDialog.setFileMode(QFileDialog::Directory);
  QStringList destList;
  if(destDialog.exec())
  {
    destList = destDialog.selectedFiles();
    //QMessageBox msg2;
    //msg2.setText(destList.at(0));
    //msg2.exec();
  }
/*
  int srcListLen = srcList.size();
  char** list = new (char*)[srcListLen];
  for( int cnt=0;cnt< srcListLen; cnt++ )
  {
      strcpy( list[cnt], srcList.at( cnt ).toLocal8Bit().data() );
  }
  */
const char* srcs[] ={"/home/redlightning/Documents/Test"};
  //  copyProcess = new copyInstance( const_cast<const char**>(list), srcListLen, destList.at( 0 ).toLocal8Bit().data(),this );
  
  startElapsedTimer();     
  startRemainingTimer(8);     

  copyProcess = new copyInstance( srcs,1, "/home/redlightning/Pictures",this );
  
  //copyDialog->hide();
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
     model = new QStandardItemModel(0,3,this); 
     model->setHorizontalHeaderItem(0, new QStandardItem(QString("File")));
     model->setHorizontalHeaderItem(1, new QStandardItem(QString("Size")));
     model->setHorizontalHeaderItem(2, new QStandardItem(QString("Status")));
     
     ui_more.tableView->setModel(model);
}


QList<QStandardItem *> TuxCopy::prepareRow(const QString &first,const QString &second,const QString &third)
 {
     QList<QStandardItem *> rowItems;
     rowItems << new QStandardItem(first);
     rowItems << new QStandardItem(second);
     rowItems << new QStandardItem(third);
     return rowItems;
 }

void TuxCopy::startElapsedTimer()
{

	time.setHMS(0,0,0,0);
	timer = new QTimer(this);
	timer->start(1000);
	connect(timer, SIGNAL(timeout()), this, SLOT(showElapsedTime()));
}

void TuxCopy::startRemainingTimer(int eta)
{
	remainingTime = eta; 
	time2.setHMS(0,0,0,0); 	
	timer2 = new QTimer(this);
	timer2->start(1000);
	connect(timer2, SIGNAL(timeout()), this, SLOT(showRemainingTime()));
}

void TuxCopy::showElapsedTime()
{
	QTime newtime;
	
	elapsed=elapsed+1;
	newtime=time.addSecs(elapsed);
	QString text = newtime.toString("hh:mm:ss");
	ui_copy.lblTimeElapsed->setText("Elapsed Time: " + text);
}

void TuxCopy::showRemainingTime()
{
	QTime newtime;
	
	remainingTime=remainingTime-1;
	newtime=time.addSecs(remainingTime);
	QString text = newtime.toString("hh:mm:ss");
	ui_copy.lblTimeRemaining->setText("Remaining Time: " + text);
} 
