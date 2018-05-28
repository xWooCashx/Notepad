#include "tab.h"
#include "ui_tab.h"

Tab::Tab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tab)
{
edited=false;
    ui->setupUi(this);
}

bool Tab::isEdited()
{
   return edited;
}

void Tab::saved()
{
    edited=false;
}
Tab::~Tab()
{
    delete ui;
}

void Tab::on_plainTextEdit_textChanged()
{
    edited=true;
}

const QString &Tab::getFileName()
{
    return fileName;
}
void Tab::setFileName(const QString & setFileName)
{
    fileName=setFileName;
}
 QString Tab::getText()
 {
     return ui->tekst->toPlainText();
 }
 void Tab::appendText(const QString &text)
 {
    ui->tekst->appendPlainText(text);
 }
