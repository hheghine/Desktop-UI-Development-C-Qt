#include "mainwindow.h"
#include "./ui_mainwindow.h"

double  g_value = 0.0;

bool    addTrigger = false;
bool    subTrigger = false;
bool    divTrigger = false;
bool    multTrigger = false;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Display->setText(QString::number(g_value));

    QPushButton *numButtons[10];

    for (int i = 0; i < 10; ++i)
    {
        QString buttonName = "Button" + QString::number(i);
        numButtons[i] = MainWindow::findChild<QPushButton *>(buttonName);

        connect(numButtons[i], SIGNAL(released()), this, SLOT(NumPressed()));
    }

    connect(ui->ButtonAdd, SIGNAL(released()), this, SLOT(MathButtonPressed()));
    connect(ui->ButtonSub, SIGNAL(released()), this, SLOT(MathButtonPressed()));
    connect(ui->ButtonMult, SIGNAL(released()), this, SLOT(MathButtonPressed()));
    connect(ui->ButtonDiv, SIGNAL(released()), this, SLOT(MathButtonPressed()));

    connect(ui->ButtonEq, SIGNAL(released()), this, SLOT(EqualButton()));

    connect(ui->ButtonPM, SIGNAL(released()), this, SLOT(ChangeNumberSign()));

    connect(ui->ButtonAC, SIGNAL(released()), this, SLOT(ClearAll()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void    MainWindow::NumPressed()
{
    QPushButton *button = (QPushButton *)sender();
    QString     buttonVal = button->text();
    QString     displayVal = ui->Display->text();

    if (displayVal.toDouble() == 0 || displayVal.toDouble() == 0.0)
        ui->Display->setText(buttonVal);
    else
    {
        QString value = displayVal + buttonVal;
        double  dblVal = value.toDouble();
        ui->Display->setText(QString::number(dblVal, 'g', 16));
    }
}

void    MainWindow::MathButtonPressed()
{
    /* reset */
    addTrigger = false;
    subTrigger = false;
    multTrigger = false;
    divTrigger = false;

    QString displayVal = ui->Display->text();
    g_value = displayVal.toDouble();

    QPushButton *button = (QPushButton *)sender();
    QString     buttonVal = button->text();

    if (QString::compare(buttonVal, "/", Qt::CaseInsensitive) == 0)
        divTrigger = true;
    else if (QString::compare(buttonVal, "*", Qt::CaseInsensitive) == 0)
        multTrigger = true;
    else if (QString::compare(buttonVal, "+", Qt::CaseInsensitive) == 0)
        addTrigger = true;
    else
        subTrigger = true;

    ui->Display->setText("");
}

void    MainWindow::EqualButton()
{
    double  res = 0.0;
    QString displayVal = ui->Display->text();
    double  dbl = displayVal.toDouble();

    if (addTrigger || subTrigger || divTrigger || multTrigger)
    {
        if (addTrigger)
            res = g_value + dbl;
        else if (subTrigger)
            res = g_value - dbl;
        else if (divTrigger)
            res = g_value / dbl;
        else
            res = g_value * dbl;
    }

    ui->Display->setText(QString::number(res));
}

void MainWindow::ChangeNumberSign()
{
    QString             displayVal = ui->Display->text();
    QRegularExpression  reg("[-+]?[0-9]*\\.?[0-9]+");

    if (reg.match(displayVal).hasMatch())
    {
        double dbl = displayVal.toDouble();
        double dblSign = -1 * dbl;

        ui->Display->setText(QString::number(dblSign));
    }
}

void    MainWindow::ClearAll()
{
    g_value = 0.0;
    addTrigger = false;
    subTrigger = false;
    multTrigger = false;
    divTrigger = false;
    ui->Display->setText("0");
}
