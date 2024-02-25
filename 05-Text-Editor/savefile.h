#ifndef SAVEFILE_H
#define SAVEFILE_H

#include <QDialog>
#include <QDebug>
#include <QFile>
#include <QStandardPaths>
#include <QTextStream>

namespace Ui {
class SaveFile;
}

class SaveFile : public QDialog
{
    Q_OBJECT

public:
    explicit SaveFile(QWidget *parent = nullptr);
    ~SaveFile();

    Ui::SaveFile    *getUi() const;

private:
    Ui::SaveFile *ui;
};

#endif // SAVEFILE_H
