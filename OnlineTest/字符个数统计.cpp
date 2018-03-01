/*题目描述
编写一个函数，计算字符串中含有的不同字符的个数。字符在ACSII码范围内(0~127)。不在范围内的不作统计。
输入描述:
输入N个字符，字符在ACSII码范围内。
输出描述:
输出范围在(0~127)字符的个数。
示例1
输入
abc
输出
3
*/

#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int main()
{
	bool y[128];
	string l;
	memset(y, 0, sizeof(y));
	cin >> l;
	for (char c : l)
	{
		y[(int)c]++;
	}
	int sum = 0;
	for (int i = 0; i < 128; i++)
	{
		sum += y[i];
	}
	cout << sum;
	return 0;
}