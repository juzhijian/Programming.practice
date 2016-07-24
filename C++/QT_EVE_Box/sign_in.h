#ifndef SIGN_IN_H
#define SIGN_IN_H

#include "mainwindow.h"
#include "registerdialog.h"

#include <QDialog>

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

    void on_registerbtn_clicked();

    void on_exitbtn_clicked();

private:
	Ui::sign_in * ui;
	MainWindow * mw;
signals:
    void toMainWindow(QString);
};

#endif // SIGN_IN_H
