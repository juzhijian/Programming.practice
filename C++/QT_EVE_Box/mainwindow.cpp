#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //创建model用于与数据库交互
    model=new QSqlTableModel(this);
    model->setTable("user");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    Hcy_xieru();
}

MainWindow::~MainWindow()
{
    delete ui;
}

/* 接收槽信号 */
void MainWindow::comesign_in(QString name,QString num)
{
    studentname = name;
    studentnum = num;
    //设置学生成绩管理界面的标题
    this->setWindowTitle(QStringLiteral("EVE盒子  登录账号：") + studentname);
    ui->studentnameline->setText(studentname);
    //取系统时间
    QDateTime current_date_time = QDateTime::currentDateTime();
    QString current_date = current_date_time.toString("yyyy-MM-dd hh:mm:ss");
    //写入信息
    model->select();
    model->setData(model->index(studentnum.toInt(),8),current_date);
    model->submitAll();
}

/* 写入信息 */
void MainWindow::Hcy_xieru()
{

}
