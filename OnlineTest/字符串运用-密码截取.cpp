#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
using namespace std;

string l;
bool f[5001][5001];

string LongestPalindrome(const string& l)
{
	int n = l.length();
	memset(f, 0, sizeof(f));
	int maxLen = 1;
	int st = 0;
	for (int i = 0; i < l.length(); i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (i - j < 2)
			{
				f[j][i] = (l[i] == l[j]);
			}
			else
			{
				f[j][i] = (l[i] == l[j] && f[j + 1][i - 1]);
			}
			if (f[j][i] && maxLen < i - j + 1)
			{
				maxLen = i - j + 1;
				st = j;
			}
		}
	}
	return l.substr(st, maxLen);
}


int Manacher(const string& inStr)
{
	string l;
	for (int i = 0; i < inStr.length(); i++)
	{
		l += '#';
		l += inStr[i];
	}
	l += '#';
	int len = 2 * inStr.length() + 1;
	int maxR = 0, pos = 0, maxLength = 0;
	int* r = new int[len];
	for (int i = 0; i < len; i++)
	{
		if (i < maxR)
		{
			r[i] = min(r[2 * pos - i], maxR - i);
		}
		else
		{
			r[i] = 1;
		}
		while (i - r[i] >= 0 && r[i] + i < len && l[i - r[i]] == l[i + r[i]])
		{
			r[i]++;
		}
		if (maxR < r[i] + i - 1)
		{
			maxR = r[i] + i - 1;
			pos = i;
		}
		maxLength = max(maxLength, r[i] - 1);
	}
	return maxLength;
}


int main()
{
	cin >> l;
	cout << Manacher(l) << endl;
	return 0;
}