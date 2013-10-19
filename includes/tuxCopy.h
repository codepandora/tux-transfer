#ifndef TUX_COPY_H
#define TUX_COPY_H

#include <QStandardItemModel>
#include <QFileDialog>
#include <QMessageBox>
#include <QTime>
#include <QTimer>
#include "../ui/copyDialog.h"
#include "../ui/copyMore.h"
#include "CopyInstance.h"

class TuxCopy : public QDialog
{
	Q_OBJECT

public:
	TuxCopy(QDialog *parent=0);
//	~TuxCopy();
	
	QDialog *copyDialog;
	QWidget *more;
	QStandardItemModel *model;
        Ui::copyDialog ui_copy;
	Ui::copyMore ui_more;
	QTime time;
	QTimer *timer;
	QTime time2;
	QTimer *timer2;
	int elapsed;
	int remainingTime;

	void displayList(); //Display the File List table in More panel
	QList<QStandardItem *> prepareRow(const QString&,const QString&,const QString&); //Prepare a Tuple for File List Table
	void startElapsedTimer();
	void startRemainingTimer(int);

private:
	copyInstance* copyProcess;

private slots:
	void showDialog(); //SLOT to display CopyDialog
	void toggleMore(bool); //SLOT to toggle More panel display 
	void showElapsedTime();
	void showRemainingTime();

};

#endif