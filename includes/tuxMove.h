#ifndef TUX_MOVE_H
#define TUX_MOVE_H

#include <QStandardItemModel>
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

	void displayList(); //Display the File List table in More panel
	QList<QStandardItem *> prepareRow(const QString&,const QString&); //Prepare a Tuple for File List Table

private slots:
	void showDialog(); //SLOT to display CopyDialog
	void toggleMore(bool); //SLOT to toggle More panel display 

};

#endif