/********************************************************************************
** Form generated from reading UI file 'folderExistsDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef FOLDEREXISTSDIALOG_H
#define FOLDEREXISTSDIALOG_H

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

class Ui_folderExistsDialog
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *btnRenameOlder;
    QLabel *lblFolderInfo2;
    QLabel *lblFolderInfo1;
    QPushButton *btnRename;
    QPushButton *btnSkip;
    QPushButton *btnRenameAll;
    QLabel *lblFolder2;
    QLabel *lblFolder1;
    QLabel *lblMsg2;
    QPushButton *btnOverwriteAll;
    QPushButton *btnOverwriteOlder;
    QPushButton *btnCancel;
    QPushButton *btnSkipAll;
    QPushButton *btnOverwrite;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *lblMsg;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *folderExistsDialog)
    {
        if (folderExistsDialog->objectName().isEmpty())
            folderExistsDialog->setObjectName(QStringLiteral("folderExistsDialog"));
        folderExistsDialog->resize(550, 180);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(folderExistsDialog->sizePolicy().hasHeightForWidth());
        folderExistsDialog->setSizePolicy(sizePolicy);
        folderExistsDialog->setMinimumSize(QSize(550, 180));
        folderExistsDialog->setMaximumSize(QSize(550, 180));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/res/copyIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        folderExistsDialog->setWindowIcon(icon);
        folderExistsDialog->setStyleSheet(QLatin1String("QDialog\n"
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
        gridLayoutWidget = new QWidget(folderExistsDialog);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 540, 178));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(3);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(10, 2, 5, 2);
        btnRenameOlder = new QPushButton(gridLayoutWidget);
        btnRenameOlder->setObjectName(QStringLiteral("btnRenameOlder"));

        gridLayout->addWidget(btnRenameOlder, 3, 3, 1, 1);

        lblFolderInfo2 = new QLabel(gridLayoutWidget);
        lblFolderInfo2->setObjectName(QStringLiteral("lblFolderInfo2"));
        lblFolderInfo2->setMinimumSize(QSize(0, 18));
        lblFolderInfo2->setMaximumSize(QSize(16777215, 18));
        lblFolderInfo2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lblFolderInfo2, 5, 0, 1, 1);

        lblFolderInfo1 = new QLabel(gridLayoutWidget);
        lblFolderInfo1->setObjectName(QStringLiteral("lblFolderInfo1"));
        lblFolderInfo1->setMinimumSize(QSize(0, 18));
        lblFolderInfo1->setMaximumSize(QSize(16777215, 18));
        lblFolderInfo1->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        lblFolderInfo1->setWordWrap(false);

        gridLayout->addWidget(lblFolderInfo1, 2, 0, 1, 1);

        btnRename = new QPushButton(gridLayoutWidget);
        btnRename->setObjectName(QStringLiteral("btnRename"));

        gridLayout->addWidget(btnRename, 3, 1, 1, 1);

        btnSkip = new QPushButton(gridLayoutWidget);
        btnSkip->setObjectName(QStringLiteral("btnSkip"));

        gridLayout->addWidget(btnSkip, 5, 1, 1, 1);

        btnRenameAll = new QPushButton(gridLayoutWidget);
        btnRenameAll->setObjectName(QStringLiteral("btnRenameAll"));

        gridLayout->addWidget(btnRenameAll, 3, 2, 1, 1);

        lblFolder2 = new QLabel(gridLayoutWidget);
        lblFolder2->setObjectName(QStringLiteral("lblFolder2"));
        lblFolder2->setMinimumSize(QSize(0, 20));
        lblFolder2->setMaximumSize(QSize(16777215, 20));
        lblFolder2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lblFolder2, 4, 0, 1, 1);

        lblFolder1 = new QLabel(gridLayoutWidget);
        lblFolder1->setObjectName(QStringLiteral("lblFolder1"));
        lblFolder1->setMinimumSize(QSize(0, 20));
        lblFolder1->setMaximumSize(QSize(16777215, 20));
        lblFolder1->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lblFolder1, 1, 0, 1, 1);

        lblMsg2 = new QLabel(gridLayoutWidget);
        lblMsg2->setObjectName(QStringLiteral("lblMsg2"));
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


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Maximum);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);


        retranslateUi(folderExistsDialog);

        QMetaObject::connectSlotsByName(folderExistsDialog);
    } // setupUi

    void retranslateUi(QDialog *folderExistsDialog)
    {
        folderExistsDialog->setWindowTitle(QApplication::translate("folderExistsDialog", "Folder Already Exists", 0));
        btnRenameOlder->setText(QApplication::translate("folderExistsDialog", "Older", 0));
        lblFolderInfo2->setText(QApplication::translate("folderExistsDialog", "<html><head/><body><p>Date created: 12/08/2013 08:45:03 PM</p></body></html>", 0));
        lblFolderInfo1->setText(QApplication::translate("folderExistsDialog", "<html><head/><body><p>Date created: 12/08/2013 08:45:03 PM</p></body></html>", 0));
        btnRename->setText(QApplication::translate("folderExistsDialog", "Rename", 0));
        btnSkip->setText(QApplication::translate("folderExistsDialog", "Skip", 0));
        btnRenameAll->setText(QApplication::translate("folderExistsDialog", "Rename All", 0));
        lblFolder2->setText(QApplication::translate("folderExistsDialog", "<html><head/><body><p><span style=\" font-weight:600;\">/home/Downloads/Tux</span></p></body></html>", 0));
        lblFolder1->setText(QApplication::translate("folderExistsDialog", "<html><head/><body><p><span style=\" font-weight:600;\">/home/Documents/Tux</span></p></body></html>", 0));
        lblMsg2->setText(QApplication::translate("folderExistsDialog", "<html><head/><body><p><span style=\" font-size:10pt;\">with this one?</span></p></body></html>", 0));
        btnOverwriteAll->setText(QApplication::translate("folderExistsDialog", "Overwrite All", 0));
        btnOverwriteOlder->setText(QApplication::translate("folderExistsDialog", "Older", 0));
        btnCancel->setText(QApplication::translate("folderExistsDialog", "Cancel", 0));
        btnSkipAll->setText(QApplication::translate("folderExistsDialog", "Skip All", 0));
        btnOverwrite->setText(QApplication::translate("folderExistsDialog", "Overwrite", 0));
        label->setText(QString());
        lblMsg->setText(QApplication::translate("folderExistsDialog", "<html><head/><body><p><span style=\" font-size:10pt;\">Would you like to replace the existing folder</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class folderExistsDialog: public Ui_folderExistsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // FOLDEREXISTSDIALOG_H
