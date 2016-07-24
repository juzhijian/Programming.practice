#include "sign_in.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	//显示登陆窗口
	sign_in w;//登录界面
	w.show();//显示界面
	return a.exec();
}
