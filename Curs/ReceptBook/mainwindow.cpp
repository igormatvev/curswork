#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    newRecord = new NewRecordWidget;
    editRecord = new EditRecordWidget;
    helpWidget = new Helper;

    connect(newRecord,SIGNAL(sendToWidget(QString,
                                          QString,
                                          QString,
                                          QString,
                                          QByteArray)), this, SLOT(addNewRecipe(QString,
                                                                                QString,
                                                                                QString,
                                                                                QString,
                                                                                QByteArray)));
    connect(editRecord,SIGNAL(sendToWidgetUpdate(int,
                                                 QString,
                                                 QString,
                                                 QString,
                                                 QString,
                                                 QByteArray)), this, SLOT(editOldRecipe(int,
                                                                                 QString,
                                                                                 QString,
                                                                                 QString,
                                                                                 QString,
                                                                                 QByteArray)));
    connect(this,SIGNAL(sendForEdit(int,
                                    QString,
                                    QString,
                                    QString,
                                    QString,
                                    QByteArray)), editRecord, SLOT(catchInfo(int,
                                                                           QString,
                                                                           QString,
                                                                           QString,
                                                                           QString   ,
                                                                           QByteArray)));

    ui->searchBox->setPlaceholderText("??????????");

    recipesModel = new QSqlTableModel(this);
    recipesModel->setTable(TABLE_NAME);

    ui->recipesTable->setModel(recipesModel);
    ui->recipesTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->recipesTable->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->recipesTable->resizeColumnsToContents();
    ui->recipesTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->recipesTable->horizontalHeader()->setStretchLastSection(true);
    ui->recipesTable->setColumnHidden(0, true);
    ui->recipesTable->setColumnHidden(2, true);
    ui->recipesTable->setColumnHidden(3, true);
    ui->recipesTable->setColumnHidden(4, true);
    ui->recipesTable->setColumnHidden(5, true);
    ui->recipesTable->setColumnHidden(6, true);
    ui->recipesTable->horizontalHeader()->hide();
    ui->recipesTable->verticalHeader()->hide();

    recipesModel->select();

    ui->recipesTable->setModel(recipesModel);

    connect(ui->recipesTable->selectionModel(), SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),
                    this, SLOT(currentRecipe(QModelIndex)));

    categoryAll = new QAction();
    categoryFirst = new QAction();
    categorySecond = new QAction();
    categoryGarnish = new QAction();
    categorySauce = new QAction();
    categoryDrink = new QAction();
    categoryMarinade = new QAction();
    categoryStock = new QAction();
    categoryDough = new QAction();
    categorySnack = new QAction();
    categorySweet = new QAction();

    categoryAll->setText("?????? ??????????????");
    categoryFirst->setText("???????????? ??????????");
    categorySecond->setText("???????????? ??????????");
    categoryGarnish->setText("????????????");
    categorySauce->setText("??????????");
    categoryDrink->setText("??????????????");
    categoryMarinade->setText("????????????????");
    categoryStock->setText("??????????????????");
    categoryDough->setText("?????????????? ???? ??????????");
    categorySnack->setText("??????????????");
    categorySweet->setText("????????????????");

    categoriesMenu = new QMenu;
    categoriesMenu->addAction(categoryAll);
    categoriesMenu->addAction(categoryFirst);
    categoriesMenu->addAction(categorySecond);
    categoriesMenu->addAction(categoryGarnish);
    categoriesMenu->addAction(categorySauce);
    categoriesMenu->addAction(categoryDrink);
    categoriesMenu->addAction(categoryMarinade);
    categoriesMenu->addAction(categoryStock);
    categoriesMenu->addAction(categoryDough);
    categoriesMenu->addAction(categorySnack);
    categoriesMenu->addAction(categorySweet);
    categoriesMenu->setMaximumWidth(201);
    categoriesMenu->setMinimumWidth(201);

    ui->categoriesButton->setMenu(categoriesMenu);

    connect(categoryAll, SIGNAL(triggered()), SLOT(categoriesAllButton_selected()));
    connect(categoryFirst, SIGNAL(triggered()), SLOT(categoriesFirstButton_selected()));
    connect(categorySecond, SIGNAL(triggered()), SLOT(categoriesSecondButton_selected()));
    connect(categoryGarnish, SIGNAL(triggered()), SLOT(categoriesGarnishButton_selected()));
    connect(categorySauce, SIGNAL(triggered()), SLOT(categoriesSauceButton_selected()));
    connect(categoryDrink, SIGNAL(triggered()), SLOT(categoriesDrinkButton_selected()));
    connect(categoryMarinade, SIGNAL(triggered()), SLOT(categoriesMarinadeButton_selected()));
    connect(categoryStock, SIGNAL(triggered()), SLOT(categoriesStockButton_selected()));
    connect(categoryDough, SIGNAL(triggered()), SLOT(categoriesDoughButton_selected()));
    connect(categorySnack, SIGNAL(triggered()), SLOT(categoriesSnackButton_selected()));
    connect(categorySweet, SIGNAL(triggered()), SLOT(categoriesSweetButton_selected()));

    filterAll = new QAction;
    filterName = new QAction;
    filterIngredients = new QAction;
    filterRecipe = new QAction;

    filterAll->setText("???????????????????? ??????????");
    filterName->setText("????????????????");
    filterIngredients->setText("??????????????????????");
    filterRecipe->setText("????????????");

    filtersMenu = new QMenu;
    filtersMenu->addAction(filterAll);
    filtersMenu->addAction(filterName);
    filtersMenu->addAction(filterIngredients);
    filtersMenu->addAction(filterRecipe);

    ui->filterButton->setMenu(filtersMenu);

    connect(filterAll, SIGNAL(triggered()), SLOT(filterAll_selected()));
    connect(filterName, SIGNAL(triggered()), SLOT(filterName_selected()));
    connect(filterIngredients, SIGNAL(triggered()), SLOT(filterIngredients_selected()));
    connect(filterRecipe, SIGNAL(triggered()), SLOT(filterRecipe_selected()));

    picLabel_width = ui->picLabel->width();
    picLabel_height = ui->picLabel->height();

    currentCategory = "?????? ??????????????";
    currentFilter = "ALL";
    currentID = 0;

    flag_best = false;
    hideInterface(true);

}

