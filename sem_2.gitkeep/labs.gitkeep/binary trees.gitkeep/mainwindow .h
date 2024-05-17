#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QGraphicsTextItem>
#include <QString>
#include <QDebug>
#include <QtCore>
#include <QtGui>

#include "tree.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked(); // Считывание кнопки "Применить"

    void on_showBtn_clicked(); // Считывание кнопки "Показать"
    void showTre(Node *tree, int x, int y); // Рекурсивный показ деревца

    //void on_radioButton_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *Scene; // Добавление указателя на объект "Сценка"
    QGraphicsEllipseItem *ell; // Добавление указателя на объект "Эллипса"
    QGraphicsLineItem *line; // Добавление указателя на объект "Линия"
    QGraphicsTextItem *text; // Добавление указателя на объект "Текст"

};
#endif // MAINWINDOW_H
