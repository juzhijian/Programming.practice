#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
	ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/* 接收槽信号 */
void MainWindow::comesign_in(QString name)
{
    user_name = name;
    //设置盒子的标题
    this->setWindowTitle(QStringLiteral("EVE盒子  登录账号：") + user_name);
    //取系统时间
	QDateTime current_date_time = QDateTime::currentDateTime();
	QString current_date = current_date_time.toString("yyyy-MM-dd hh:mm:ss");
    //写入信息
    QString sql = "update user set last_reg_time='"+ current_date + "' where user_name='" + user_name + "'";
    QSqlQuery query;
    query.exec(sql);
}

void MainWindow::on_pushButton_3_clicked()
{

}
