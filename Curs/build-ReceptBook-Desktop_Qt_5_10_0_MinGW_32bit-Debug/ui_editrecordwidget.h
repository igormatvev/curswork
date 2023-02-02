/********************************************************************************
** Form generated from reading UI file 'editrecordwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITRECORDWIDGET_H
#define UI_EDITRECORDWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditRecordWidget
{
public:
    QPushButton *cancelButton;
    QLabel *picLabel;
    QPushButton *saveButton;
    QTextEdit *ingredientsBox;
    QLineEdit *nameLine;
    QTextEdit *recipeBox;
    QPushButton *selectCategoryButton;
    QPushButton *addPicButton;

    void setupUi(QWidget *EditRecordWidget)
    {
        if (EditRecordWidget->objectName().isEmpty())
            EditRecordWidget->setObjectName(QStringLiteral("EditRecordWidget"));
        EditRecordWidget->resize(900, 650);
        EditRecordWidget->setMinimumSize(QSize(900, 650));
        EditRecordWidget->setMaximumSize(QSize(900, 650));
        QIcon icon;
        icon.addFile(QStringLiteral("../src/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        EditRecordWidget->setWindowIcon(icon);
        EditRecordWidget->setStyleSheet(QLatin1String("#EditRecordWidget {background-color: rgb(252, 238, 251);}\n"
"QPushButton {background-color: rgb(239, 187, 238);\n"
"	border-radius: 10px;\n"
"	border-width: 0px;}\n"
"QPushButton:hover {background-color: rgb(244, 204, 242);\n"
"	border-width: 0px;}\n"
"QLineEdit {background-color: rgb(239, 187, 238);}\n"
"#nameLine {border-radius: 10px;\n"
"	border-width: 1px;\n"
"	min-height: 40px;\n"
"	max-height: 40px;\n"
"	min-width: 200px;\n"
"	max-width: 200px}\n"
"\n"
"QTextEdit  {background-color: rgb(255, 255, 255);}\n"
""));
        cancelButton = new QPushButton(EditRecordWidget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(700, 600, 180, 40));
        QFont font;
        font.setFamily(QStringLiteral("Calibri Light"));
        font.setPointSize(11);
        cancelButton->setFont(font);
        picLabel = new QLabel(EditRecordWidget);
        picLabel->setObjectName(QStringLiteral("picLabel"));
        picLabel->setGeometry(QRect(30, 26, 200, 200));
        saveButton = new QPushButton(EditRecordWidget);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setGeometry(QRect(510, 600, 180, 40));
        saveButton->setFont(font);
        ingredientsBox = new QTextEdit(EditRecordWidget);
        ingredientsBox->setObjectName(QStringLiteral("ingredientsBox"));
        ingredientsBox->setGeometry(QRect(280, 20, 600, 200));
        ingredientsBox->setFont(font);
        nameLine = new QLineEdit(EditRecordWidget);
        nameLine->setObjectName(QStringLiteral("nameLine"));
        nameLine->setGeometry(QRect(30, 309, 200, 40));
        recipeBox = new QTextEdit(EditRecordWidget);
        recipeBox->setObjectName(QStringLiteral("recipeBox"));
        recipeBox->setGeometry(QRect(280, 236, 601, 351));
        recipeBox->setFont(font);
        selectCategoryButton = new QPushButton(EditRecordWidget);
        selectCategoryButton->setObjectName(QStringLiteral("selectCategoryButton"));
        selectCategoryButton->setGeometry(QRect(30, 356, 200, 40));
        selectCategoryButton->setFont(font);
        addPicButton = new QPushButton(EditRecordWidget);
        addPicButton->setObjectName(QStringLiteral("addPicButton"));
        addPicButton->setGeometry(QRect(30, 236, 200, 40));
        addPicButton->setFont(font);

        retranslateUi(EditRecordWidget);

        QMetaObject::connectSlotsByName(EditRecordWidget);
    } // setupUi

    void retranslateUi(QWidget *EditRecordWidget)
    {
        EditRecordWidget->setWindowTitle(QApplication::translate("EditRecordWidget", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \321\200\320\265\321\206\320\265\320\277\321\202", nullptr));
        cancelButton->setText(QApplication::translate("EditRecordWidget", "\320\236\321\202\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        picLabel->setText(QString());
        saveButton->setText(QApplication::translate("EditRecordWidget", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \321\200\320\265\321\206\320\265\320\277\321\202", nullptr));
        selectCategoryButton->setText(QApplication::translate("EditRecordWidget", "\320\232\320\260\321\202\320\265\320\263\320\276\321\200\320\270\321\217", nullptr));
        addPicButton->setText(QApplication::translate("EditRecordWidget", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\270\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditRecordWidget: public Ui_EditRecordWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITRECORDWIDGET_H
