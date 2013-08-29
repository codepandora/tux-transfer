/********************************************************************************
** Form generated from reading UI file 'copyDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef COPYDIALOG_H
#define COPYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_copyDialog
{
public:
    QWidget *gridLayoutWidget;
    QHBoxLayout *layoutButtons;
    QPushButton *btnMore;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnPause;
    QPushButton *btnSkip;
    QPushButton *btnCancel;
    QProgressBar *pbarOverall;
    QProgressBar *pbarCurrent;
    QLabel *lblFrom;
    QLabel *lblTo;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *layoutTime;
    QLabel *lblTimeElapsed;
    QLabel *lblTimeRemaining;
    QLabel *lblIcon;
    QLabel *lblFileCurrent;
    QLabel *lblCurrent;
    QLabel *lblSizeCurrent;
    QLabel *lblSizeOverall;
    QLabel *lblRate;
    QLabel *lblSpeed;
    QLabel *lblOverall;
    QLabel *lblFileNo;

    void setupUi(QDialog *copyDialog)
    {
        if (copyDialog->objectName().isEmpty())
            copyDialog->setObjectName(QStringLiteral("copyDialog"));
        copyDialog->resize(419, 170);
        copyDialog->setMinimumSize(QSize(419, 170));
        copyDialog->setMaximumSize(QSize(420, 170));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/res/copyIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        copyDialog->setWindowIcon(icon);
        copyDialog->setStyleSheet(QLatin1String("#copyDialog\n"
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
"                                      stop: 0 #4eff00, stop: 1 #4e8800); \n"
"}"));
        gridLayoutWidget = new QWidget(copyDialog);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(9, 140, 401, 38));
        layoutButtons = new QHBoxLayout(gridLayoutWidget);
        layoutButtons->setSpacing(5);
        layoutButtons->setObjectName(QStringLiteral("layoutButtons"));
        layoutButtons->setContentsMargins(5, 0, 0, 10);
        btnMore = new QPushButton(gridLayoutWidget);
        btnMore->setObjectName(QStringLiteral("btnMore"));
        btnMore->setMinimumSize(QSize(0, 0));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/res/arrow-down.svgz"), QSize(), QIcon::Normal, QIcon::Off);
        btnMore->setIcon(icon1);
        btnMore->setIconSize(QSize(16, 16));

        layoutButtons->addWidget(btnMore);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        layoutButtons->addItem(horizontalSpacer);

        btnPause = new QPushButton(gridLayoutWidget);
        btnPause->setObjectName(QStringLiteral("btnPause"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icons/res/media-playback-pause.svgz"), QSize(), QIcon::Normal, QIcon::Off);
        btnPause->setIcon(icon2);
        btnPause->setIconSize(QSize(16, 16));

        layoutButtons->addWidget(btnPause);

        btnSkip = new QPushButton(gridLayoutWidget);
        btnSkip->setObjectName(QStringLiteral("btnSkip"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icons/res/media-skip-forward.svgz"), QSize(), QIcon::Normal, QIcon::Off);
        btnSkip->setIcon(icon3);
        btnSkip->setIconSize(QSize(16, 16));

        layoutButtons->addWidget(btnSkip);

        btnCancel = new QPushButton(gridLayoutWidget);
        btnCancel->setObjectName(QStringLiteral("btnCancel"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/icons/res/process-stop.svgz"), QSize(), QIcon::Normal, QIcon::Off);
        btnCancel->setIcon(icon4);
        btnCancel->setIconSize(QSize(16, 16));

        layoutButtons->addWidget(btnCancel);

        pbarOverall = new QProgressBar(copyDialog);
        pbarOverall->setObjectName(QStringLiteral("pbarOverall"));
        pbarOverall->setGeometry(QRect(15, 116, 396, 15));
        pbarOverall->setValue(91);
        pbarCurrent = new QProgressBar(copyDialog);
        pbarCurrent->setObjectName(QStringLiteral("pbarCurrent"));
        pbarCurrent->setGeometry(QRect(15, 76, 396, 15));
        pbarCurrent->setValue(72);
        lblFrom = new QLabel(copyDialog);
        lblFrom->setObjectName(QStringLiteral("lblFrom"));
        lblFrom->setGeometry(QRect(80, 2, 331, 20));
        lblTo = new QLabel(copyDialog);
        lblTo->setObjectName(QStringLiteral("lblTo"));
        lblTo->setGeometry(QRect(80, 18, 331, 20));
        horizontalLayoutWidget = new QWidget(copyDialog);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setEnabled(true);
        horizontalLayoutWidget->setGeometry(QRect(80, 29, 341, 31));
        layoutTime = new QHBoxLayout(horizontalLayoutWidget);
        layoutTime->setObjectName(QStringLiteral("layoutTime"));
        layoutTime->setContentsMargins(0, 0, 8, 0);
        lblTimeElapsed = new QLabel(horizontalLayoutWidget);
        lblTimeElapsed->setObjectName(QStringLiteral("lblTimeElapsed"));
        lblTimeElapsed->setEnabled(true);

        layoutTime->addWidget(lblTimeElapsed);

        lblTimeRemaining = new QLabel(horizontalLayoutWidget);
        lblTimeRemaining->setObjectName(QStringLiteral("lblTimeRemaining"));
        lblTimeRemaining->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        layoutTime->addWidget(lblTimeRemaining);

        lblIcon = new QLabel(copyDialog);
        lblIcon->setObjectName(QStringLiteral("lblIcon"));
        lblIcon->setGeometry(QRect(20, 8, 45, 45));
        lblIcon->setPixmap(QPixmap(QString::fromUtf8(":/icons/res/copyIcon.png")));
        lblIcon->setScaledContents(true);
        lblFileCurrent = new QLabel(copyDialog);
        lblFileCurrent->setObjectName(QStringLiteral("lblFileCurrent"));
        lblFileCurrent->setGeometry(QRect(80, 57, 191, 16));
        lblCurrent = new QLabel(copyDialog);
        lblCurrent->setObjectName(QStringLiteral("lblCurrent"));
        lblCurrent->setGeometry(QRect(20, 57, 51, 16));
        lblSizeCurrent = new QLabel(copyDialog);
        lblSizeCurrent->setObjectName(QStringLiteral("lblSizeCurrent"));
        lblSizeCurrent->setGeometry(QRect(282, 57, 131, 20));
        lblSizeCurrent->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lblSizeOverall = new QLabel(copyDialog);
        lblSizeOverall->setObjectName(QStringLiteral("lblSizeOverall"));
        lblSizeOverall->setGeometry(QRect(262, 97, 151, 16));
        lblSizeOverall->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lblRate = new QLabel(copyDialog);
        lblRate->setObjectName(QStringLiteral("lblRate"));
        lblRate->setGeometry(QRect(190, 97, 61, 16));
        lblSpeed = new QLabel(copyDialog);
        lblSpeed->setObjectName(QStringLiteral("lblSpeed"));
        lblSpeed->setGeometry(QRect(151, 97, 41, 16));
        lblSpeed->setScaledContents(false);
        lblOverall = new QLabel(copyDialog);
        lblOverall->setObjectName(QStringLiteral("lblOverall"));
        lblOverall->setGeometry(QRect(20, 97, 51, 16));
        lblFileNo = new QLabel(copyDialog);
        lblFileNo->setObjectName(QStringLiteral("lblFileNo"));
        lblFileNo->setGeometry(QRect(80, 97, 61, 16));

        retranslateUi(copyDialog);

        QMetaObject::connectSlotsByName(copyDialog);
    } // setupUi

    void retranslateUi(QDialog *copyDialog)
    {
        copyDialog->setWindowTitle(QApplication::translate("copyDialog", "Copying (0%)", 0));
        btnMore->setText(QApplication::translate("copyDialog", "More", 0));
        btnPause->setText(QApplication::translate("copyDialog", "Pause", 0));
        btnSkip->setText(QApplication::translate("copyDialog", "Skip", 0));
        btnCancel->setText(QApplication::translate("copyDialog", "Cancel", 0));
        lblFrom->setText(QApplication::translate("copyDialog", "<html><head/><body><p>from <span style=\" font-weight:600;\">/home/CodePandora/Projects</span></p></body></html>", 0));
        lblTo->setText(QApplication::translate("copyDialog", "<html><head/><body><p>to &nbsp;&nbsp;&nbsp;<span style=\" font-weight:600;\">/home/CodePandora/Documents</span></p></body></html>", 0));
        lblTimeElapsed->setText(QApplication::translate("copyDialog", "Elapsed Time: 00:00:00", 0));
        lblTimeRemaining->setText(QApplication::translate("copyDialog", "Remaining Time: 00:00:00", 0));
        lblIcon->setText(QString());
        lblFileCurrent->setText(QApplication::translate("copyDialog", "<html><head/><body><p><span style=\" font-weight:600;\">Tux-transfer-github.zip</span></p></body></html>", 0));
        lblCurrent->setText(QApplication::translate("copyDialog", "<html><head/><body><p><span style=\" font-weight:600;\">Current</span></p></body></html>", 0));
        lblSizeCurrent->setText(QApplication::translate("copyDialog", "20.0 MB / 27.5 MB", 0));
        lblSizeOverall->setText(QApplication::translate("copyDialog", "168.5 MB / 182.5 MB", 0));
        lblRate->setText(QApplication::translate("copyDialog", "41MB/s", 0));
        lblSpeed->setText(QApplication::translate("copyDialog", "Speed:", 0));
        lblOverall->setText(QApplication::translate("copyDialog", "<html><head/><body><p><span style=\" font-weight:600;\">Overall</span></p></body></html>", 0));
        lblFileNo->setText(QApplication::translate("copyDialog", "8 / 10", 0));
    } // retranslateUi

};

namespace Ui {
    class copyDialog: public Ui_copyDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // COPYDIALOG_H
