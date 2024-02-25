#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->plainTextEdit);
}

void MainWindow::on_actionNew_File_triggered()
{
    NewFile file;

    file.setModal(true);
    file.exec();
}

MainWindow::~MainWindow()
{
    delete ui;
}
