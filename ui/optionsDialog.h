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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_optionsDialog
{
public:
    QDialogButtonBox *buttonBox;
    QTabWidget *tabOptions;
    QWidget *tabGeneral;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QCheckBox *checkBox;
    QSpinBox *spinBox;
    QCheckBox *checkBox_2;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
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
"}\n"
"\n"
"#tabGeneral QLabel\n"
"{\n"
" color:#000;\n"
"}"));
        buttonBox = new QDialogButtonBox(optionsDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(360, 370, 221, 23));
        buttonBox->setStandardButtons(QDialogButtonBox::Apply|QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        tabOptions = new QTabWidget(optionsDialog);
        tabOptions->setObjectName(QStringLiteral("tabOptions"));
        tabOptions->setGeometry(QRect(20, 80, 561, 281));
        tabGeneral = new QWidget();
        tabGeneral->setObjectName(QStringLiteral("tabGeneral"));
        label = new QLabel(tabGeneral);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 311, 16));
        label_2 = new QLabel(tabGeneral);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 30, 311, 16));
        label_3 = new QLabel(tabGeneral);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 50, 311, 16));
        label_4 = new QLabel(tabGeneral);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 75, 311, 16));
        label_5 = new QLabel(tabGeneral);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 95, 311, 16));
        checkBox = new QCheckBox(tabGeneral);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(340, 10, 70, 17));
        checkBox->setChecked(true);
        spinBox = new QSpinBox(tabGeneral);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(340, 30, 161, 21));
        spinBox->setMaximum(4096);
        spinBox->setSingleStep(1024);
        spinBox->setValue(1024);
        checkBox_2 = new QCheckBox(tabGeneral);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setGeometry(QRect(340, 50, 70, 17));
        comboBox = new QComboBox(tabGeneral);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(340, 70, 161, 20));
        comboBox->setEditable(false);
        comboBox_2 = new QComboBox(tabGeneral);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(340, 95, 161, 20));
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
        lblLogo->setGeometry(QRect(20, 5, 71, 71));
        lblLogo->setPixmap(QPixmap(QString::fromUtf8(":/logo/res/tux-transfer.png")));
        lblLogo->setScaledContents(true);
        lblOptions = new QLabel(optionsDialog);
        lblOptions->setObjectName(QStringLiteral("lblOptions"));
        lblOptions->setGeometry(QRect(100, 20, 261, 41));
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
        label->setText(QApplication::translate("optionsDialog", "Keep the file date", 0));
        label_2->setText(QApplication::translate("optionsDialog", "Block size", 0));
        label_3->setText(QApplication::translate("optionsDialog", "Auto start the transfer", 0));
        label_4->setText(QApplication::translate("optionsDialog", "When folder error", 0));
        label_5->setText(QApplication::translate("optionsDialog", "When folder collision", 0));
        checkBox->setText(QString());
        spinBox->setSuffix(QApplication::translate("optionsDialog", "KB", 0));
        checkBox_2->setText(QString());
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("optionsDialog", "Ask", 0)
        );
        comboBox->setCurrentText(QApplication::translate("optionsDialog", "Ask", 0));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("optionsDialog", "Ask", 0)
        );
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
