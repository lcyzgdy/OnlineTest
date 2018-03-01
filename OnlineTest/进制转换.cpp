/* 题目描述
	写出一个程序，接受一个十六进制的数值字符串，输出该数值的十进制字符串。（多组同时输入 ）
   输入描述:
	输入一个十六进制的数值字符串。
   输出描述:
	输出该数值的十进制字符串。
   示例1
   输入
	0xA
   输出
	10
*/

#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
	string l;
	while (cin >> l)
	{
		bool negitive = false;
		int firstInt = 2;
		int result = 0;
		if (l[0] == '-')
		{
			negitive = true;
			firstInt = 3;
		}
		for (int i = firstInt; i < l.length(); i++)
		{
			if (l[i] <= '9' && l[i] >= '0')
			{
				int a = l[i] - '0';
				result = result * 16 + a;
			}
			else
			{
				int a = l[i] - 'A' + 10;
				result = result * 16 + a;
			}
		}
		cout << result << endl;
	}
	return 0;
}