/********************************************************************************
** Form generated from reading UI file 'copyMore.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef COPYMORE_H
#define COPYMORE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_copyMore
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QPushButton *btnDown;
    QPushButton *btnAdd;
    QPushButton *btnUp;
    QPushButton *btnRemove;
    QTableView *tableView;

    void setupUi(QWidget *copyMore)
    {
        if (copyMore->objectName().isEmpty())
            copyMore->setObjectName(QStringLiteral("copyMore"));
        copyMore->resize(420, 180);
        copyMore->setMaximumSize(QSize(420, 500));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/res/copyIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        copyMore->setWindowIcon(icon);
        copyMore->setStyleSheet(QLatin1String("QWidget\n"
"{\n"
"background:#222222;\n"
"}\n"
"\n"
"QTableView\n"
"{\n"
"background:#222222;\n"
"color:#ffffff;\n"
"border:1px solid #000;\n"
"}"));
        gridLayoutWidget = new QWidget(copyMore);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 421, 181));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetNoConstraint);
        gridLayout->setContentsMargins(2, 2, 3, 3);
        verticalSpacer = new QSpacerItem(10, 65, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 4, 0, 1, 1);

        btnDown = new QPushButton(gridLayoutWidget);
        btnDown->setObjectName(QStringLiteral("btnDown"));
        btnDown->setMaximumSize(QSize(30, 16777215));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/res/arrow-down-double.svgz"), QSize(), QIcon::Normal, QIcon::Off);
        btnDown->setIcon(icon1);
        btnDown->setIconSize(QSize(16, 16));

        gridLayout->addWidget(btnDown, 3, 0, 1, 1);

        btnAdd = new QPushButton(gridLayoutWidget);
        btnAdd->setObjectName(QStringLiteral("btnAdd"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnAdd->sizePolicy().hasHeightForWidth());
        btnAdd->setSizePolicy(sizePolicy);
        btnAdd->setMaximumSize(QSize(30, 16777215));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icons/res/list-add.svgz"), QSize(), QIcon::Normal, QIcon::Off);
        btnAdd->setIcon(icon2);
        btnAdd->setIconSize(QSize(16, 16));

        gridLayout->addWidget(btnAdd, 0, 0, 1, 1);

        btnUp = new QPushButton(gridLayoutWidget);
        btnUp->setObjectName(QStringLiteral("btnUp"));
        btnUp->setMaximumSize(QSize(30, 16777215));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icons/res/arrow-up-double.svgz"), QSize(), QIcon::Normal, QIcon::Off);
        btnUp->setIcon(icon3);
        btnUp->setIconSize(QSize(16, 16));

        gridLayout->addWidget(btnUp, 2, 0, 1, 1);

        btnRemove = new QPushButton(gridLayoutWidget);
        btnRemove->setObjectName(QStringLiteral("btnRemove"));
        sizePolicy.setHeightForWidth(btnRemove->sizePolicy().hasHeightForWidth());
        btnRemove->setSizePolicy(sizePolicy);
        btnRemove->setMinimumSize(QSize(0, 0));
        btnRemove->setMaximumSize(QSize(30, 16777215));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/icons/res/application-exit.svgz"), QSize(), QIcon::Normal, QIcon::Off);
        btnRemove->setIcon(icon4);
        btnRemove->setIconSize(QSize(16, 16));

        gridLayout->addWidget(btnRemove, 1, 0, 1, 1);

        tableView = new QTableView(gridLayoutWidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tableView->sizePolicy().hasHeightForWidth());
        tableView->setSizePolicy(sizePolicy1);
        tableView->setMaximumSize(QSize(16777215, 180));

        gridLayout->addWidget(tableView, 0, 1, 5, 1);


        retranslateUi(copyMore);

        QMetaObject::connectSlotsByName(copyMore);
    } // setupUi

    void retranslateUi(QWidget *copyMore)
    {
        copyMore->setWindowTitle(QApplication::translate("copyMore", "More", 0));
        btnDown->setText(QString());
        btnAdd->setText(QString());
        btnUp->setText(QString());
        btnRemove->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class copyMore: public Ui_copyMore {};
} // namespace Ui

QT_END_NAMESPACE

#endif // COPYMORE_H
