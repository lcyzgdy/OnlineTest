#include<iostream>
//#include<fstream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<vector>
#include<cstdio>
using namespace std;

struct ForwardStar
{
	int u, v, data;
} w[100010];
int n, m;
vector<int> s[20010];
int color[20010];
int clash[3];
int f[100010];

bool cmp(ForwardStar a, ForwardStar b)
{
	return a.data > b.data;
}

int Find(int i)
{
	if (f[i] == i) return f[i];
	f[i] = Find(f[i]);
	return f[i];
}

void Kruskal()
{
	int x, y;
	int t = 0;
	for (int i = 1; i <= m; i++) f[i] = i;
	for (int i = 1; i <= m; i++)
	{
		x = Find(w[i].u);
		y = Find(w[i].v);
		if (x != y)
		{
			f[x] = y;
			t++;
			s[w[i].u].push_back(w[i].v);
			s[w[i].v].push_back(w[i].u);
			if (t == n - 1) break;
		}
	}
}

void Dye(int u, int curCol)
{
	if (color[u] != 0) return;
	color[u] = curCol;
	for (int i = 0; i < s[u].size(); i++) Dye(s[u][i], 3 ^ curCol);
}

int main()
{
	//freopen("prison.in", "r", stdin);
	//freopen("prison.out", "w", stdout);
	cin >> n >> m;
	int a, b, c;
	for (int i = 1; i <= m; i++) // ����Ϊʲô��1��ʼ����ʱӦ����һʱ�Գ顣
	{
		//scanf("%d %d %d", &a, &b, &c);
		cin >> a >> b >> c;
		w[i].u = a;
		w[i].v = b;
		w[i].data = c;
	}
	sort(w + 1, w + 1 + m, [](ForwardStar& a, ForwardStar& b) { return a.data > b.data; });
	Kruskal();
	Dye(1, 1); //Ⱦɫ���ֱ���1��2��ʾ��1^3=2,2^3=1����3��ȥ������Ҳ���ԡ�
	for (int i = 1; i <= m; i++)
	{
		if (color[w[i].u] == color[w[i].v]) clash[color[w[i].u]] = max(clash[color[w[i].u]], w[i].data);
	}
	cout << max(clash[1], clash[2]); //����һ�п��Բ��÷ֱ�������������.
	return 0;
}