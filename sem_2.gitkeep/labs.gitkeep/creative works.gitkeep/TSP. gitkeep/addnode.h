#ifndef ADDNODE_H
#define ADDNODE_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class addnode;
}

class addnode : public QDialog
{
    Q_OBJECT

public:
    explicit addnode(QWidget *parent = nullptr);
    ~addnode();

signals:     void dataReady(const QString& data);
private slots:
    void on_pushButton_clicked();

private:
    Ui::addnode *ui;
};

#endif // ADDNODE_H
