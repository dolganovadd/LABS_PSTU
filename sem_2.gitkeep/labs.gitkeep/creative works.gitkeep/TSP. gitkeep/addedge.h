#ifndef ADDEDGE_H
#define ADDEDGE_H

#include <QDialog>

namespace Ui {
class addedge;
}

class addedge : public QDialog
{
    Q_OBJECT

public:
    explicit addedge(QWidget *parent = nullptr);
    ~addedge();

signals: void dataR(const QString&first,const QString&second,const QString&weidht);
private slots:
    void on_pushButton_clicked();

private:
    Ui::addedge *ui;
};

#endif // ADDEDGE_H
