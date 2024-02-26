#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QColorDialog>
#include <QInputDialog>
#include <QMenuBar>
#include <QMenu>
#include <QtWidgets>

#include "doodlearea.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

private slots:
    void penColor();
    void penWidth();

private:
    DoodleArea *doodleArea;
};

#endif // MAINWINDOW_H
