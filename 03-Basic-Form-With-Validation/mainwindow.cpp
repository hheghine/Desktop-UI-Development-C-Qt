#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // ui->label->setText("Hey there, human!");

    QFormLayout *layout = new QFormLayout();

    QLabel      *label_FirstName = new QLabel();
    QLabel      *label_LastName = new QLabel();
    QLabel      *label_Age = new QLabel();

    // QLabel *label_FirstName = ui->label_FirstName;
    // QLabel *label_LastName = ui->label_LastName;
    // QLabel *label_Age = ui->label_Age;

    label_FirstName->setText("Enter First Name: ");
    label_LastName->setText("Enter Last Name: ");
    label_Age->setText("Enter Age: ");

    QLineEdit   *line_FirstName = new QLineEdit();
    QLineEdit   *line_LastName = new QLineEdit();
    QLineEdit   *line_Age = new QLineEdit();

    // QLineEdit *line_FirstName = ui->line_FirstName;
    // QLineEdit *line_LastName = ui->line_LastName;
    // QLineEdit *line_Age = ui->line_Age;

    line_FirstName->setPlaceholderText("Enter First Name Here");
    line_LastName->setPlaceholderText("Enter Last Name Here");
    line_Age->setPlaceholderText("Enter Age Here");


    label_FirstName->setGeometry(50, 50, 100, 20);  // x, y, width, height
    line_FirstName->setGeometry(160, 50, 200, 20);

    label_LastName->setGeometry(50, 80, 100, 20);
    line_LastName->setGeometry(160, 80, 200, 20);

    label_Age->setGeometry(50, 110, 100, 20);
    line_Age->setGeometry(160, 110, 200, 20);

    layout->addRow(label_FirstName->text(), line_FirstName);
    layout->addRow(label_LastName->text(), line_LastName);
    layout->addRow(label_Age->text(), line_Age);

    // this->centralWidget()->setLayout(layout);

    label_FirstName->setParent(this->centralWidget());
    line_FirstName->setParent(this->centralWidget());
    label_LastName->setParent(this->centralWidget());
    line_LastName->setParent(this->centralWidget());
    label_Age->setParent(this->centralWidget());
    line_Age->setParent(this->centralWidget());


    label_FirstName->setVisible(false);
    label_LastName->setVisible(false);
    label_Age->setVisible(false);

    line_FirstName->setVisible(true);
    line_LastName->setVisible(true);
    line_Age->setVisible(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}
