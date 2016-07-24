#include "mysql.h"

MySql::MySql(QObject *parent) : QObject(parent)
{
	//设置驱动名
	dbDriver = "QMYSQL";
	//设置数据库名
	dbName = "eve";
	//设置用户名
	userName = "root";
	//设置用户密码
	userPwd = "Guojinxin<>?3537";
	//设置主机名
	hostName = "192.168.100.224";
	//设置端口
	hostPort = 5432;
	connDB();
}

/* 连接数据库 */
bool MySql::connDB()
{
	//连接MySQL数据库
	QSqlDatabase db = QSqlDatabase::addDatabase(dbDriver);
	//设置主机名
	db.setHostName(hostName);
	//设置数据库名
	db.setDatabaseName(dbName);
	//设置用户名
	db.setUserName(userName);
	//设置用户密码
	db.setPassword(userPwd);

	//发送连接
	if (!db.open())
	{
		//  qDebug() << QSqlDatabase::drivers();
		qDebug() << db.lastError();
		QMessageBox message(QMessageBox::Warning, QStringLiteral("提示"),
			QStringLiteral("系统载入数据库失败，无法运行！"),
			QMessageBox::Yes);

		if (message.exec() == QMessageBox::Yes)
		{
			qDebug() << "clicked yes\n";
			//退出程序
			QTimer::singleShot(0, qApp, SLOT(quit()));
		}
		return false;
	}
	return true;
}

/* 登录判断 */
bool MySql::queryDB(const QString &sql)
{
	QSqlQuery query;
	query.exec(sql);
	if (query.next())
	{
		formvalue.user_id = query.value(0).toInt();
		formvalue.group_id = query.value(1).toInt();
		formvalue.user_name = query.value(2).toString();
		formvalue.user_password = query.value(3).toString();
		//qDebug() << formvalue.user_name;
		//qDebug() << formvalue.user_password;
		return true;
	}
	return false;
}

/* 新建用户 */
bool MySql::queryDB_new(const QString &sql)
{
	QSqlQuery query;
	query.exec(sql);
	if (!query.next())
	{
		//qDebug() << formvalue.user_name;
		//qDebug() << formvalue.user_password;
		return true;
	}
	return false;
}
