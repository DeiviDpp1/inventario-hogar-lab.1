#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dbManager = new DatabaseManager("inventory.db");
    dbManager->open();

    model =new QSqlTableModel(this);
    model->setTable("components");

    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    model->select();

    ui->tableView->setModel(model);

    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setEditTriggers(QAbstractItemView::DoubleClicked);

    ui->tableView->horizontalHeader()->setStretchLastSection(true);

}

MainWindow::~MainWindow()
{
    delete ui;
    dbManager->close();
    delete dbManager;
}
