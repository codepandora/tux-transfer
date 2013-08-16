/********************************************************************************
** Form generated from reading UI file 'fileExistsDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef FILEEXISTSDIALOG_H
#define FILEEXISTSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_fileExistsDialog
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *btnRenameOlder;
    QLabel *lblFileInfo2;
    QLabel *lblFileInfo1;
    QPushButton *btnRename;
    QPushButton *btnSkip;
    QPushButton *btnRenameAll;
    QLabel *lblFile2;
    QLabel *lblFile1;
    QLabel *lblMsg2;
    QPushButton *btnOverwriteAll;
    QPushButton *btnOverwriteOlder;
    QPushButton *btnCancel;
    QPushButton *btnSkipAll;
    QPushButton *btnOverwrite;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *lblMsg;

    void setupUi(QDialog *fileExistsDialog)
    {
        if (fileExistsDialog->objectName().isEmpty())
            fileExistsDialog->setObjectName(QStringLiteral("fileExistsDialog"));
        fileExistsDialog->resize(570, 180);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(fileExistsDialog->sizePolicy().hasHeightForWidth());
        fileExistsDialog->setSizePolicy(sizePolicy);
        fileExistsDialog->setMinimumSize(QSize(570, 180));
        fileExistsDialog->setMaximumSize(QSize(570, 180));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/res/copyIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        fileExistsDialog->setWindowIcon(icon);
        fileExistsDialog->setStyleSheet(QLatin1String("QDialog\n"
"{\n"
"background:#222222;\n"
"}\n"
"\n"
"QLabel\n"
"{\n"
"color:#ffffff;\n"
"}\n"
"\n"
"#lblMsg,#lblMsg2\n"
"{\n"
"color:#fff000;\n"
"}"));
        gridLayoutWidget = new QWidget(fileExistsDialog);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 566, 178));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(3);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(10, 2, 5, 2);
        btnRenameOlder = new QPushButton(gridLayoutWidget);
        btnRenameOlder->setObjectName(QStringLiteral("btnRenameOlder"));

        gridLayout->addWidget(btnRenameOlder, 3, 3, 1, 1);

        lblFileInfo2 = new QLabel(gridLayoutWidget);
        lblFileInfo2->setObjectName(QStringLiteral("lblFileInfo2"));
        lblFileInfo2->setMinimumSize(QSize(0, 18));
        lblFileInfo2->setMaximumSize(QSize(16777215, 18));
        lblFileInfo2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lblFileInfo2, 5, 0, 1, 1);

        lblFileInfo1 = new QLabel(gridLayoutWidget);
        lblFileInfo1->setObjectName(QStringLiteral("lblFileInfo1"));
        lblFileInfo1->setMinimumSize(QSize(0, 18));
        lblFileInfo1->setMaximumSize(QSize(16777215, 18));
        lblFileInfo1->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        lblFileInfo1->setWordWrap(false);

        gridLayout->addWidget(lblFileInfo1, 2, 0, 1, 1);

        btnRename = new QPushButton(gridLayoutWidget);
        btnRename->setObjectName(QStringLiteral("btnRename"));

        gridLayout->addWidget(btnRename, 3, 1, 1, 1);

        btnSkip = new QPushButton(gridLayoutWidget);
        btnSkip->setObjectName(QStringLiteral("btnSkip"));

        gridLayout->addWidget(btnSkip, 5, 1, 1, 1);

        btnRenameAll = new QPushButton(gridLayoutWidget);
        btnRenameAll->setObjectName(QStringLiteral("btnRenameAll"));

        gridLayout->addWidget(btnRenameAll, 3, 2, 1, 1);

        lblFile2 = new QLabel(gridLayoutWidget);
        lblFile2->setObjectName(QStringLiteral("lblFile2"));
        lblFile2->setMinimumSize(QSize(0, 20));
        lblFile2->setMaximumSize(QSize(16777215, 20));
        lblFile2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lblFile2, 4, 0, 1, 1);

        lblFile1 = new QLabel(gridLayoutWidget);
        lblFile1->setObjectName(QStringLiteral("lblFile1"));
        lblFile1->setMinimumSize(QSize(0, 20));
        lblFile1->setMaximumSize(QSize(16777215, 20));
        lblFile1->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lblFile1, 1, 0, 1, 1);

        lblMsg2 = new QLabel(gridLayoutWidget);
        lblMsg2->setObjectName(QStringLiteral("lblMsg2"));
        lblMsg2->setMinimumSize(QSize(280, 0));
        lblMsg2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lblMsg2->setMargin(0);
        lblMsg2->setIndent(35);

        gridLayout->addWidget(lblMsg2, 3, 0, 1, 1);

        btnOverwriteAll = new QPushButton(gridLayoutWidget);
        btnOverwriteAll->setObjectName(QStringLiteral("btnOverwriteAll"));

        gridLayout->addWidget(btnOverwriteAll, 1, 2, 1, 1);

        btnOverwriteOlder = new QPushButton(gridLayoutWidget);
        btnOverwriteOlder->setObjectName(QStringLiteral("btnOverwriteOlder"));

        gridLayout->addWidget(btnOverwriteOlder, 1, 3, 1, 1);

        btnCancel = new QPushButton(gridLayoutWidget);
        btnCancel->setObjectName(QStringLiteral("btnCancel"));

        gridLayout->addWidget(btnCancel, 5, 3, 1, 1);

        btnSkipAll = new QPushButton(gridLayoutWidget);
        btnSkipAll->setObjectName(QStringLiteral("btnSkipAll"));

        gridLayout->addWidget(btnSkipAll, 5, 2, 1, 1);

        btnOverwrite = new QPushButton(gridLayoutWidget);
        btnOverwrite->setObjectName(QStringLiteral("btnOverwrite"));

        gridLayout->addWidget(btnOverwrite, 1, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Maximum);

        gridLayout->addItem(verticalSpacer, 0, 2, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(30, 30));
        label->setPixmap(QPixmap(QString::fromUtf8(":/icons/res/moveIcon.png")));
        label->setScaledContents(true);

        horizontalLayout->addWidget(label);

        lblMsg = new QLabel(gridLayoutWidget);
        lblMsg->setObjectName(QStringLiteral("lblMsg"));
        lblMsg->setMinimumSize(QSize(0, 25));
        lblMsg->setMaximumSize(QSize(16777215, 25));
        lblMsg->setScaledContents(false);

        horizontalLayout->addWidget(lblMsg);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 2);


        retranslateUi(fileExistsDialog);

        QMetaObject::connectSlotsByName(fileExistsDialog);
    } // setupUi

    void retranslateUi(QDialog *fileExistsDialog)
    {
        fileExistsDialog->setWindowTitle(QApplication::translate("fileExistsDialog", "File Already Exists", 0));
        btnRenameOlder->setText(QApplication::translate("fileExistsDialog", "Older", 0));
        lblFileInfo2->setText(QApplication::translate("fileExistsDialog", "<html><head/><body><p>4,160 bytes  12/08/2013 08:45:03 PM</p></body></html>", 0));
        lblFileInfo1->setText(QApplication::translate("fileExistsDialog", "<html><head/><body><p>4,160 bytes  12/08/2013 08:45:03 PM</p></body></html>", 0));
        btnRename->setText(QApplication::translate("fileExistsDialog", "Rename", 0));
        btnSkip->setText(QApplication::translate("fileExistsDialog", "Skip", 0));
        btnRenameAll->setText(QApplication::translate("fileExistsDialog", "Rename All", 0));
        lblFile2->setText(QApplication::translate("fileExistsDialog", "<html><head/><body><p><span style=\" font-weight:600;\">/home/Downloads/Tux Transfer.zip</span></p></body></html>", 0));
        lblFile1->setText(QApplication::translate("fileExistsDialog", "<html><head/><body><p><span style=\" font-weight:600;\">/home/Documents/Tux Transfer.zip</span></p></body></html>", 0));
        lblMsg2->setText(QApplication::translate("fileExistsDialog", "<html><head/><body><p><span style=\" font-size:10pt;\">with this one?</span></p></body></html>", 0));
        btnOverwriteAll->setText(QApplication::translate("fileExistsDialog", "Overwrite All", 0));
        btnOverwriteOlder->setText(QApplication::translate("fileExistsDialog", "Older", 0));
        btnCancel->setText(QApplication::translate("fileExistsDialog", "Cancel", 0));
        btnSkipAll->setText(QApplication::translate("fileExistsDialog", "Skip All", 0));
        btnOverwrite->setText(QApplication::translate("fileExistsDialog", "Overwrite", 0));
        label->setText(QString());
        lblMsg->setText(QApplication::translate("fileExistsDialog", "<html><head/><body><p><span style=\" font-size:10pt;\">Would you like to replace the existing file </span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class fileExistsDialog: public Ui_fileExistsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // FILEEXISTSDIALOG_H
