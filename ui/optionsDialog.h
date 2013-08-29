/********************************************************************************
** Form generated from reading UI file 'optionsDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef OPTIONSDIALOG_H
#define OPTIONSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_optionsDialog
{
public:
    QDialogButtonBox *buttonBox;
    QTabWidget *tabOptions;
    QWidget *tabGeneral;
    QWidget *tabEngine;
    QWidget *tabInterface;
    QWidget *tabDebug;
    QWidget *tabLog;
    QLabel *lblLogo;
    QLabel *lblOptions;

    void setupUi(QDialog *optionsDialog)
    {
        if (optionsDialog->objectName().isEmpty())
            optionsDialog->setObjectName(QStringLiteral("optionsDialog"));
        optionsDialog->resize(600, 400);
        optionsDialog->setMinimumSize(QSize(600, 400));
        optionsDialog->setMaximumSize(QSize(600, 400));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/res/copyIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        optionsDialog->setWindowIcon(icon);
        optionsDialog->setStyleSheet(QLatin1String("QDialog\n"
"{\n"
"background:#222222;\n"
"}\n"
"\n"
"QLabel\n"
"{\n"
" color:#ffffff;\n"
"}"));
        buttonBox = new QDialogButtonBox(optionsDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(370, 370, 221, 23));
        buttonBox->setStandardButtons(QDialogButtonBox::Apply|QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        tabOptions = new QTabWidget(optionsDialog);
        tabOptions->setObjectName(QStringLiteral("tabOptions"));
        tabOptions->setGeometry(QRect(30, 80, 561, 281));
        tabGeneral = new QWidget();
        tabGeneral->setObjectName(QStringLiteral("tabGeneral"));
        tabOptions->addTab(tabGeneral, QString());
        tabEngine = new QWidget();
        tabEngine->setObjectName(QStringLiteral("tabEngine"));
        tabOptions->addTab(tabEngine, QString());
        tabInterface = new QWidget();
        tabInterface->setObjectName(QStringLiteral("tabInterface"));
        tabOptions->addTab(tabInterface, QString());
        tabDebug = new QWidget();
        tabDebug->setObjectName(QStringLiteral("tabDebug"));
        tabOptions->addTab(tabDebug, QString());
        tabLog = new QWidget();
        tabLog->setObjectName(QStringLiteral("tabLog"));
        tabOptions->addTab(tabLog, QString());
        lblLogo = new QLabel(optionsDialog);
        lblLogo->setObjectName(QStringLiteral("lblLogo"));
        lblLogo->setGeometry(QRect(30, 5, 71, 71));
        lblLogo->setPixmap(QPixmap(QString::fromUtf8(":/logo/res/tux-transfer.png")));
        lblLogo->setScaledContents(true);
        lblOptions = new QLabel(optionsDialog);
        lblOptions->setObjectName(QStringLiteral("lblOptions"));
        lblOptions->setGeometry(QRect(110, 20, 261, 41));
        QFont font;
        font.setFamily(QStringLiteral("Segoe UI"));
        lblOptions->setFont(font);

        retranslateUi(optionsDialog);

        tabOptions->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(optionsDialog);
    } // setupUi

    void retranslateUi(QDialog *optionsDialog)
    {
        optionsDialog->setWindowTitle(QApplication::translate("optionsDialog", "Options", 0));
        tabOptions->setTabText(tabOptions->indexOf(tabGeneral), QApplication::translate("optionsDialog", "General", 0));
        tabOptions->setTabText(tabOptions->indexOf(tabEngine), QApplication::translate("optionsDialog", "Transfer Engine", 0));
        tabOptions->setTabText(tabOptions->indexOf(tabInterface), QApplication::translate("optionsDialog", "Interface", 0));
        tabOptions->setTabText(tabOptions->indexOf(tabDebug), QApplication::translate("optionsDialog", "Debug", 0));
        tabOptions->setTabText(tabOptions->indexOf(tabLog), QApplication::translate("optionsDialog", "Log", 0));
        lblLogo->setText(QString());
        lblOptions->setText(QApplication::translate("optionsDialog", "<html><head/><body><p><span style=\" font-size:16pt;\">Tux Transfer Options</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class optionsDialog: public Ui_optionsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // OPTIONSDIALOG_H
