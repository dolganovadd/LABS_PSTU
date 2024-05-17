#include "addnode.h"
#include "mainwindow.h"
#include "./ui_addnode.h"
#include <QString>

addnode::addnode(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::addnode)
{
    ui->setupUi(this);

}

addnode::~addnode()
{
    delete ui;
}

void addnode::on_pushButton_clicked()
{
    QString dat = ui->lineEdit->text(); //номер узла
    emit dataReady(dat); // передача информации другому окну
    close();
}
