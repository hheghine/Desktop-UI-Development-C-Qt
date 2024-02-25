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

void MainWindow::on_actionSave_triggered()
{
    SaveFile saveFileDialog;

    if (saveFileDialog.exec() == QDialog::Accepted)
        saveToFile(saveFileDialog.getUi()->SavedFileName->text() + ".txt");
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"));

    if (!fileName.isEmpty())
    {
        QFile file(fileName);

        if (file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream in(&file);
            ui->plainTextEdit->setPlainText(in.readAll());
            file.close();
        }
        else
            qDebug() << "Failed to open file for reading:" << file.errorString();
    }
}

void    MainWindow::saveToFile(const QString &fileName)
{
    QFile   file(fileName);

    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream stream(&file);
        stream << ui->plainTextEdit->toPlainText();
        file.close();
    }
    else
        qDebug() << "Failed to open file for writing:" << file.errorString();
}
