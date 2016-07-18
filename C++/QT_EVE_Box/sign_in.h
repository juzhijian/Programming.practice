#ifndef SIGN_IN_H
#define SIGN_IN_H

#include "mainwindow.h"
#include "registerdialog.h"
#include <QDialog>
#include <QDebug>
#include <QSqlQuery>        //执行语句类
#include <QSqlDatabase>     //数据库类
#include <QSqlRecord>       //返回记录类
#include <QtSql>
#include <QSqlError>
#include <QSqlTableModel>
#include <QPalette>

namespace Ui {
class sign_in;
}
class sign_in : public QDialog
{
    Q_OBJECT

public:
    explicit sign_in(QWidget *parent = 0);
    ~sign_in();

    void clearAll();
    bool judgeEmpty();
private slots:
    void on_loginbtn_clicked();
    void on_exitbtn_clicked();
    void on_registerbtn_clicked();
private:
    Ui::sign_in *ui;
    QSqlTableModel *model;
    MainWindow *mw;
signals:
    void toMainWindow(QString,QString);
};
#endif // SIGN_IN_H
