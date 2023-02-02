/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *bestButton;
    QLineEdit *searchBox;
    QTextEdit *outputBox;
    QPushButton *categoriesButton;
    QTableView *recipesTable;
    QPushButton *addButton;
    QPushButton *edit_bestButton;
    QLabel *picLabel;
    QPushButton *editButton;
    QPushButton *deleteButton;
    QLineEdit *nameLabel;
    QPushButton *filterButton;
    QPushButton *helpButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(1125, 645);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(1125, 645));
        MainWindow->setMaximumSize(QSize(1125, 645));
        MainWindow->setCursor(QCursor(Qt::ArrowCursor));
        MainWindow->setMouseTracking(false);
        QIcon icon;
        icon.addFile(QStringLiteral("../src/default.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QLatin1String("#MainWindow {background: rgb(252, 238, 251);}\n"
"QPushButton {\n"
"	background: rgb(239, 187, 238);\n"
"	border-radius: 10px;\n"
"	border-width: 0px;}\n"
"QPushButton:hover {\n"
"	background: rgb(244, 204, 242);\n"
"	border-width: 0px;\n"
"	border-radius: 10px;}\n"
"QLineEdit {background: rgb(239, 187, 238);}\n"
"#nameEdit {border-radius: 15px;\n"
"	border-width: 1px;\n"
"	min-height: 30px;\n"
"	max-height: 30px;\n"
"	min-width: 250px;\n"
"	max-width: 250px;}\n"
"#searchBox {\n"
"	border-radius: 5px;\n"
"	border-width: 1px;\n"
"	min-height: 30px;\n"
"	max-height: 30px;\n"
"	min-width: 250px;\n"
"	max-width: 250px;\n"
"	 }\n"
"#recipesTable {background: rgb(252, 238, 251);}\n"
"#outputBox  {}\n"
"\n"
"\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        bestButton = new QPushButton(centralwidget);
        bestButton->setObjectName(QStringLiteral("bestButton"));
        bestButton->setGeometry(QRect(190, 50, 41, 41));
        QFont font;
        font.setFamily(QStringLiteral("Calibri Light"));
        font.setPointSize(10);
        bestButton->setFont(font);
        bestButton->setCursor(QCursor(Qt::PointingHandCursor));
        bestButton->setStyleSheet(QStringLiteral("border-radius: 20px;"));
        searchBox = new QLineEdit(centralwidget);
        searchBox->setObjectName(QStringLiteral("searchBox"));
        searchBox->setGeometry(QRect(10, 10, 250, 30));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(searchBox->sizePolicy().hasHeightForWidth());
        searchBox->setSizePolicy(sizePolicy1);
        searchBox->setMaximumSize(QSize(250, 30));
        searchBox->setFont(font);
        searchBox->setCursor(QCursor(Qt::IBeamCursor));
        searchBox->setFrame(true);
        outputBox = new QTextEdit(centralwidget);
        outputBox->setObjectName(QStringLiteral("outputBox"));
        outputBox->setEnabled(true);
        outputBox->setGeometry(QRect(470, 90, 631, 531));
        QFont font1;
        font1.setFamily(QStringLiteral("Calibri Light"));
        font1.setPointSize(11);
        outputBox->setFont(font1);
        outputBox->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        outputBox->setReadOnly(true);
        categoriesButton = new QPushButton(centralwidget);
        categoriesButton->setObjectName(QStringLiteral("categoriesButton"));
        categoriesButton->setGeometry(QRect(10, 50, 161, 40));
        categoriesButton->setFont(font1);
        recipesTable = new QTableView(centralwidget);
        recipesTable->setObjectName(QStringLiteral("recipesTable"));
        recipesTable->setGeometry(QRect(20, 100, 200, 521));
        QFont font2;
        font2.setFamily(QStringLiteral("Calibri Light"));
        recipesTable->setFont(font2);
        recipesTable->setStyleSheet(QStringLiteral(""));
        addButton = new QPushButton(centralwidget);
        addButton->setObjectName(QStringLiteral("addButton"));
        addButton->setGeometry(QRect(810, 10, 231, 31));
        addButton->setFont(font1);
        addButton->setStyleSheet(QStringLiteral(""));
        edit_bestButton = new QPushButton(centralwidget);
        edit_bestButton->setObjectName(QStringLiteral("edit_bestButton"));
        edit_bestButton->setGeometry(QRect(420, 480, 41, 41));
        edit_bestButton->setFont(font1);
        edit_bestButton->setCursor(QCursor(Qt::PointingHandCursor));
        edit_bestButton->setFocusPolicy(Qt::StrongFocus);
        edit_bestButton->setStyleSheet(QStringLiteral("border-radius: 20px;"));
        picLabel = new QLabel(centralwidget);
        picLabel->setObjectName(QStringLiteral("picLabel"));
        picLabel->setGeometry(QRect(240, 90, 220, 220));
        editButton = new QPushButton(centralwidget);
        editButton->setObjectName(QStringLiteral("editButton"));
        editButton->setGeometry(QRect(240, 380, 220, 40));
        editButton->setFont(font1);
        deleteButton = new QPushButton(centralwidget);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));
        deleteButton->setGeometry(QRect(240, 430, 220, 40));
        deleteButton->setFont(font1);
        nameLabel = new QLineEdit(centralwidget);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));
        nameLabel->setGeometry(QRect(240, 330, 220, 40));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Ignored);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(nameLabel->sizePolicy().hasHeightForWidth());
        nameLabel->setSizePolicy(sizePolicy2);
        nameLabel->setMinimumSize(QSize(220, 40));
        nameLabel->setMaximumSize(QSize(220, 40));
        nameLabel->setFont(font);
        nameLabel->setStyleSheet(QStringLiteral("border:none;"));
        nameLabel->setReadOnly(true);
        filterButton = new QPushButton(centralwidget);
        filterButton->setObjectName(QStringLiteral("filterButton"));
        filterButton->setGeometry(QRect(270, 10, 91, 30));
        filterButton->setFont(font);
        helpButton = new QPushButton(centralwidget);
        helpButton->setObjectName(QStringLiteral("helpButton"));
        helpButton->setGeometry(QRect(1070, 10, 31, 31));
        QFont font3;
        font3.setFamily(QStringLiteral("Calibri Light"));
        font3.setPointSize(9);
        helpButton->setFont(font3);
        helpButton->setStyleSheet(QStringLiteral("border-radius: 15px;"));
        MainWindow->setCentralWidget(centralwidget);
        bestButton->raise();
        outputBox->raise();
        categoriesButton->raise();
        recipesTable->raise();
        addButton->raise();
        edit_bestButton->raise();
        picLabel->raise();
        editButton->raise();
        deleteButton->raise();
        nameLabel->raise();
        searchBox->raise();
        filterButton->raise();
        helpButton->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "RecipeBook", nullptr));
        bestButton->setText(QApplication::translate("MainWindow", "\342\230\206", nullptr));
        searchBox->setInputMask(QString());
        searchBox->setText(QString());
        categoriesButton->setText(QApplication::translate("MainWindow", "\320\232\320\260\321\202\320\265\320\263\320\276\321\200\320\270\321\217", nullptr));
        addButton->setText(QApplication::translate("MainWindow", "\342\236\225 \320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\275\320\276\320\262\321\213\320\271 \321\200\320\265\321\206\320\265\320\277\321\202", nullptr));
        edit_bestButton->setText(QApplication::translate("MainWindow", "\342\230\206", nullptr));
        picLabel->setText(QString());
        editButton->setText(QApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \321\200\320\265\321\206\320\265\320\277\321\202", nullptr));
        deleteButton->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\200\320\265\321\206\320\265\320\277\321\202", nullptr));
        filterButton->setText(QApplication::translate("MainWindow", "\320\244\320\270\320\273\321\214\321\202\321\200\321\213", nullptr));
        helpButton->setText(QApplication::translate("MainWindow", "?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
