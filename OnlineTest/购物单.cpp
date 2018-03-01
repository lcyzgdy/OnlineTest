#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;

struct Property
{
	int value;
	int weight;
	int child1, child2;
	bool main;
};

int n, m;
vector<Property> t;

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int v, p, q;
		cin >> v >> p >> q;
		Property a;
		a.child1 = a.child2 = -1;
		a.value = v * p;
		a.weight = v;
		if (q == 0)
		{
			a.main = true;
		}
		else
		{
			q--;
			a.main = false;
			if (t[q].child1 < 0)
			{
				t[q].child1 = i;
			}
			else
			{
				t[q].child2 = i;
			}
		}
		t.emplace_back(a);
	}
	for (int i = 0; i < t.size(); i++)
	{
		if (t[i].child1 >= 0)
		{
			Property a;
			a.main = true;
			a.value = t[i].value + t[t[i].child1].value;
			a.weight = t[i].weight + t[t[i].child1].weight;
			a.child1 = a.child2 = -1;
			t.emplace_back(a);
		}
		if (t[i].child2 >= 0)
		{
			Property a;
			a.main = true;
			a.value = t[i].value + t[t[i].child2].value;
			a.weight = t[i].weight + t[t[i].child2].weight;
			a.child1 = a.child2 = -1;
			t.emplace_back(a);

			Property b;
			b.main = true;
			b.value = t[i].value + t[t[i].child1].value + t[t[i].child2].value;
			b.weight = t[i].weight + t[t[i].child1].weight + t[t[i].child2].weight;
			b.child1 = b.child2 = -1;
			t.emplace_back(b);
		}
	}
	int f[32001];
	memset(f, 0, sizeof(f));
	for (Property& i : t)
	{
		if (!i.main) continue;
		for (int j = n; j >= 0; j--)
		{
			if (j >= i.weight)
			{
				f[j] = max(f[j], f[j - i.weight] + i.value);
			}
		}
	}
	cout << f[n];
	return 0;
}