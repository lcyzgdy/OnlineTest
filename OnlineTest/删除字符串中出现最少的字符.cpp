#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
using namespace std;

string l;
int sum[26];

int main()
{
	while (cin >> l)
	{
		memset(sum, 0, sizeof(sum));
		for (int i = 0; i < l.length(); i++)
		{
			sum[l[i] - 'a']++;
		}
		int minn = 0x7fffffff;
		for (int i = 0; i < 26; i++)
		{
			if (sum[i] == 0) continue;
			minn = min(minn, sum[i]);
		}
		for (char c : l)
		{
			if (sum[c - 'a'] > minn)
			{
				cout << c;
			}
		}
		cout << endl;
	}
	return 0;
}