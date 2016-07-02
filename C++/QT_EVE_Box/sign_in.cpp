#include "sign_in.h"
#include "ui_sign_in.h"
#include <QtWidgets>

sign_in::sign_in(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sign_in)
{
    ui->setupUi(this);
}

sign_in::~sign_in()
{
    delete ui;
}

void sign_in::on_pushButton_clicked()
{
    if(this->ui->lineEdit_name->text().trimmed()== tr("admin") &&
       this->ui->lineEdit_pwd->text().trimmed()==tr("admin"))
    {
        accept();
    }
    else
    {
        QMessageBox::warning(this, QString::fromLocal8Bit("警告"), QStringLiteral("用户名或密码错误!"));
        this->ui->lineEdit_name->clear();
        this->ui->lineEdit_pwd->clear();
        this->ui->lineEdit_name->setFocus();
    }
}

//取消
void sign_in::on_pushButton_2_clicked()
{
    this->close();
}