void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter qp(this);
    QPainterPath path;
    QPen pen(QColor(252, 238, 251), 2, Qt::SolidLine);
    path.addRoundedRect(290, 80, 901, 551, 10, 10);
//    path.addRoundedRect(30, 80, 200, 551, 10, 10);

    qp.setPen(pen);
    qp.fillPath(path, QColor(252, 238, 251));
    qp.drawPath(path);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::currentRecipe(QModelIndex id)
{
    currentID = recipesModel->data(recipesModel->index(id.row(), 0)).toInt();
    currentRow = id.row();

    QString name = recipesModel->data(recipesModel->index(currentRow, 1)).toString();
    QString ingredients = recipesModel->data(recipesModel->index(currentRow, 2)).toString();
    QString recipe = recipesModel->data(recipesModel->index(currentRow, 3)).toString();
    QString type = recipesModel->data(recipesModel->index(currentRow, 4)).toString();
    QString best = recipesModel->data(recipesModel->index(currentRow, 5)).toString();
    QPixmap pic = QPixmap();

    if (best == "1"){
        ui->nameLabel->setText(name + " ???");
        ui->edit_bestButton->setText("???");
    }
    else {
        ui->nameLabel->setText(name);
        ui->edit_bestButton->setText("???");
    }
    ui->nameLabel->setText(name);
    ui->outputBox->setPlainText("??????????????????: " + type + "\n??????????????????????:\n" + ingredients + "\n????????????: \n" + recipe);

    pic.loadFromData(recipesModel->data(recipesModel->index(id.row(), 6)).toByteArray());
    recipePic = recipesModel->data(recipesModel->index(id.row(), 6)).toByteArray();
    ui->picLabel->setPixmap(pic.scaled(picLabel_width,picLabel_height,Qt::KeepAspectRatio));
    hideInterface(false);
}

