#include "registerdialog.h"
#include "ui_registerdialog.h"

registerdialog::registerdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registerdialog)
{
    ui->setupUi(this);
    //创建model,进行数据库操作
	model = new QSqlTableModel(this);
	model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    //设置注册对话框标题
	this->setWindowTitle(QStringLiteral("注册用户"));
    //设置两行密码lineedit的显示
    ui->passwordline->setEchoMode(QLineEdit::PasswordEchoOnEdit);
    ui->passwordline1->setEchoMode(QLineEdit::PasswordEchoOnEdit);
    //设置lineedit提示语句
	ui->userline->setPlaceholderText(QStringLiteral("请输入用户名"));
    ui->passwordline->setPlaceholderText(QStringLiteral("请输入密码"));
    ui->passwordline1->setPlaceholderText(QStringLiteral("请重新输入密码"));
    ui->lineEdit_qq->setPlaceholderText(QStringLiteral("请输入您的QQ"));
    ui->lineEdit_maill->setPlaceholderText(QStringLiteral("请输入您的邮箱"));
    ui->yanzhengline->setPlaceholderText(QStringLiteral("请输入验证码"));
    //设置验证码
	QTime t;
	t = QTime::currentTime();
	qsrand(t.msec() + t.second() * 1000);
    this->setyanzheng();
}

registerdialog::~registerdialog()
{
    delete ui;
}

/* 返回 */
void registerdialog::on_returnbtn_clicked()
{
    this->accept();
}

/* 设置验证码 */
void registerdialog::setyanzheng()
{
	QPalette p1;
	p1.setColor(QPalette::WindowText, Qt::red);
	yanzheng = qrand() % 10000;
	while (yanzheng < 1000)
		yanzheng = qrand() % 10000;
	ui->yanzhenglabel->setText(QString::number(yanzheng));
	ui->yanzhenglabel->setPalette(p1);
}

/* 清空lineedit的上的文本 */
void registerdialog::clearAll()
{
    ui->userline->clear();
    ui->passwordline->clear();
    ui->passwordline1->clear();
    ui->lineEdit_qq->clear();
    ui->lineEdit_maill->clear();
    ui->yanzhengline->clear();
}

/* 判断lineedit是否为空 */
bool registerdialog::judgeEmpty()
{
    if(ui->userline->text().isEmpty())
    {
		QMessageBox::warning(this, QStringLiteral("警告"),
			QStringLiteral("用户名不能为空"));
		return false;
    }
    else if(ui->passwordline->text().isEmpty()||
            ui->passwordline1->text().isEmpty())
    {
		QMessageBox::warning(this, QStringLiteral("警告"),
			QStringLiteral("用户密码不能为空"));
        return false;
    }
    else if(ui->lineEdit_qq->text().isEmpty())
    {
		QMessageBox::warning(this, QStringLiteral("警告"),
			QStringLiteral("用户QQ号不能为空"));
        return false;
    }
    else if(ui->lineEdit_maill->text().isEmpty())
    {
		QMessageBox::warning(this, QStringLiteral("警告"),
			QStringLiteral("用户邮箱不能为空"));
        return false;
    }
    else if(ui->yanzhengline->text().isEmpty())
    {
		QMessageBox::warning(this, QStringLiteral("警告"),
			QStringLiteral("验证码不能为空"));
        return false;
    }
    else
        return true;
}

/* 注册 */
void registerdialog::on_registerbtn_clicked()
{
    int i;
    //判断lineedit是否为空
    if(!this->judgeEmpty())
    {
        ui->passwordline->clear();
        ui->passwordline1->clear();
        ui->yanzhengline->clear();
        return;
    }
    //判断两次密码输入是否一致
    if(ui->passwordline->text()!=ui->passwordline1->text())
    {
		QMessageBox::warning(this, QStringLiteral("警告"),
			QStringLiteral("两次密码输入不一致"), QMessageBox::Yes);
        ui->passwordline->clear();
        ui->passwordline1->clear();
        ui->yanzhengline->clear();
        this->setyanzheng();
        return;
    }
    //判断验证码输入是否正确
    if(ui->yanzhenglabel->text()!=ui->yanzhengline->text())
    {
		QMessageBox::warning(this, QStringLiteral("警告"),
			QStringLiteral("验证码输入错误"), QMessageBox::Yes);
        ui->passwordline->clear();
        ui->passwordline1->clear();
        ui->yanzhengline->clear();
        this->setyanzheng();
        return;
    }
    //设置table为user表
    model->setTable("user");
    model->select();
    for(i=0;i<model->rowCount();i++)
    {
        QSqlRecord record=model->record(i);
        //判断学生信息已经存在
        if((record.value(2)==ui->userline->text()&&record.value(3)!=""))
        {
			QMessageBox::warning(this, QStringLiteral("警告"),
				QStringLiteral("用户已存在"), QMessageBox::Yes);
            this->clearAll();
            this->setyanzheng();
            return;
            }
        }
    //如果学生信息不存在,添加学生信息进数据库
    if(i==model->rowCount())
    {
		QSqlRecord record1 = model->record();
        //取系统时间
		QDateTime current_date_time = QDateTime::currentDateTime();
		QString current_date = current_date_time.toString("yyyy-MM-dd hh:mm:ss");
        //写入数据
		record1.setValue("group_id", 0);
		record1.setValue("user_name", ui->userline->text());
		record1.setValue("user_password", ui->passwordline->text());
		record1.setValue("user_qq", ui->lineEdit_qq->text());
		record1.setValue("user_maill", ui->lineEdit_maill->text());
		record1.setValue("register_time", current_date);
		model->insertRecord(-1, record1);
        }
    //判断学生信息是否上传数据库成功
    if(model->submitAll())
    {
		QMessageBox::information(this, QStringLiteral("警告"),
			QStringLiteral("恭喜你注册成功^*^"), QMessageBox::Yes);
        this->accept();
    }
    //上传不成功
    else
    {
		QMessageBox::information(this, QStringLiteral("警告"),
			QStringLiteral("注册失败请重新注册"), QMessageBox::Yes);
    }
    this->clearAll();
    this->setyanzheng();
}
