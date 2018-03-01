#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;

struct LinkedForwardStar
{
	int u, v, c;
	int next;
} graphic[1000];
int n, m;
int point[1000];
int path[1000];
queue<int> q;

bool Spfa(int s, int v)
{
	int dis[1000];
	bool y[1000], yy = false;
	int h, i, j;
	memset(dis, 0x7f, sizeof(dis));
	memset(y, 0, sizeof(y));
	memset(path, 0, sizeof(path));
	q.push(s);
	dis[s] = 0;
	y[s] = true;
	while (!q.empty())
	{
		h = q.front();
		q.pop();
		if (h == v)
		{
			yy = true;
			break;
		}
		i = point[h];
		while (i != 0)
		{
			if ((dis[graphic[i].v] > dis[h] + 1) && (graphic[i].c > 0))
			{
				dis[graphic[i].v] = dis[h] + 1;
				if (y[graphic[i].v] != true)
				{
					q.push(graphic[i].v);
					y[graphic[i].v] = true;
				}
				path[graphic[i].v] = i;
			}
			i = graphic[i].next;
		}
		y[h] = true;
	}
	while (!q.empty()) q.pop();
	return yy;
}

int Ek(int s, int v)
{
	int maxFlow = 0, i;
	int e = 0x7fffffff;
	while (Spfa(s, v))
	{
		i = v;
		e = 0x7fffffff;
		while (i != s)
		{
			i = path[i];
			e = min(e, graphic[i].c);
			i = graphic[i].u;
		}
		i = v;
		while (i != s)
		{
			i = path[i];
			graphic[i].c -= e;
			if (graphic[i].u == graphic[i + 1].u && graphic[i].v == graphic[i + 1].v) graphic[i + 1].c += e;
			else graphic[i - 1].c += e;
			i = graphic[i].u;
		}
		maxFlow += e;
	}
	return maxFlow;
}

int main()
{
	cin >> m >> n;
	int a, b, c, d = 0;
	for (int i = 1; i <= m; i++)
	{
		cin >> a >> b >> c;
		d++;
		graphic[d].u = a;
		graphic[d].v = b;
		graphic[d].c = c;
		if (point[a] == 0)
		{
			point[a] = d;
			path[a] = d;
		}
		else
		{
			graphic[path[a]].next = d;
			path[a] = d;
		}
		d++;
		graphic[d].u = b;
		graphic[d].v = a;
		graphic[d].c = 0;
		if (point[b] == 0)
		{
			point[b] = d;
			path[b] = d;
		}
		else
		{
			graphic[path[b]].next = d;
			path[b] = d;
		}
	}
	memset(path, 0, sizeof(path));
	cout << Ek(1, n) << endl;
	return 0;
}