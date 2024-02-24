#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_AddButton_clicked()
{
    QListWidgetItem *item = new QListWidgetItem(ui->TaskTxt->text(), ui->listWidget);
    ui->listWidget->addItem(item);
    item->setFlags(item->flags() | Qt::ItemIsEditable);
    ui->TaskTxt->clear();
    ui->TaskTxt->setFocus();
}


void MainWindow::on_RemoveButton_clicked()
{

}


void MainWindow::on_RemoveAllButton_clicked()
{

}

