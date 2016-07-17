#include "sign_in.h"
#include <QApplication>
#include <QIcon>
#include <QSqlDatabase>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //连接MySQL数据库
    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
    //设置主机名
    db.setHostName("192.168.100.224");
    //设置账号名
    db.setUserName("root");
    //设置密码名
    db.setPassword("Guojinxin<>?3537");
    //设置数据库名
    db.setDatabaseName("eve");
    //设置端口
    //db.setPort(3306);

    if(db.open())
    {
        //显示登陆窗口
        sign_in w;//登录界面
        w.show();//显示界面
        return a.exec();
    }
    else
    {
        QMessageBox::information(NULL, QString::fromLocal8Bit("提示"), QStringLiteral("系统载入数据库失败，无法运行！"),QMessageBox::Yes);
    }
    return 0;
}
