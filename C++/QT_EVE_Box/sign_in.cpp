
#include "sign_in.h"
#include "ui_sign_in.h"
#include "mysql.h"

sign_in::sign_in(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sign_in)
{
    ui->setupUi(this);
    //设置登录对话框的标题
	this->setWindowTitle(QStringLiteral("登录"));
    //设置登录对话框的图标
	this->setWindowIcon(QIcon(":/eves/img/book.jpg"));
    //设置登录对话框大小固定为399*252
	this->setMaximumSize(399, 252);
	this->setMinimumSize(399, 252);
    //设置lineedit提示语句
	ui->userline->setPlaceholderText(QStringLiteral("请输入用户名"));
	ui->passwordline->setPlaceholderText(QStringLiteral("请输入密码"));
    //设置passlineedit显示为密码模式
    ui->passwordline->setEchoMode(QLineEdit::Password);
}

/* 析构函数 */
sign_in::~sign_in()
{
    delete ui;
}

/* 用户登录 */
void sign_in::on_loginbtn_clicked()
{
    //检查是否为空
    if(!this->judgeEmpty())
    {
        ui->passwordline->clear();
        return;
    }
    QString name = ui->userline->text();
    QString passwd = ui->passwordline->text();
    QString sql = "select * from user where user_name = '"
        + name + "'and user_password ='" + passwd + "'";
    MySql mySql;
    if( mySql.queryDB(sql) )
    {
        QString str1 = mySql.formvalue.user_name;
        QMessageBox::information(this, QStringLiteral("登录成功"),
            QStringLiteral("账号") + str1 + QStringLiteral("登录成功"), QMessageBox::Ok);
        this->clearAll();
        //创建主窗口
        mw = new MainWindow;
        //连接主窗口和登录对话框信号与槽
        connect(mw, SIGNAL(tosign_in()), this, SLOT(showNormal()));
        mw->show();
        connect(this, SIGNAL(toMainWindow(QString)), mw, SLOT(comesign_in(QString)));
        emit toMainWindow(str1);
        //关闭窗体
        this->hide();
        return;
    }
    else
    {
        QMessageBox message(QMessageBox::Warning,QStringLiteral("登录失败"),
                            QStringLiteral("用户名或密码错误！是否重新登录？"),
                            QMessageBox::Yes|QMessageBox::No);

        if (message.exec()!=QMessageBox::Yes)
           {
            this->close();
           }
        this->clearAll();
        return;
    }

}

/* 清空编辑框 */
void sign_in::clearAll()
{
	ui->userline->clear();
    ui->passwordline->clear();
}

/* 检查是否为空 */
bool sign_in::judgeEmpty()
{
    if(ui->userline->text().isEmpty())
    {
		QMessageBox::warning(this, QString::fromLocal8Bit("警告"),
			QStringLiteral("用户名不能为空！"));
        return false;
    }
    if(ui->passwordline->text().isEmpty())
    {
		QMessageBox::warning(this, QString::fromLocal8Bit("警告"),
			QStringLiteral("密码不能为空！"));
        return false;
    }
    else
        return true;
}

/* 取消登录 */
void sign_in::on_exitbtn_clicked()
{
    this->close();
}

/* 用户注册 */
void sign_in::on_registerbtn_clicked()
{
    registerdialog d(this);
	this->hide();
    if(d.exec()==QDialog::Accepted)
    {
		this->showNormal();
    }
	this->clearAll();
}
