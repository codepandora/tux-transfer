#include "../includes/tuxMove.h"

TuxMove::TuxMove(QDialog *parent) : QDialog(parent)
{
     moveDialog = new QDialog();
     ui_move.setupUi(moveDialog);
     ui_move.lblIcon->setPixmap(QPixmap(QString::fromUtf8(":/icons/res/moveIcon.png")));     
     QIcon icon;
     icon.addFile(QStringLiteral(":/icons/res/moveIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
     moveDialog->setWindowIcon(icon);
     moveDialog->setStyleSheet(QLatin1String("#copyDialog\n"
"{\n"
"background:#222222;\n"
"}\n"
"\n"
"QLabel\n"
"{\n"
"color:#ffffff;\n"
"}\n"
"\n"
"QProgressBar\n"
"{\n"
"text-align:center;\n"
" color:#000;\n"
"font-weight:bold;\n"
"}\n"
"\n"
"QProgressBar::chunk \n"
"{ \n"
"background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #fff000, stop: 1 #ff6900); \n"
"}"));   

     more = new QWidget(moveDialog);
     ui_more.setupUi(more);
   
     more->setGeometry(0,171,421,181);
     ui_move.btnMore->setCheckable(true);
     more->setVisible(false);
	
     connect(ui_move.btnMore, SIGNAL(toggled(bool)),this,SLOT(toggleMore(bool)));

     elapsed = 0;
     displayList(); //Display File List in More Panel
 
     QList<QStandardItem *>firstRow = prepareRow("/home/codepandora/cp.png","In Progress");  
     model->appendRow(firstRow);     

}

void TuxMove::showDialog()
{
  QFileDialog srcDialog(this);
  srcDialog.setFileMode(QFileDialog::ExistingFiles);
  QStringList srcList;
  if(srcDialog.exec())
  {
    srcList = srcDialog.selectedFiles();
    QMessageBox msg;
    msg.setText(srcList.at(0));
    msg.exec();
  }

  QFileDialog destDialog(this);
  destDialog.setFileMode(QFileDialog::Directory);
  QStringList destList;
  if(destDialog.exec())
  {
    destList = destDialog.selectedFiles();
    QMessageBox msg2;
    msg2.setText(destList.at(0));
    msg2.exec();
  }

  moveDialog->show();
  startElapsedTimer();     
  startRemainingTimer(600);     

}

void TuxMove::toggleMore(bool state)
{
  if(state)
	moveDialog->resize(419,350);
  else
	moveDialog->resize(419,170);
 
  more->setVisible(state);
}


void TuxMove::displayList()
{
     model = new QStandardItemModel(0,2,this); 
     model->setHorizontalHeaderItem(0, new QStandardItem(QString("File")));
     model->setHorizontalHeaderItem(1, new QStandardItem(QString("Status")));
 
     ui_more.tableView->setModel(model);
}


QList<QStandardItem *> TuxMove::prepareRow(const QString &first,const QString &second)
 {
     QList<QStandardItem *> rowItems;
     rowItems << new QStandardItem(first);
     rowItems << new QStandardItem(second);
     return rowItems;
 }


void TuxMove::startElapsedTimer()
{

	time.setHMS(0,0,0,0);
	timer = new QTimer(this);
	timer->start(1000);
	connect(timer, SIGNAL(timeout()), this, SLOT(showElapsedTime()));
}

void TuxMove::startRemainingTimer(int eta)
{
	remainingTime = eta; 
	time2.setHMS(0,0,0,0); 	
	timer2 = new QTimer(this);
	timer2->start(1000);
	connect(timer2, SIGNAL(timeout()), this, SLOT(showRemainingTime()));
}

void TuxMove::showElapsedTime()
{
	QTime newtime;
	
	elapsed=elapsed+1;
	newtime=time.addSecs(elapsed);
	QString text = newtime.toString("hh:mm:ss");
	ui_move.lblTimeElapsed->setText("Elapsed Time: " + text);
}

void TuxMove::showRemainingTime()
{
	QTime newtime;
	
	remainingTime=remainingTime-1;
	newtime=time.addSecs(remainingTime);
	QString text = newtime.toString("hh:mm:ss");
	ui_move.lblTimeRemaining->setText("Remaining Time: " + text);
} 