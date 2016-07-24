#ifndef REGISTERDIALOG_H
#define REGISTERDIALOG_H

#include <QDialog>
#include "mysql.h"

#include <QPalette>
#include <QTime>

namespace Ui {
class registerdialog;
}

class registerdialog : public QDialog
{
    Q_OBJECT

public:
    explicit registerdialog(QWidget *parent = 0);
    ~registerdialog();

    void setyanzheng();
    void clearAll();
    bool judgeEmpty();

private slots:
    void on_registerbtn_clicked();

    void on_returnbtn_clicked();
private:
    Ui::registerdialog *ui;
    int yanzheng;
    QSqlTableModel *model;
    MySql mySql;
};

#endif // REGISTERDIALOG_H
