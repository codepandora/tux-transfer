#ifndef TUX_MOVE_H
#define TUX_MOVE_H

#include <QStandardItemModel>
#include <QFileDialog>
#include <QMessageBox>
#include <QTime>
#include <QTimer>
#include "../ui/copyDialog.h"
#include "../ui/copyMore.h"

class TuxMove : public QDialog
{
	Q_OBJECT;

public:
	TuxMove(QDialog *parent=0);
//	~TuxMove();
	
	QDialog *moveDialog;
	QWidget *more;
	QStandardItemModel *model;
        Ui::copyDialog ui_move;
	Ui::copyMore ui_more;
	QTime time;
	QTimer *timer;
	QTime time2;
	QTimer *timer2;
	int elapsed;
	int remainingTime;

	void displayList(); //Display the File List table in More panel
	QList<QStandardItem *> prepareRow(const QString&,const QString&); //Prepare a Tuple for File List Table
	void startElapsedTimer();
	void startRemainingTimer(int);

private slots:
	void showDialog(); //SLOT to display MoveDialog
	void toggleMore(bool); //SLOT to toggle More panel display 
	void showElapsedTime();
	void showRemainingTime();

};

#endif