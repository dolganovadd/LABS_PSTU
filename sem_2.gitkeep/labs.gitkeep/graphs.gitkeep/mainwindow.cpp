#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "addnode.h"
#include "addedge.h"
#include "graph.h"
#include <QString>
#include <QPoint>
#include <qDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Scene = new QGraphicsScene(this); // установка сцены для показа графов
    ui->graphicsView->setScene(Scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    Scene->setSceneRect(180,10,611,341);
    Scene->update();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    QBrush whBrush(Qt::black); //задание цвета для объектов
    QPen blackPen(Qt::black);
    blackPen.setWidth(1);

    gr->addNode();
    QGraphicsEllipseItem *ell = Scene->addEllipse(190,20,30,30, blackPen, whBrush); //показ объектов на сцене
    QGraphicsTextItem *text = Scene->addText(QString::number(gr->arrGr.size()+1), QFont("Arial"));
    text->setPos(ell->boundingRect().center().rx()- ell->boundingRect().width()/4,
                 ell->boundingRect().center().ry() - ell->boundingRect().height()/3);
    text->setDefaultTextColor(QColor("white"));
    QList<QGraphicsItem*> items;
    items << ell << text;
    QGraphicsItemGroup *group = Scene->createItemGroup(items);
    group->setFlag(QGraphicsItem::ItemIsMovable, true);
    gr->arrGr.push_back(group);
    updateLine();
    Scene->update();
}


void MainWindow::on_pushButton_2_clicked()
{
    addnode *window = new addnode(this); //вызов окна добавления узла
    connect(window, &addnode::dataReady, this, &MainWindow::receiveData); //связь окна добавления с главным окном
    window->setModal(true);

    window->exec();
    updateLine();
    delete window;
    Scene->update();

}
void MainWindow::receiveData(const QString& data) {    //Получение и обработка данных
    gr->delNode(data.toInt());

    delete gr->arrGr[data.toInt()-1];
    for (int i(data.toInt()); i < gr->arrGr.size();i++){
        gr->arrGr[i-1] = gr->arrGr[i];
    }
    gr->arrGr.pop_back();

    QGraphicsItemGroup** groups = new QGraphicsItemGroup* [gr->arrGr.size()];

    for (int i(0); i < gr->arrGr.size();i++){
        groups[i] = gr->arrGr[i];
    }


    for (int i(data.toInt()-1); i < gr->arrGr.size(); i++)
    {
        foreach (QGraphicsItem *item, groups[i]->childItems())
        {
            QGraphicsTextItem *textItem = qgraphicsitem_cast<QGraphicsTextItem*>(item);
            if (textItem)
            {
                textItem->setPlainText(QString::number(i+1));
            }
        }
    }
    groups = 0;
    delete[] groups;
    updateLine();
    Scene->update();
}


void MainWindow::on_pushButton_3_clicked()
{
    addedge *wi = new addedge(this); //добавление окна связи
    connect(wi, &addedge::dataR, this, &MainWindow::recEdge); //связываем окно связи с главным
    wi->setModal(true);
    wi->exec();
    updateLine();
    delete wi;
    Scene->update();
}

void MainWindow::recEdge(const QString&first,const QString&second,const QString&weidht){ // обработка полученных данных

    gr->setMat(first.toInt(),second.toInt(),weidht.toInt());
    gr->showw();
    updateLine();
    Scene->update();

}

void MainWindow::updateLine(){
    QPen whPen(Qt::black);

    int s = gr->l.size(); //удаление объектов со сцены
    for (int i(0); i<s; i++){
        delete gr->l.back();
        gr->l.pop_back();

    }
    s = gr->t.size();
    for (int i(0); i<s; i++){

        delete gr->t.back();
        gr->t.pop_back();

    }
    Scene->update();

    for (int i(0); i<gr->getSize();i++){ //рисуем линии связи с учетом координат объектов
        for (int j(i+1); j < gr->getSize();j++){
            if (gr->checkMat(i,j)){
                QGraphicsLineItem *lin = new QGraphicsLineItem;
                QGraphicsTextItem *text = new QGraphicsTextItem;
                text = Scene->addText(QString::number(gr->weidgt(i,j)), QFont("Arial"));

                QPointF center1 = gr->arrGr[i]->mapToScene(gr->arrGr[i]->boundingRect().center());
                QPointF center2 = gr->arrGr[j]->mapToScene(gr->arrGr[j]->boundingRect().center());
                qreal angle = qAtan2(center2.y() - center1.y(), center2.x() - center1.x());
                text->setPos((center1.x()+center2.x())/2,(center1.y()+center2.y())/2);
                lin = Scene->addLine(center1.x() + 10 *qCos(angle),center1.y()+ 10 *qSin(angle),center2.x()- 10 *qCos(angle),center2.y()- 10 *qSin(angle), whPen);
                text->setDefaultTextColor(QColor("green"));

                gr->l.push_back(lin);
                gr->t.push_back(text);
            }
        }
    }

    for (int i(0); i<gr->getSize();i++){
        for (int j(i+1); j < gr->getSize();j++){
            if (gr->checkMat(j,i)){
                QGraphicsLineItem *lin = new QGraphicsLineItem;
                QGraphicsTextItem *text = new QGraphicsTextItem;
                text = Scene->addText('(' + QString::number(gr->weidgt(j,i)) + ')', QFont("Arial"));

                QPointF center1 = gr->arrGr[i]->mapToScene(gr->arrGr[i]->boundingRect().center());
                QPointF center2 = gr->arrGr[j]->mapToScene(gr->arrGr[j]->boundingRect().center());
                qreal angle = qAtan2(center2.y() - center1.y(), center2.x() - center1.x());
                text->setPos((center1.x()+center2.x())/2-4,(center1.y()+center2.y())/2+12);
                lin = Scene->addLine(center1.x() + 10 *qCos(angle),center1.y()+ 10 *qSin(angle),center2.x()- 10 *qCos(angle),center2.y()- 10 *qSin(angle), whPen);
                text->setDefaultTextColor(QColor("red"));

                gr->l.push_back(lin);
                gr->t.push_back(text);
            }
        }
    }

    Scene->update();
}


void MainWindow::on_pushButton_4_clicked()
{
    ui->statusbar->showMessage("Обход в ширину: "+ gr->searchInWidth(1));

}

void MainWindow::on_pushButton_5_clicked()
{
    ui->statusbar->showMessage("Обход в глубину: "+ gr->searchInDepth(1));
}

void MainWindow::on_pushButton_6_clicked()
{
    gr->dijkstra(1);
    ui->statusbar->showMessage("Кратчайший путь: "+ gr->showw());
}



