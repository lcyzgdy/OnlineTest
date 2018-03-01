#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

int n;
int a[2005];

int f[2005];
int g[2005];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	memset(f, 0, sizeof(f));
	memset(g, 0, sizeof(g));

	for (int i = 0; i < n; i++)
	{
		f[i] = 1;
		g[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (a[j] < a[i])
			{
				f[i] = max(f[i], f[j] + 1);
			}
		}
	}

	for (int i = n - 1; i >= 0; i--)
	{
		g[i] = 1;
		for (int j = n - 1; j > i; j--)
		{
			if (a[j] < a[i])
			{
				g[i] = max(g[i], g[j] + 1);
			}
		}
	}
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		k = max(k, f[i] + g[i] - 1);
	}
	cout << n - k;
}