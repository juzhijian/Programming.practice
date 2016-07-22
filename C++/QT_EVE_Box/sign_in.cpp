
#include "sign_in.h"
#include "ui_sign_in.h"

sign_in::sign_in(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sign_in)
{
    ui->setupUi(this);
    //创建QSqlTableModel
	model = new QSqlTableModel(this);
	model->setEditStrategy(QSqlTableModel::OnManualSubmit);
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

    model->setTable("user");
    model->select();

    int i;
    for(i=0;i<model->rowCount();i++)
    {
		QSqlRecord record = model->record(i);

        if(record.value(2)==ui->userline->text()&&
                record.value(3)==ui->passwordline->text())
        {
			QString str1 = QStringLiteral("登录成功");
			QString str2 = record.value(2).toString();
			QString str3 = QStringLiteral("账号");
			QString str4 = QString::number(i);
			QMessageBox::information(this, QString::fromLocal8Bit("提示"),
				str3 + str2 + str1, QMessageBox::Yes);
			this->clearAll();
            //创建主窗口
			mw = new MainWindow;
            //连接主窗口和登录对话框信号与槽
			connect(mw, SIGNAL(tosign_in()), this, SLOT(showNormal()));
			mw->show();
			connect(this, SIGNAL(toMainWindow(QString, QString)), mw, SLOT(comesign_in(QString, QString)));
			emit toMainWindow(str2, str4);
			this->hide();
            return;
        }
        else if(record.value(2)==ui->userline->text()&&
                record.value(3)!=ui->passwordline->text())
       {
			QMessageBox::information(this, QString::fromLocal8Bit("提示"),
				QStringLiteral("密码输入有误！"), QMessageBox::Yes);
			this->clearAll();
            return;
        }
    }
	QMessageBox::warning(this, QString::fromLocal8Bit("提示"),
		QStringLiteral("用户不存在,请注册！"), QMessageBox::Yes);
    this->clearAll();
    return;
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
