/********************************************************************************
** Form generated from reading UI file 'fileErrorDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef FILEERRORDIALOG_H
#define FILEERRORDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_fileErrorDialog
{
public:
    QPushButton *btnSkip;
    QPushButton *btnCancel;
    QLabel *lblIcon;
    QLabel *lblFileError;
    QLabel *lblFileName;
    QLabel *label;

    void setupUi(QDialog *fileErrorDialog)
    {
        if (fileErrorDialog->objectName().isEmpty())
            fileErrorDialog->setObjectName(QStringLiteral("fileErrorDialog"));
        fileErrorDialog->resize(350, 160);
        fileErrorDialog->setMinimumSize(QSize(350, 160));
        fileErrorDialog->setMaximumSize(QSize(350, 160));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/res/copyIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        fileErrorDialog->setWindowIcon(icon);
        fileErrorDialog->setStyleSheet(QLatin1String("QDialog\n"
"{\n"
"background:#222222;\n"
"}\n"
"\n"
"QLabel\n"
"{\n"
"color:#ffffff;\n"
"}\n"
"\n"
"#lblFileError\n"
"{\n"
"color:#ff6900;\n"
"}"));
        btnSkip = new QPushButton(fileErrorDialog);
        btnSkip->setObjectName(QStringLiteral("btnSkip"));
        btnSkip->setGeometry(QRect(180, 130, 75, 23));
        btnCancel = new QPushButton(fileErrorDialog);
        btnCancel->setObjectName(QStringLiteral("btnCancel"));
        btnCancel->setGeometry(QRect(260, 130, 75, 23));
        lblIcon = new QLabel(fileErrorDialog);
        lblIcon->setObjectName(QStringLiteral("lblIcon"));
        lblIcon->setGeometry(QRect(10, 5, 50, 50));
        lblIcon->setPixmap(QPixmap(QString::fromUtf8(":/icons/res/process-stop.svgz")));
        lblIcon->setScaledContents(true);
        lblFileError = new QLabel(fileErrorDialog);
        lblFileError->setObjectName(QStringLiteral("lblFileError"));
        lblFileError->setGeometry(QRect(70, 10, 301, 31));
        QFont font;
        font.setFamily(QStringLiteral("Segoe UI"));
        lblFileError->setFont(font);
        lblFileName = new QLabel(fileErrorDialog);
        lblFileName->setObjectName(QStringLiteral("lblFileName"));
        lblFileName->setGeometry(QRect(70, 50, 311, 21));
        lblFileName->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label = new QLabel(fileErrorDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 75, 211, 61));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        retranslateUi(fileErrorDialog);

        QMetaObject::connectSlotsByName(fileErrorDialog);
    } // setupUi

    void retranslateUi(QDialog *fileErrorDialog)
    {
        fileErrorDialog->setWindowTitle(QApplication::translate("fileErrorDialog", "File Error", 0));
        btnSkip->setText(QApplication::translate("fileErrorDialog", "Skip", 0));
        btnCancel->setText(QApplication::translate("fileErrorDialog", "Cancel ", 0));
        lblIcon->setText(QString());
        lblFileError->setText(QApplication::translate("fileErrorDialog", "<html><head/><body><p><span style=\" font-size:16pt;\">File Transfer Error</span></p></body></html>", 0));
        lblFileName->setText(QApplication::translate("fileErrorDialog", "<html><head/><body><p><span style=\" font-size:10pt;\">File error: </span><span style=\" font-size:10pt; font-weight:600;\">Tux.doc</span></p></body></html>", 0));
        label->setText(QApplication::translate("fileErrorDialog", "<html><head/><body><p>Skip current file?<br />Or<br />Cancel transfer operation?</p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class fileErrorDialog: public Ui_fileErrorDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // FILEERRORDIALOG_H
