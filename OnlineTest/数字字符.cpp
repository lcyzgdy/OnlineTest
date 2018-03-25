#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

int has[10];

int main()
{
	string l;
	cin >> l;
	memset(has, 0, sizeof(has));
	for (char c : l)
	{
		has[c - '0']++;
	}
	for (int i = 1; i < 10000000; i++)
	{
		int h = i;
		while (h)
		{
			if (has[h % 10] == 0)
			{
				cout << i << endl;
				return 0;
			}
			h /= 10;
		}
	}
	sort(l.begin(), l.end());
	int d = min(*has, *(has + 10));
	if (d == 0)
	{
		cout << 1;
		for (int i = 0; i < has[0]; i++)
		{
			cout << 0;
		}
		cout << endl;
		return 0;
	}
	else
	{
		cout << d;
		for (int i = 0; i < has[1]; i++) cout << 0;
		for (int i = 0; i < has[d] - 1; i++) cout << d;
		cout << endl;
		return 0;
	}
	return 0;
}