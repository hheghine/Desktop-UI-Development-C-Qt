#include "mainwindow.h"

MainWindow::MainWindow()
{
    doodleArea = new DoodleArea;
    setCentralWidget(doodleArea);

    QAction *penColorAct = new QAction(tr("Pen Color"), this);
    connect(penColorAct, &QAction::triggered, this, &MainWindow::penColor);

    QAction *penWidthAct = new QAction(tr("Pen Width"), this);
    connect(penWidthAct, &QAction::triggered, this, &MainWindow::penWidth);

    QAction *clearAct = new QAction(tr("&Clear"), this);
    connect(clearAct, &QAction::triggered, doodleArea, &DoodleArea::clearDrawing);

    QMenu *optionMenu = menuBar()->addMenu(tr("Options"));
    optionMenu->addAction(penColorAct);
    optionMenu->addAction(penWidthAct);
    optionMenu->addAction(clearAct);

    setWindowTitle(tr(" Doodle /|\\ ^._.^ /|\\ "));
    resize(500, 500);
}

void    MainWindow::penColor()
{
    QColor color = QColorDialog::getColor(doodleArea->getPenColor());
    if (color.isValid())
        doodleArea->setPenColor(color);
}

void MainWindow::penWidth()
{
    bool    ok;
    int     width = QInputDialog::getInt(this, tr("Pen Width"), tr("Select pen width:"), doodleArea->getPenWidth(), 1, 50, 1, &ok);

    if (ok)
        doodleArea->setPenWidth(width);
}

