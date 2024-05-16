#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "waiter.h"
#include "cook.h"
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QSqlTableModel>
#include <QSqlQueryModel>
#include <QTableView>
#include <QVariant>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    waiter *form;
    cook *form1;
    QSqlDatabase db;
    QSqlTableModel *model;
    int cnt = 1;

private slots:
    void on_addPushBtn_clicked();
    void on_waiterPushBtn_clicked();
    void on_cookPushBtn_clicked();
};
#endif // MAINWINDOW_H
