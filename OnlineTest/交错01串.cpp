#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int len01 = 0;
	for (int i = 0; i < s.length(); i++)
	{
		int cur = s[i] - '0';
		int len = 0;
		for (int j = i; j < s.length(); j++)
		{
			if ((s[j] - '0') == (cur & 1))
			{
				len++;
				cur = ~cur;
			}
			else break;
		}
		len01 = max(len01, len);
	}
	cout << len01;
	return 0;
}