#ifndef MYSQL_H
#define MYSQL_H

#include <QObject>
#include <QtSql>
#include <QSqlDatabase>     //数据库类
#include <QDebug>
#include <QMessageBox>

/* 用户结构 */
struct message_info
{
    int user_id;
    int group_id;
    QString user_name;
    QString user_password;
};

class MySql : public QObject
{
    Q_OBJECT
public:
    explicit MySql(QObject *parent = 0);

    bool connDB();
    bool queryDB(const QString &sql);
    bool queryDB_new(const QString &sql);
    message_info formvalue;

private:
    QString dbDriver;
    QString dbName;
    QString userName;
    QString userPwd;
    QString hostName;
    int hostPort;

signals:

public slots:
};

#endif // MYSQL_H
