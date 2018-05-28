#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <tab.h>
#include <qnumeric.h>
#include <QMessageBox>
#include <QCloseEvent>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionNew_triggered();

    void on_actionSave_triggered();

    void on_actionOpen_triggered();

    void on_tabWidget_tabCloseRequested(int index);

signals:



private:
    Ui::MainWindow *ui;
     int counter;
    Tab* createNewTab(const QString &title);
    QString createTabName();
    const QString & getFileName(Tab *tab);
    void save(int index);
    bool closeTab(int index);
protected:
    void closeEvent(QCloseEvent *event);
};

#endif // MAINWINDOW_H
