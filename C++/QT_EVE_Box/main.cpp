#include "mainwindow.h"
#include <QApplication>
#include "sign_in.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;//主界面
    sign_in login;//登录界面
    login.show();

    if(login.exec()==QDialog::Accepted)
    {
         w.show();
         return a.exec();
    }
    else
        return 0;

}