void MainWindow::categoriesAllButton_selected()
{
    currentCategory = "?????? ??????????????";
    ui->categoriesButton->setText(currentCategory);
    categorySelected();
}

void MainWindow::categoriesFirstButton_selected()
{
    currentCategory = "???????????? ??????????";
    ui->categoriesButton->setText(currentCategory);
    categorySelected();
}

void MainWindow::categoriesSecondButton_selected()
{
    currentCategory = "???????????? ??????????";
    ui->categoriesButton->setText(currentCategory);
    categorySelected();
}

void MainWindow::categoriesGarnishButton_selected()
{
    currentCategory = "????????????";
    ui->categoriesButton->setText(currentCategory);
    categorySelected();
}

void MainWindow::categoriesSauceButton_selected()
{
    currentCategory = "??????????";
    ui->categoriesButton->setText(currentCategory);
    categorySelected();
}

void MainWindow::categoriesDrinkButton_selected()
{
    currentCategory = "??????????????";
    ui->categoriesButton->setText(currentCategory);
    categorySelected();
}

void MainWindow::categoriesMarinadeButton_selected()
{
    currentCategory = "????????????????";
    ui->categoriesButton->setText(currentCategory);
    categorySelected();
}

void MainWindow::categoriesStockButton_selected()
{
    currentCategory = "??????????????????";
    ui->categoriesButton->setText(currentCategory);
    categorySelected();
}

void MainWindow::categoriesDoughButton_selected()
{
    currentCategory = "?????????????? ???? ??????????";
    ui->categoriesButton->setText(currentCategory);
    categorySelected();
}

void MainWindow::categoriesSnackButton_selected()
{
    currentCategory = "??????????????";
    ui->categoriesButton->setText(currentCategory);
    categorySelected();
}

void MainWindow::categoriesSweetButton_selected()
{
    currentCategory = "????????????????";
    ui->categoriesButton->setText(currentCategory);
    categorySelected();
}

void MainWindow::on_bestButton_clicked()
{
    if (flag_best){
        flag_best = false;
        ui->bestButton->setText("???");
    }
    else {
        flag_best = true;
        ui->bestButton->setText("???");
    }

    categorySelected();
}


void MainWindow::on_deleteButton_clicked()
{
    int n = QMessageBox::warning(0,
                                 "RecipeBook",
                                 "???? ?????????????????????????? ???????????? ?????????????? ?????????????",
                                 "????",
                                 "??????",
                                 QString(),
                                 0,
                                 1
                                );
    if(!n) {
        dataControl.deleteFromDatabase(currentID);
        recipesModel->select();
        ui->nameLabel->clear();
        ui->outputBox->clear();
        ui->picLabel->clear();
        QMessageBox::information(0, "RecipeBook", "???????????? ????????????");
        hideInterface(true);
        currentID = 0;
    }
}

void MainWindow::on_edit_bestButton_clicked()
{
    QString name = recipesModel->data(recipesModel->index(currentRow, 1)).toString();
    QString best = recipesModel->data(recipesModel->index(currentRow, 5)).toString();

    if (best == '1' ){
        dataControl.editBestInDatabase(currentID, 0);
        ui->nameLabel->setText(name + " ???");
        ui->edit_bestButton->setText("???");
    }
    else {
        dataControl.editBestInDatabase(currentID, 1);
        ui->nameLabel->setText(name);
        ui->edit_bestButton->setText("???");
    }
    recipesModel->select();
    ui->recipesTable->selectRow(currentRow);
    categorySelected();
}

