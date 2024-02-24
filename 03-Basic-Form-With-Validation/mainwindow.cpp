#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setText("Hey there, human!");

    QFormLayout *layout = new QFormLayout();

    ui->line_FirstName->setPlaceholderText("First Name");
    ui->line_LastName->setPlaceholderText("Last Name");
    ui->line_Age->setPlaceholderText("Age");

    this->centralWidget()->setLayout(layout);
}

void MainWindow::on_pushButton_clicked()
{
    QString firstName = ui->line_FirstName->text();
    QString lastName = ui->line_LastName->text();
    QString age = ui->line_Age->text();

    if (firstName.isEmpty() || lastName.isEmpty() || age.isEmpty())
        QMessageBox::critical(this, "Error", "Please fill in all fields.");
    else
        QMessageBox::information(this, "Success", "Form submitted successfully.");
}

MainWindow::~MainWindow()
{
    delete ui;
}
