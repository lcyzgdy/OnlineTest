#include<iostream>
#include<algorithm>
using namespace std;

bool visited[105][105];
int mp[105][105];
int n;
int maxn;

void Dfs(int color, int x, int y, int area)
{
	maxn = max(maxn, area);
	visited[x][y] = 1;
	if (x - 1 >= 0 && mp[x - 1][y] == color && !visited[x - 1][y]) Dfs(color, x - 1, y, area + 1);
	if (x + 1 < n && mp[x + 1][y] == color && !visited[x + 1][y]) Dfs(color, x + 1, y, area + 1);
	if (y - 1 >= 0 && mp[x][y - 1] == color && !visited[x][y - 1]) Dfs(color, x, y - 1, area + 1);
	if (y + 1 < n && mp[x][y + 1] == color && !visited[x][y + 1]) Dfs(color, x, y + 1, area + 1);
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			char c;
			cin >> c;
			mp[i][j] = c == 'W' ? 1 : 0;
		}
	}
	for (int j = 0; j < n; j++)
	{
		int maxx = 1;
		for (int i = 1; i < n; i++)
		{
			if (mp[i][j] == mp[i - 1][j]) maxx++;
			else
			{
				maxn = max(maxx, maxn);
				maxx = 1;
			}
		}
		maxn = max(maxn, maxx);
	}
	cout << maxn << endl;
}