/********************************************************************************
** Form generated from reading UI file 'helper.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELPER_H
#define UI_HELPER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Helper
{
public:
    QTextBrowser *textBrowser;

    void setupUi(QWidget *Helper)
    {
        if (Helper->objectName().isEmpty())
            Helper->setObjectName(QStringLiteral("Helper"));
        Helper->resize(900, 650);
        Helper->setMinimumSize(QSize(900, 650));
        Helper->setMaximumSize(QSize(900, 650));
        QIcon icon;
        icon.addFile(QStringLiteral("../src/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        Helper->setWindowIcon(icon);
        Helper->setStyleSheet(QStringLiteral("QTextBrowser {background-color:  rgb(142, 154, 76)}"));
        textBrowser = new QTextBrowser(Helper);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(0, 0, 899, 651));
        textBrowser->setMaximumSize(QSize(16777215, 16777215));
        textBrowser->setStyleSheet(QLatin1String("background: rgb(252, 238, 251);\n"
"line-height: 2;"));

        retranslateUi(Helper);

        QMetaObject::connectSlotsByName(Helper);
    } // setupUi

    void retranslateUi(QWidget *Helper)
    {
        Helper->setWindowTitle(QApplication::translate("Helper", "\320\237\320\276\320\274\320\276\321\211\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Helper: public Ui_Helper {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELPER_H
