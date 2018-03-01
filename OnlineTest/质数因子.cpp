/*题目描述
功能:输入一个正整数，按照从小到大的顺序输出它的所有质数的因子（如180的质数因子为2 2 3 3 5 ）
最后一个数后面也要有空格

详细描述：

函数接口说明：
public String getResult(long ulDataInput)
输入参数：
long ulDataInput：输入的正整数
返回值：
String


输入描述:
输入一个long型整数
输出描述:
按照从小到大的顺序输出它的所有质数的因子，以空格隔开。最后一个数后面也要有空格。
示例1
输入
180
输出
2 2 3 3 5*/

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	long long t;
	cin >> t;
	while ((t & 1L) == 0L)
	{
		cout << 2 << ' ';
		t >>= 1;
	}
	for (int i = 3; i <= t; i += 2)
	{
		while (t % i == 0)
		{
			cout << i << ' ';
			t /= i;
		}
	}
	return 0;
}