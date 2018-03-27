#include<iostream>
#include<algorithm>
using namespace std;

int n, k;
int s[100];
int ss[100];

int main()
{
	cin >> n >> k;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
		sum += s[i];
	}
	for (int i = 0; i < n; i++)
	{
		int j = k % n;
		while (j--)
		{
			ss[i] += s[(j + i) % n] % 100;
			ss[i] %= 100;
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << (s[i] + sum * (k / n)) << ' ';
	}
	return 0;
}