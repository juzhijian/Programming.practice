#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "mysql.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void comesign_in(QString);

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    QString user_name;

signals:
    void tosign_in();
};

#endif // MAINWINDOW_H
