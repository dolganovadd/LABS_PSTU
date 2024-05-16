#include "cook.h"
#include "ui_cook.h"
#include <QSqlQuery>

cook::cook(waiter *f, QSqlDatabase *db, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cook)
{

    ui->setupUi(this);
    this->db=db;
    this->form=f;
    connect(this, &cook::signal, form, &waiter::slot); //Связываем окно официанта и повара
    QSqlQuery query(*db);
    //добавление количества и номера блюда из базы данных в окно повара
    query.exec("SELECT dish_name, number FROM 'order'");
    while(query.next())
    {
        QString value = query.value(0).toString() + ' ' + query.value(1).toString();
        ui->textBrowser->append(value);
        ui->textBrowser->setStyleSheet("color: black;" "font: 22px");
    }

}

cook::~cook()
{
    delete ui;
}


void cook::on_pushButton_clicked()
{
    emit signal();
    ui->textBrowser->clear();
}

