#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#define maxn 10010
using namespace std;

class LinkedForwardStar
{
	struct BaseLinkedForwardStar
	{
		int u, v, cost;
		int next;
	};
	vector<BaseLinkedForwardStar> m_graphic;

public:
	LinkedForwardStar() = default;
	LinkedForwardStar(int size)
	{
		m_graphic.resize(size);
	}

	void Add(int u, int v, int value, bool direction = true)
	{
		BaseLinkedForwardStar s;
	}

	vector<int> Spfa(int from)
	{
	}
};

struct pi
{
	int to;
	int cost;
	int next;
}pp[2 * maxn];
struct ppi
{
	int to;
	int id;
	int next;
};
ppi pp1[200 * maxn];
int head[maxn], tot, vis[maxn], ed, head1[maxn], fa[maxn];
int dis[maxn], use[100 * maxn];

void add(int a, int b, int cost)
{
	pp[tot].to = b;
	pp[tot].cost = cost;
	pp[tot].next = head[a];
	head[a] = tot++;
	pp[tot].to = a;
	pp[tot].cost = cost;
	pp[tot].next = head[b];
	head[b] = tot++;
}

void add1(int a, int b, int id)
{
	pp1[ed].to = b;
	pp1[ed].id = id;
	pp1[ed].next = head1[a];
	head1[a] = ed++;
	pp1[ed].to = a;
	pp1[ed].id = id;
	pp1[ed].next = head1[b];
	head1[b] = ed++;
}

int find(int a)
{
	if (fa[a] == a || fa[a] == -1)
		return fa[a] = a;
	return fa[a] = find(fa[a]);
}

void LCA(int v, int pa, int to)
{
	int i, k;
	vis[v] = to;
	fa[v] = v;
	for (i = head1[v]; i != -1; i = pp1[i].next)
	{
		if (vis[pp1[i].to] == to)
		{
			k = find(pp1[i].to);
			use[pp1[i].id] = dis[v] + dis[pp1[i].to] - 2 * dis[k];
		}
	}
	for (i = head[v]; i != -1; i = pp[i].next)
	{
		if (pp[i].to == pa)
			continue;
		dis[pp[i].to] = dis[v] + pp[i].cost;
		LCA(pp[i].to, v, to);
		fa[pp[i].to] = v;
	}
	return;
}

int main()
{
	int i, j, n, m, p, k, f, to;
	while (scanf("%d%d%d", &n, &m, &f) != EOF)
	{
		memset(head, -1, sizeof(head));
		memset(head1, -1, sizeof(head1));
		tot = 0;
		ed = 0;
		for (i = 1; i <= m; i++)
		{
			scanf("%d%d%d", &j, &p, &k);
			add(j, p, k);
		}
		for (i = 1; i <= n; i++)
		{
			vis[i] = 0;
			fa[i] = -1;
			dis[i] = 0;
		}
		for (i = 1; i <= f; i++)
		{
			scanf("%d%d", &j, &p);
			add1(j, p, i);
			use[i] = -1;
		}
		to = 0;
		for (i = 1; i <= n; i++)
		{
			if (!vis[i])
			{
				to++;
				LCA(i, -1, to);
			}
		}
		for (i = 1; i <= f; i++)
		{
			if (use[i] < 0)
				printf("Not connected\n");
			else
				printf("%d\n", use[i]);
		}
	}
	return 0;
}