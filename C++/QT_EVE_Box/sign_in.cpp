#include "sign_in.h"
#include "ui_sign_in.h"
#include <QtWidgets>

sign_in::sign_in(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sign_in)
{
    ui->setupUi(this);
    //����QSqlTableModel
    model=new QSqlTableModel(this);
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    //���õ�¼�Ի���ı���
    this->setWindowTitle(QStringLiteral("��¼"));
    //���õ�¼�Ի����ͼ��
    this->setWindowIcon(QIcon(":/eves/img/book.jpg"));
    //���õ�¼�Ի����С�̶�Ϊ399*252
    this->setMaximumSize(399,252);
    this->setMinimumSize(399,252);    
    //����������ť��ͼ��
    ui->exitbtn->setIcon(QIcon(":/eves/img/exit.png"));
    ui->registerbtn->setIcon(QIcon(":/eves/img/log.png"));
    ui->loginbtn->setIcon(QIcon(":/eves/img/Enter.png"));
    //����ͼƬ
    ui->piclabel->setPixmap(QPixmap(":/student/img/log.png").scaled(ui->piclabel->size()));
    //����lineedit��ʾ���
    ui->userline->setPlaceholderText(QStringLiteral("�������û���"));
    ui->passwordline->setPlaceholderText(QStringLiteral("����������"));
    //����passlineedit��ʾΪ����ģʽ
    ui->passwordline->setEchoMode(QLineEdit::Password);
}

/* �������� */
sign_in::~sign_in()
{    
    delete ui;
}

/* �û���¼ */
void sign_in::on_loginbtn_clicked()
{
    //����Ƿ�Ϊ��
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
        QSqlRecord record=model->record(i);

        if(record.value(2)==ui->userline->text()&&
                record.value(3)==ui->passwordline->text())
        {
            QString str1=QStringLiteral("��¼�ɹ�");
            QString str2=record.value(2).toString();
            QString str3=QStringLiteral("�˺�");
            QMessageBox::information(this,QString::fromLocal8Bit("��ʾ"),str3+str2+str1,QMessageBox::Yes);
            this->clearAll();
            //����������
            mw = new MainWindow;
            //���ӹ����ں͵�¼�Ի����ź����
            connect(mw,SIGNAL(toLoginDialog()),this,SLOT(showNormal()));
            mw->show();
            connect(this,SIGNAL(toMainWindow(QString,QString)),mw,SLOT(comeLoginDialog(QString,QString)));
            emit toMainWindow(str2,record.value(0).toString());
            this->hide();
            return;
        }
        else if(record.value(2)==ui->userline->text()&&
                record.value(3)!=ui->passwordline->text())
       {
            QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QStringLiteral("������������"),QMessageBox::Yes);
            this->clearAll();
            return;
        }
    }
    QMessageBox::warning(this, QString::fromLocal8Bit("��ʾ"), QStringLiteral("�û�������,��ע�ᣡ"),QMessageBox::Yes);
    this->clearAll();
    return;
}

/* ��ձ༭�� */
void sign_in::clearAll()
{
    ui->userline->clear();
    ui->passwordline->clear();
}

/* ����Ƿ�Ϊ�� */
bool sign_in::judgeEmpty()
{
    if(ui->userline->text().isEmpty())
    {
        QMessageBox::warning(this, QString::fromLocal8Bit("����"), QStringLiteral("�û�������Ϊ�գ�"));
        return false;
    }
    if(ui->passwordline->text().isEmpty())
    {
        QMessageBox::warning(this, QString::fromLocal8Bit("����"), QStringLiteral("���벻��Ϊ�գ�"));
        return false;
    }
    else
        return true;
}

/* ȡ����¼ */
void sign_in::on_exitbtn_clicked()
{
    this->close();
}
