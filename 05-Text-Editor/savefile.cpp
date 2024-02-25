#include "savefile.h"
#include "ui_savefile.h"

SaveFile::SaveFile(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SaveFile)
{
    ui->setupUi(this);

    ui->SavedFileName->setPlaceholderText("File Name");
}

Ui::SaveFile *SaveFile::getUi() const
{
    return ui;
}

SaveFile::~SaveFile()
{
    delete ui;
}
