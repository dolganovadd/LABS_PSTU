#ifndef WAITER_H
#define WAITER_H

#include <QWidget>
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QSqlTableModel>
#include <QSqlQueryModel>
#include <QTableView>
#include <QVariant>
#include <QWidget>
#include <QLabel>
#include <QCheckBox>
#include <QVBoxLayout>
#include<QStandardItemModel>

namespace Ui {
class waiter;
}

class waiter : public QWidget
{
    Q_OBJECT

public:
    explicit waiter(QSqlDatabase *db,QWidget *parent = nullptr);
    ~waiter();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::waiter *ui;
    QSqlDatabase *db;
    QStandardItemModel *model;

public slots:
    void slot();
};

#endif // WAITER_H
