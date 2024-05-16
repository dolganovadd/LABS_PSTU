#ifndef COOK_H
#define COOK_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include "waiter.h"


namespace Ui {
class cook;
}

class cook : public QWidget
{
    Q_OBJECT

public:
    explicit cook(waiter *f, QSqlDatabase *db, QWidget *parent = nullptr);
    ~cook();

private:
    Ui::cook *ui;
    QSqlDatabase *db;
    waiter *form;

private slots:
    void on_pushButton_clicked();

signals:
    void signal();
};

#endif // COOK_H
