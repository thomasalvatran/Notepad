#include "mydialog.h"
#include "ui_mydialog.h"


MyDialog::MyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyDialog)
{
    ui->setupUi(this);
    ui->label->setText("mydialog label ********");
    ui->listWidget->addItem("Hello");
    for(int i= 0; i< 9; i++)
        ui->listWidget->addItem(QString::number(i) + " Item");

    ui->treeWidget->setColumnCount(2);
//    ui->treeWidget->setHeaderLabel("col a");
    ui->treeWidget->setHeaderLabels(QStringList() << "First" << "Second");
    AddRoot("1 Hello","World");
    AddRoot("2 Hello","World");
    AddRoot("3 Hello","World");

}

MyDialog::~MyDialog()
{
    delete ui;
}

void MyDialog::on_pushButton_2_clicked()
{
    //ui->listWidget->currentItem()->setText("Fussy");
    QListWidgetItem *item = ui->listWidget->currentItem();
    item->setText("Fussy bunny");
    item->setTextColor(Qt::red);
    item->setBackground(Qt::black);
}

void MyDialog::AddRoot(QString name, QString Description)
{
    QTreeWidgetItem *item = new QTreeWidgetItem(ui->treeWidget);
    item->setText(0, name);
    item->setText(1, Description);
//    ui->treeWidget->addTopLevelItem(item);
    AddChild(item, "one", "hello");
    AddChild(item, "two", "world");
}

void MyDialog::AddChild(QTreeWidgetItem *parent, QString name, QString Description)
{
//    QTreeWidgetItem *item = new QTreeWidgetItem(ui->treeWidget);
    QTreeWidgetItem *item = new QTreeWidgetItem();
    item->setText(0, name);
    item->setText(1, Description);
    parent->addChild(item);
}

void MyDialog::on_pushButton_3_clicked()
{
    ui->treeWidget->currentItem()->setBackground(0, Qt::red);
    ui->treeWidget->currentItem()->setBackground(1, Qt::blue);
}
