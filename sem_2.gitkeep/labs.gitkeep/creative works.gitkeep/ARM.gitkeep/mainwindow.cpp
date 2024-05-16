#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include "waiter.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/QT/armneww/database.db");
    if (!db.open())
    {
        ui->statusbar->showMessage("error: " + db.lastError().databaseText());
    }
    else
    {
        ui->statusbar->showMessage("ok");
    }

    model = new QSqlTableModel(this, db);
    model->setTable("menu"); //выбор таблицы из базы данных
    model->lastError();
    model->select(); //выводим информацию из базы данных
    ui->tableView->setModel(model); //добавляем информацию в таблицу
    model->setHeaderData(1, Qt::Horizontal, "Меню", Qt::DisplayRole);
    ui->tableView->setColumnHidden(0, true);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed);
    ui->tableView->setColumnWidth(1, 371);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_addPushBtn_clicked()
{
    QString data = ui->lineEdit->text();

    // Подготовка запроса на вставку данных в таблицу 'menu'
    QSqlQuery query;
    if (cnt<13)
    {
        query.prepare("UPDATE menu SET  dish_name  = :newValue WHERE id = :rowID");
        query.bindValue(":newValue", data);
        query.bindValue(":rowID", cnt++);
    }
    else
    {
        query.prepare("INSERT INTO menu (dish_name) VALUES (:name);");
        query.bindValue(":name", data);
    }

    // Выполнение запроса
    if (query.exec())
    {
        qDebug() << "Data successfully inserted into the 'menu' table.";
        model->setTable("menu"); //выбор таблицы из базы данных
        model->lastError();
        model->select(); //выводим информацию из базы данных
        ui->tableView->setModel(model); //добавляем информацию в таблицу
        model->setHeaderData(1, Qt::Horizontal, "Меню", Qt::DisplayRole);
        ui->tableView->setColumnHidden(0, true);
        ui->tableView->setStyleSheet("color: black;" "font: 14px");
        ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        ui->tableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed);
        ui->tableView->setColumnWidth(1, 371);

    }
    else {
        qDebug() << "Error inserting data:" << query.lastError().text();
    }

}

//Открытие окна официанта
void MainWindow::on_waiterPushBtn_clicked()
{
    form = new waiter(&db);
    form->show();  
}

//Открытие окна повара и скрытие окна меню
void MainWindow::on_cookPushBtn_clicked()
{
    hide();
    form1 = new cook(form,&db);
    form1->show();
}
