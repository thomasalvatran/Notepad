#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QDialog>
#include <QDebug>
#include <QtCore>
#include <QtGui>
#include <QTreeWidget>

namespace Ui {
class MyDialog;
}

class MyDialog : public QDialog
{
    Q_OBJECT

void AddRoot(QString name, QString Description);
void AddChild(QTreeWidgetItem *parent, QString name, QString Description);

public:
    explicit MyDialog(QWidget *parent = 0);
    ~MyDialog();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MyDialog *ui;

};

#endif // MYDIALOG_H
