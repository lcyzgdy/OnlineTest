#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n, m;
int s[8003][1004];
int f[8003][1004];

int main()
{
	cin >> n >> m;
	int i, j, k;
	memset(s, 128, sizeof(s));
	memset(f, -11, sizeof(f));
	for (i = 1; i <= m; i++)
	{
		for (j = 1; j <= n; j++)
		{
			cin >> s[i][j];
			if (s[i][j] == -1) s[i][j] = -0x77777777;
		}
	}
	for (i = 1; i <= n; i++)
	{
		f[m][i] = s[m][i];
	}
	for (i = (m - 1); i >= 1; i--)
	{
		for (j = 1; j <= n; j++)
		{
			f[i][j] = max({ f[i + 1][j], f[i + 1][j - 1], f[i + 1][j + 1] }) + s[i][j];
		}
	}
	j = 0;
	for (i = 1; i <= n; i++)
	{
		j = (j > f[1][i]) ? j : f[1][i];
	}
	cout << j << endl;
	return 0;
}