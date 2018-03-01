#include<iostream>
#include<algorithm>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

int n;
int a[105];
int m[101][101];
int color[101];
int match0[101], match1[101];
int visited[101];

bool IsPrime(int n)
{
	if (n <= 0) return false;
	if (n == 1) return false;
	if (n == 2) return true;
	if (n == 3) return true;
	if ((n & 1) == 0) return false;
	for (int i = 3; i <= sqrt(n); i += 2)
	{
		if (n%i == 0) return false;
	}
	return true;
}

void Render(int k, int curColor)
{
	color[k] = curColor;
	for (int i = 0; i < n; i++)
	{
		if (m[k][i] == 1 && color[i] < 0) Render(i, 1 - curColor);
	}
}

int Path(int u)
{
	for (int v = 0; v < n; v++)
	{
		if (color[u] == color[v]) continue;
		if (m[u][v] == 1 && !visited[v])
		{
			visited[v] = 1;
			if (match1[v] <= -1 || Path(match1[v]))
			{
				match0[u] = v;
				match1[v] = u;
				return 1;
			}
		}
	}
	return 0;
}

void PrintMap()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << m[i][j] << ' ';
		}
		cout << endl;
	}
}
int main()
{
	while (cin >> n)
	{
		//cout << IsPrime(n) << endl;
		for (int i = 0; i < n; i++) cin >> a[i];
		memset(m, 0, sizeof(m));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (IsPrime(a[i] + a[j]))
				{
					m[i][j] = m[j][i] = 1;
				}
			}
		}

		//PrintMap();
		memset(color, 0xff, sizeof(color));
		Render(0, 0);

		int res = 0;
		memset(match0, 0xff, sizeof(match0));
		memset(match1, 0xff, sizeof(match1));
		for (int i = 0; i < n; i++)
		{
			if (color[i] != 0) continue;
			if (match0[i] <= -1)
			{
				memset(visited, 0, sizeof(visited));
				res += Path(i);
			}
		}
		cout << res << endl;
	}
	return 0;
}