#include "waiter.h"
#include "ui_waiter.h"
#include "mainwindow.h"
#include <QWidget>
#include <QLabel>
#include <QCheckBox>
#include <QVBoxLayout>
#include <QStandardItemModel>
#include <QListWidgetItem>


waiter::waiter(QSqlDatabase *db,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::waiter)
{
    ui->setupUi(this);
    this->db=db;

    QSqlQuery query(*db);
    //Добавляем данные из базы данных в combobox
    query.exec("SELECT dish_name FROM menu");
    while(query.next()){
        QString value = query.value(0).toString();

        ui->comboBox->addItem(value);
        ui->comboBox->setStyleSheet("color: black;" "font: 14px");

    }
    model = new QStandardItemModel;
    ui->listView->setStyleSheet("color: black;" "font: 22px");
}

waiter::~waiter()
{
    delete ui;
}


void waiter::on_pushButton_clicked()
{

    // Создаем элементы данных
    QStandardItem *nameItem = new QStandardItem(ui->comboBox->currentText() + " Количество: " + QString::number(ui->spinBox->value()));
    model->appendRow(nameItem);

    // Устанавливаем модель в listview
    ui->listView->setModel(model);
    QSqlQuery query(*db);
    query.prepare("INSERT INTO 'order' (dish_name, number) VALUES (:name, :number);");

    query.bindValue(":name", ui->comboBox->currentText());
    query.bindValue(":number", ui->spinBox->value());
    query.exec();

}


void waiter::on_pushButton_2_clicked()
{
    model->clear(); //Очищаем listview
    ui->listView->setModel(nullptr);
    QSqlQuery query(*db);
    query.exec("DELETE FROM 'order'");//Очищаем базу данных
    ui->label->setText("Заказ не готов");
    ui->label->setStyleSheet("color: white");
}

void waiter::slot()
{
    ui->label->setText("Заказ готов"); //Меняем надпись, используя кнопку из окна повара
    ui->label->setStyleSheet("color: green");
}

