#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QMainWindow>
#include "mydialog.h"

namespace Ui {
class Notepad;
}

class Notepad : public QMainWindow
{
    Q_OBJECT

public:
    explicit Notepad(QWidget *parent = 0);
    ~Notepad();

private slots:
    void on_quitButton_clicked();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionQuit_triggered();

    void on_actionDisconnected_triggered();

    void on_actionRemove_qWidgets_triggered();

    void on_actionHello_triggered();

    void on_actionDialogue_triggered();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Notepad *ui;
    MyDialog *mDialog;

};

#endif // NOTEPAD_H
