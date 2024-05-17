#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QString>
#include <QPainter>


Tree *tree = new Tree;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->initNode->click(); // Переключение на initRadioButton
    Scene = new QGraphicsScene(this); // ВЫделение памяти для объекта "Сценка"
    ui->grView->setScene(Scene); // Встраивание сцены в объект QGraphicView
    ui->grView->setRenderHint(QPainter::Antialiasing); // Установка режима отрисовки
    ui->grView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Отключение VerticalScrollBar
    ui->grView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Отключение HorizontalScrollBar

    Scene->setSceneRect(0,0,741,341); // Устновка размеров сцены
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString dat = ui->userData->text(); // Считывание данных с поля для ввода данных

    // Проверка RadioButton, отвечающего за массив
    if (ui->arr->isChecked())
        tree->arrNodes(dat,tree->root);
    // Проверка RadioButton, отвечающего за иницализацию корня
    if (ui->initNode->isChecked()){
        ui->statusbar->showMessage(dat); // Вывод  данных в статус бар
        tree->deletNodes(tree->root);
        delete tree;
        tree = new Tree;
        tree->init(dat.toInt());
        ui->addNode->click();
        ui->userData->clear();
        return;
    }
    // Проверка RadioButton, отвечающего за добавление узла
    if (ui->addNode->isChecked()){
        ui->statusbar->showMessage(dat); // Вывод  данных в статус бар
        tree->addNode(dat.toInt(),tree->root,356,0,200);
    }
    // Проверка RadioButton, отвечающего за удаление узла
    if (ui->delNode->isChecked()){
        ui->statusbar->showMessage(dat); // Вывод  данных в статус бар
        if (tree->count == 0) {delete tree; tree->root = NULL;}
        else tree->delNodes(dat.toInt(),tree->root);
    }
    ui->userData->clear(); // Очищение поля ввода
}

void MainWindow::showTre(Node *tree, int x, int y) {
    // Создание вспомогательных инструментов для покраса
    QBrush whBrush(Qt::white);
    QPen blackPen(Qt::black);
    QPen whPen(Qt::white);
    blackPen.setWidth(1);


    // Рекурсивный обход дерева, с добавление объектов на сцену
    if (tree != NULL) {
        showTre(tree->left, tree->x, tree->y);

        ell = Scene->addEllipse(tree->x,tree->y,30,30, blackPen, whBrush);
        //ell = Scene->addEllipse(tree->y,(tree->x)/2,30,30, blackPen, whBrush);
        text = Scene->addText(QString::number(tree->data),QFont("Arial"));
        text->setDefaultTextColor(QColor("balck"));
        text->setPos(tree->x+4,tree->y+3);
        //text->setPos(tree->y+3,(tree->x+4)/2);
        line = Scene->addLine(x+30-10,y+30-5,tree->x+10,tree->y+5, whPen);
        //line = Scene->addLine(y+30-5,(x+30-10)/2,tree->y+5,(tree->x+10)/2, whPen);
        QList<QGraphicsItem*> items;
        items << ell << text << line;
        //ell->setFlag(QGraphicsEllipseItem::ItemIsMovable);
        QGraphicsItemGroup *group = Scene->createItemGroup(items);      // объеденяем в группу эллипс и текст
        group->setFlag(QGraphicsItem::ItemIsMovable, true);
        showTre(tree->right, tree->x, tree->y);
    }
}

void MainWindow::on_showBtn_clicked()
{
    Scene->clear();
    showTre(tree->root, 356, 0);
    ui->statusbar->showMessage(QString::number(tree->getMin()));
}