void MainWindow::categorySelected()
{
    int rowNumber = recipesModel->rowCount();
    if (currentCategory == "?????? ??????????????")
        for (int i = 0 ; i < rowNumber; i++){
            if (flag_best && recipesModel->data(recipesModel->index(i, 5)).toString() != '1')
                ui->recipesTable->setRowHidden(i, true);
            else
                ui->recipesTable->setRowHidden(i, false);
        }

    else
        for (int i = 0; i < rowNumber; i++){
            if (recipesModel->data(recipesModel->index(i, 4)).toString() != currentCategory)
                ui->recipesTable->setRowHidden(i, true);
            else if (flag_best && recipesModel->data(recipesModel->index(i, 5)).toString() != '1')
                ui->recipesTable->setRowHidden(i, true);
            else
               ui->recipesTable->setRowHidden(i, false);
       }
}

void MainWindow::on_editButton_clicked()
{
    QString name = recipesModel->data(recipesModel->index(currentRow, 1)).toString();
    QString ingredients = recipesModel->data(recipesModel->index(currentRow, 2)).toString();
    QString recipe = recipesModel->data(recipesModel->index(currentRow, 3)).toString();
    QString type = recipesModel->data(recipesModel->index(currentRow, 4)).toString();
//    recipePic = recipesModel->data(recipesModel->index(currentRow, 6)).toByteArray();

    editRecord->show();
    emit sendForEdit(currentID, name, ingredients, recipe, type, recipePic);
}

void MainWindow::on_addButton_clicked()
{
        newRecord->show();
}

void MainWindow::addNewRecipe(const QString &name, const QString &ingredients, const QString &recipe, const QString &type, const QByteArray &pic)
{
    dataControl.addToDatabase(name, ingredients, recipe, type, 0, pic);

    recipesModel->select();
}

void MainWindow::editOldRecipe(const int &id, const QString &name, const QString &ingredients, const QString &recipe, const QString &type, const QByteArray &pic)
{
    dataControl.editInDatabase(id, name, ingredients, recipe, type, pic);

    recipesModel->select();
    ui->recipesTable->selectRow(currentRow);
}

void MainWindow::on_searchBox_textEdited(const QString &arg1)
{

    if (currentFilter == "NAME")
        recipesModel->setFilter(QString("name LIKE ('%%1%')").arg(arg1));
    else if (currentFilter == "INGREDIENTS")
        recipesModel->setFilter(QString("ingredients LIKE ('%%1%')").arg(arg1));
    else if (currentFilter == "RECIPE")
        recipesModel->setFilter(QString("recipe LIKE ('%%1%')").arg(arg1));
    else
        recipesModel->setFilter(QString("name LIKE ('%%1%') OR ingredients LIKE ('%%1%') OR recipe LIKE('%%1%')").arg(arg1));

    recipesModel->select();

}

void MainWindow::filterAll_selected()
{
    currentFilter = "ALL";
    ui->filterButton->setText("?????????????????????? ??????????");
}

void MainWindow::filterName_selected()
{
    currentFilter = "NAME";
    ui->filterButton->setText("????????????????");
}

void MainWindow::filterIngredients_selected()
{
    currentFilter = "INGREDIENTS";
    ui->filterButton->setText("??????????????????????");
}

void MainWindow::filterRecipe_selected()
{
    currentFilter = "RECIPE";
    ui->filterButton->setText("????????????");
}

void MainWindow::on_helpButton_clicked()
{
    helpWidget->show();
}

void MainWindow::hideInterface(const bool &mode)
{
    if (mode){
        ui->picLabel->setHidden(true);
        ui->nameLabel->setHidden(true);
        ui->edit_bestButton->setHidden(true);
        ui->editButton->setHidden(true);
        ui->deleteButton->setHidden(true);
        ui->outputBox->setHidden(true);
    }
    else {
        ui->picLabel->setHidden(false);
        ui->nameLabel->setHidden(false);
        ui->edit_bestButton->setHidden(false);
        ui->editButton->setHidden(false);
        ui->deleteButton->setHidden(false);
        ui->outputBox->setHidden(false);
    }
}
