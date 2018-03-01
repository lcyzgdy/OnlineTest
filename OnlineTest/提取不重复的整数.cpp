/*题目描述
输入一个int型整数，按照从右向左的阅读顺序，返回一个不含重复数字的新的整数。
输入描述:
输入一个int型整数
输出描述:
按照从右向左的阅读顺序，返回一个不含重复数字的新的整数
示例1
输入
9876673
输出
37689
*/

#include<iostream>
#include<string>
#include<cstring>
using namespace std;

string l;
bool b[11];

int main()
{
	memset(b, 0, sizeof(b));
	cin >> l;
	for (int i = l.length() - 1; i >= 0; i--)
	{
		if (!b[l[i] - '0'])
		{
			cout << l[i];
			b[l[i] - '0'] = true;
		}
	}
	return 0;
}