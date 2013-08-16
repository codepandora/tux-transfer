/********************************************************************************
** Form generated from reading UI file 'aboutDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_aboutDialog
{
public:
    QLabel *lblBanner;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *btnOk;

    void setupUi(QDialog *aboutDialog)
    {
        if (aboutDialog->objectName().isEmpty())
            aboutDialog->setObjectName(QStringLiteral("aboutDialog"));
        aboutDialog->resize(420, 320);
        aboutDialog->setMinimumSize(QSize(400, 300));
        aboutDialog->setMaximumSize(QSize(420, 320));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/res/copyIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        aboutDialog->setWindowIcon(icon);
        aboutDialog->setStyleSheet(QLatin1String("QDialog\n"
"{\n"
"background:#222222;\n"
"}\n"
"\n"
"QLabel\n"
"{\n"
"color:#ffffff;\n"
"}\n"
""));
        aboutDialog->setModal(false);
        lblBanner = new QLabel(aboutDialog);
        lblBanner->setObjectName(QStringLiteral("lblBanner"));
        lblBanner->setGeometry(QRect(20, 10, 91, 91));
        lblBanner->setPixmap(QPixmap(QString::fromUtf8(":/logo/res/tux-transfer.png")));
        lblBanner->setScaledContents(true);
        label = new QLabel(aboutDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(120, 10, 290, 61));
        QFont font;
        font.setFamily(QStringLiteral("Segoe UI"));
        label->setFont(font);
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_2 = new QLabel(aboutDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(260, 70, 101, 21));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_3 = new QLabel(aboutDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 110, 351, 180));
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        btnOk = new QPushButton(aboutDialog);
        btnOk->setObjectName(QStringLiteral("btnOk"));
        btnOk->setGeometry(QRect(314, 290, 71, 23));

        retranslateUi(aboutDialog);

        QMetaObject::connectSlotsByName(aboutDialog);
    } // setupUi

    void retranslateUi(QDialog *aboutDialog)
    {
        aboutDialog->setWindowTitle(QApplication::translate("aboutDialog", "About", 0));
        lblBanner->setText(QString());
        label->setText(QApplication::translate("aboutDialog", "<html><head/><body><p><span style=\" font-size:36pt;\">Tux Transfer</span></p></body></html>", 0));
        label_2->setText(QApplication::translate("aboutDialog", "version 0.1", 0));
        label_3->setText(QApplication::translate("aboutDialog", "<html><head/><body><p><span style=\" font-size:10pt;\">Tux Transfer is an advanced file copier for GNU Linux.</span><br/></p><p>Developed by</p><p>Bjorn Mascarenhas</p><p>Sumedh More<br/></p><p>Copyright \302\251 2013 CodePandora | <a href=\"http://www.codepandora.com\"><span style=\" text-decoration: underline; color:#00ffff;\">www.codepandora.com</span></a></p></body></html>", 0));
        btnOk->setText(QApplication::translate("aboutDialog", "OK", 0));
    } // retranslateUi

};

namespace Ui {
    class aboutDialog: public Ui_aboutDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // ABOUTDIALOG_H
