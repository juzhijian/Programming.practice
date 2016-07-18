#ifndef REGISTERDIALOG_H
#define REGISTERDIALOG_H

#include <QDialog>
#include <QDebug>
#include <QPalette>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QTime>
#include <QMessageBox>

namespace Ui {
class RegisterDialog;
}

class RegisterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterDialog(QWidget *parent = 0);
    ~RegisterDialog();
    void setyanzheng();
    void clearAll();
    bool judgeEmpty();


private slots:
    void on_returnbtn_clicked();

    void on_registerbtn_clicked();

private:
    Ui::RegisterDialog *ui;
    int yanzheng;
    QSqlTableModel *model;
};

#endif // REGISTERDIALOG_H
