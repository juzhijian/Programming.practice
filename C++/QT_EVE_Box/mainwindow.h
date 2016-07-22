#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QDebug>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void Hcy_xieru();

private slots:

    void comesign_in(QString,QString);

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    QString studentname,studentnum;
    QSqlTableModel *model;

signals:
    void tosign_in();
};

#endif // MAINWINDOW_H
