#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "QFileDialog"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{  counter=1;
    ui->setupUi(this);
    this->createNewTab(this->createTabName());
    this->createNewTab(this->createTabName());
   // ui->tabWidget->tabCloseRequested();
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_actionNew_triggered()
{
    qDebug()<<"new";
    this->createNewTab(this->createTabName());
}

void MainWindow::on_actionSave_triggered()
{
    qDebug()<<"save";
    this->save(ui->tabWidget->currentIndex());
}

void MainWindow::on_actionOpen_triggered()
{
    qDebug()<<"open";
   QString fileName;
    QString filters("Text files (*.txt)" );
    fileName=QFileDialog::getSaveFileName(this, "tytuł oknaaa", QDir::currentPath(), filters);
    if(fileName.isEmpty()||fileName.isNull())
        qDebug()<<"anulowano otwarcie pliku";
    else{
    Tab* newTab;
    newTab=this->createNewTab(fileName);
    newTab->setFileName(fileName);
    //newTab=this->createNewTab(QFileDialog::getSaveFileName(this, "tytuł oknaaa", QDir::currentPath(), filters));
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly|QFile::Text))
    {
        qDebug()<<"Blad odczytu";
        return;
    }
    QTextStream in(&file);
    while(!in.atEnd())
    {
        QString line=in.readLine();
        newTab->appendText(line);
    }
    file.close();
     newTab->saved();
    }
}

 QString MainWindow::createTabName()
 {

     return "Nowy " + QString::number(counter);
 }


Tab *MainWindow::createNewTab(const QString &title)
{    this->counter++;
    Tab* newTab=new Tab;
   //  newTab->setFileName("aaa");
    ui->tabWidget->addTab(newTab, title);
    ui->tabWidget->setCurrentWidget(newTab);
     return newTab;
}

 const QString & MainWindow::getFileName(Tab *tab)
 {
     QString fileName_tab = tab->getFileName();
     QString filters("Text files (*.txt)" );
     if(fileName_tab.isEmpty())
         tab->setFileName(QFileDialog::getSaveFileName(this, "tytuł oknaaa", QDir::currentPath(), filters));
     return tab->getFileName();

 }

  void MainWindow::save(int index)
  {
      Tab* tab_to_save=dynamic_cast<Tab *>(ui->tabWidget->widget(index));
      QString file_name=this->getFileName(tab_to_save);
qDebug()<<"jeszcze tylko zapis";
      QFile file(file_name);
      if(!file.open(QFile::WriteOnly | QFile::Text))
      {
          qDebug()<<"nie mozna otworzyc pliku do zapisu";
          return;
      }
    QTextStream out(&file);
     out<<tab_to_save->getText();
     file.flush();
     QFileInfo fileInfo(file);
     ui->tabWidget->setTabText(index, fileInfo.fileName());
     file.close();
     tab_to_save->saved();
  }

void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    closeTab(index);
}
bool MainWindow::closeTab(int index)
{
    QMessageBox::StandardButton reply= QMessageBox::question(this,
                                                             "Co dalej",
                                                             "Chcesz zapisać dane?",
                                                             QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel);
switch (reply)
{
case QMessageBox::Yes:
    qDebug()<<"tak";
    this->save(index);
    ui->tabWidget->removeTab(index);
    counter--;
    return true;
    break;
case QMessageBox::No:
    qDebug()<<"nie";
    ui->tabWidget->removeTab(index);
    counter--;
    return true;
    break;
case QMessageBox::Cancel:
    qDebug()<<"cancel";
    return false;
    break;
 default :
    qDebug()<<"nic";
    return false;
}
}
void MainWindow::closeEvent(QCloseEvent *event)
{ bool close_attempt;
    while( counter>0)
    {
        close_attempt=closeTab(0);
        if(close_attempt==false)
        {

            event->ignore();
            break;
        }
        counter--;
    }

}
