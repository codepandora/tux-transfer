#ifndef TUX_COPY_H
#define TUX_COPY_H

#include <QStandardItemModel>
#include <QFileDialog>
#include <QMessageBox>
#include <QTime>
#include <QTimer>
#include "../ui/copyDialog.h"
#include "../ui/copyMore.h"

class TuxCopy : public QDialog
{
	Q_OBJECT;

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
	int elapsed;

	void displayList(); //Display the File List table in More panel
	QList<QStandardItem *> prepareRow(const QString&,const QString&); //Prepare a Tuple for File List Table
	void startElapsedTimer();

private slots:
	void showDialog(); //SLOT to display CopyDialog
	void toggleMore(bool); //SLOT to toggle More panel display 
	void showTime();

};

#endif