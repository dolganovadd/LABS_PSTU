#include "addedge.h"
#include "./ui_addedge.h"
#include <QString>

addedge::addedge(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::addedge)
{
    ui->setupUi(this);
}

addedge::~addedge()
{
    delete ui;
}

void addedge::on_pushButton_clicked()
{
    QString first = ui->lineEdit_3->text(); // Первый узел
    QString second = ui->lineEdit_2->text(); // Второй узел
    QString weidht = ui->lineEdit->text(); // Вес связи
    emit dataR(first, second, weidht); // передача сообщений в другое окно
    close();
}
