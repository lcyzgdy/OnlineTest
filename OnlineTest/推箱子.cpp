#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int n, m;
char mp[10][10];
bool visited[10][10];
int playerX, playerY;
int boxX, boxY;
int targetX, targetY;
int minn = 0x3f3f3f3f;

inline int Distance(int x1, int y1, int x2, int y2)
{
	return abs(x1 - x2) + abs(y1 - y2);
}

void Dfs(int px, int py, int bx, int by, int step)
{
	visited[px][py] = true;
	if (mp[bx][by] == '@')
	{
		minn = min(minn, step);
		visited[px][py] = false;
		return;
	}
	if (step + Distance(bx, by, targetX, targetY) > minn)
	{
		visited[px][py] = false;
		return;
	}

	if (bx == px - 1 && by == py)
	{
		if (bx - 1 >= 0 && mp[bx - 1][by] != '#' && !visited[px - 1][py])
		{
			Dfs(px - 1, py, bx - 1, by, step + 1);
		}
	}
	else// (bx != px - 1)
	{
		if (px - 1 >= 0 && mp[px - 1][py] != '#' && !visited[px - 1][py])
		{
			Dfs(px - 1, py, bx, by, step + 1);
		}
	}

	if (bx == px + 1 && by == py)
	{
		if (bx + 1 < n && mp[bx + 1][by] != '#"' && !visited[px + 1][py])
		{
			Dfs(px + 1, py, bx + 1, by, step + 1);
		}
	}
	else// (bx != px + 1)
	{
		if (px + 1 < n && mp[px + 1][py] != '#' && !visited[px + 1][py])
		{
			Dfs(px + 1, py, bx, by, step + 1);
		}
	}

	if (bx == px && py - 1 == by)
	{
		if (by - 1 >= 0 && mp[bx][by - 1] != '#' && !visited[px][py - 1])
		{
			Dfs(px, py - 1, bx, by - 1, step + 1);
		}
	}
	else
	{
		if (py - 1 >= 0 && mp[px][py - 1] != '#' && !visited[px][py - 1])
		{
			Dfs(px, py - 1, bx, by, step + 1);
		}
	}
	if (step <= 5)
	{
		int kkkk = max(1, 2);
	}
	if (bx == px && by == py + 1)
	{
		if (by + 1 < m && mp[bx][by + 1] != '#' && !visited[px][py + 1])
		{
			Dfs(px, py + 1, bx, by + 1, step + 1);
		}
	}
	else
	{
		if (py + 1 < m && mp[px][py + 1] != '#' && !visited[px][py + 1])
		{
			Dfs(px, py + 1, bx, by, step + 1);
		}
	}
	visited[px][py] = false;
}

int main()
{
	cin >> n >> m;
	minn = n * m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> mp[i][j];
			if (mp[i][j] == 'X')
			{
				playerX = i;
				playerY = j;
				mp[i][j] = '.';
			}
			if (mp[i][j] == '*')
			{
				boxX = i;
				boxY = j;
				mp[i][j] = '.';
			}
			if (mp[i][j] == '@')
			{
				targetX = i;
				targetY = j;
				mp[i][j] = '.';
			}
		}
	}
	Dfs(playerX, playerY, boxX, boxY, 0);
	cout << ((minn >= n * m) ? -1 : minn) << endl;
	return 0;
}