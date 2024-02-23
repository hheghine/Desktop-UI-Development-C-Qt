#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    count(0)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::on_pushButton_clicked);
}

void MainWindow::on_pushButton_clicked()
{
    this->count++;
    ui->label->setText(QString::number(count));
}

MainWindow::~MainWindow()
{
    delete ui;
}

