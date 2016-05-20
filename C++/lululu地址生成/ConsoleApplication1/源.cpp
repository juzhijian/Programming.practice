#include<iostream>
using namespace std;
void abc();

int main()
{
	abc();
	abc();
	return 0;
}

void abc()
{
	int r = 0, y, n, p;
	cout << "最大日期2015年8月请输入年份：";
	cin >> n;
	cout << endl;
	cout << "请输入月份：";
	cin >> y;
	cout << endl;
	cout << "请输入批次：";
	cin >> p;
	for (size_t i = 0; i < 31; i++)
	{
		r = r + 1;
		cout << "http://down.jyfz.info/mnt/" << n << "-" << y << "-" << r << "-" << p << ".rar" << endl;
	}
}