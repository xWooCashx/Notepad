#ifndef TAB_H
#define TAB_H

#include <QWidget>
#include <QString>
namespace Ui {
class Tab;
}

class Tab : public QWidget
{
    Q_OBJECT

public:
    explicit Tab(QWidget *parent = 0);
    const QString&  getFileName();
    void setFileName(const QString & setFileName);
    QString getText();
    void appendText(const QString &text);
    ~Tab();
    bool isEdited();
    void saved();
private slots:
void on_plainTextEdit_textChanged();

private:
    Ui::Tab *ui;
    bool edited;
    QString fileName;


};

#endif // TAB_H
