#include "notepad.h"
#include "ui_notepad.h"
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QWidget>
#include "mydialog.h"
#include <QSpacerItem>
#include <QGridLayout>


Notepad::Notepad(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Notepad)
{
    ui->setupUi(this);
//    setCentralWidget(ui->plainTextEdit);
    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), ui->progressBar_2, SLOT(setValue(int)));
    ui->checkBox->setChecked(true);
    ui->label->setText("Notepad label ********");
//    ui->comboBox->addItem("Hello");
//    ui->comboBox->addItem("World");

    for (int i = 1; i < 9; i++)
        ui->comboBox->addItem(QString::number(i) + " Item");
}

Notepad::~Notepad()
{
    delete ui;
}

void Notepad::on_quitButton_clicked()
{
    qApp->quit();
}

void Notepad::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), QString(),
            tr("Text Files (*.txt);;C++ Files (*.cpp *.h)"));

    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
            return;
        }
        QTextStream in(&file);
        ui->textEdit->setText(in.readAll());
        file.close();
    }
}

void Notepad::on_actionSave_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), QString(),
            tr("Text Files (*.txt);;C++ Files (*.cpp *.h)"));

    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly)) {
            // error message
        } else {
            QTextStream stream(&file);
            stream << ui->textEdit->toPlainText();
            stream.flush();
            file.close();
        }
    }
}

void Notepad::on_actionQuit_triggered()
{
     qApp->quit();
}

void Notepad::on_actionDisconnected_triggered()
{
    disconnect(ui->horizontalSlider, SIGNAL(valueChanged(int)), ui->progressBar_2, SLOT(setValue(int)));
}

void Notepad::on_actionRemove_qWidgets_triggered()
{
//    QList<QWidget *> Widgets = ui->widget->findChildren<QWidget *>();
//        foreach(QWidget * child, Widgets)
//        {
//            delete child;
//        }

}
#include <iostream>
using namespace std;
void Notepad::on_actionHello_triggered()
{
    static int i;
//    ui->actionHello->text();
    cout << "Hello " << i++ <<  endl;
    ui->textEdit->setTextColor( QColor( "red" ) );
//    ui->textEdit->setText("Hello\n" + i);
//    ui->textEdit->append("Hello" + i);
    ui->textEdit->append("<b>Hello</b> " + QString::number(i) + "<br>");
//    ui->textEdit->setText("<b>Hello</b><br>");
//    QMessageBox::frameGeometry.width(222);
//    QMessageBox::resize();
    QMessageBox::information(this, "title", "QMessageBox");
    QMessageBox::about(this,"this is a test this is a test","test1");
//    QMessageBox::setText(this);
//    QMessageBox::setFixedWidth(500);
//    QMessageBox::setInformativeText("Test");
//    QMessageBox::setText("Test");
//    QMessageBox::information(this, "title", ui->textEdit->text());
    QMessageBox *msgBox = new QMessageBox();
//    msgBox.resize(400,500);

    msgBox->setText("The document has been modified.");
    msgBox->setInformativeText("Do you want to save your changes?");
    msgBox->setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    msgBox->setDefaultButton(QMessageBox::Save);
//    msgBox.resize(400,500);
    msgBox->exec();
    QMessageBox msgBox1;
    QSpacerItem* horizontalSpacer = new QSpacerItem(500, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
    msgBox1.setText( "SomText" );
    QGridLayout* layout = (QGridLayout*)msgBox1.layout();
    layout->addItem(horizontalSpacer, layout->rowCount(), 0, 1, layout->columnCount());
    msgBox1.exec();

    QTextEdit *edit = new QTextEdit(this); //??
    edit->setGeometry(5, 5, 200, 150);     //??
}

void Notepad::on_actionDialogue_triggered()
{
//    MyDialog modalDialog;
//    modalDialog.setModal(true);
//    modalDialog.exec();
      mDialog = new MyDialog(this);
      mDialog->show();

      MyDialog *m = new MyDialog(this);
      m->resize(500,200);
      m->show();
}

void Notepad::on_pushButton_clicked()
{
//      ui->lineEdit->setText("Hello");
      QMessageBox::information(this, "Title", ui->lineEdit->text());
    if(ui->checkBox->isChecked())
    {
        QMessageBox::information(this, "Your answer about Cats", "you like cats");
    }
    else
    {
       QMessageBox::information(this, "Your answer about Cats", "you don't like cats");
    }
}

void Notepad::on_pushButton_2_clicked()
{
    if (ui->radioButton1->isChecked())
    {
        QMessageBox::information(this, "Title", ui->radioButton1->text());
    }
    else
    {
        QMessageBox::information(this, "Title", ui->radioButton2->text());
    }
}

void Notepad::on_pushButton_3_clicked()
{
    QMessageBox::information(this, "Title", ui->comboBox->currentText());
//    QMessageBox::information(this, "Title", ui->comboBox->currentIndex());
}
