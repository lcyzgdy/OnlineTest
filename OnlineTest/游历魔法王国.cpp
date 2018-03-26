#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct TreeNode
{
	int id;
	int parent;
	vector<int> next;
} city[51];
int visited[51];
int n, l;
int sum;


int Unvisited()
{
	int r = 0;
	for (int i = 0; i < n; i++) r += visited[i] > 0? 0 : 1;
	return r;
}

int Visited()
{
	int r = 0;
	for (int i = 0; i < n; i++) r += visited[i] == true ? 1 : 0;
	return r;
}

void Print()
{
	cout << sum << endl;
	exit(0);
}

void Dfs(int id, int l)
{
	int t = l;
	if (Unvisited() <= 0)
	{
		int r = 0;
		for (int i = 0; i < n; i++) r += visited[i] > 0 ? 1 : 0;
		sum = max(sum, r);
		return;
	}
	visited[id]++;
	if (l == 0)
	{
		int r = 0;
		for (int i = 0; i < n; i++) r += visited[i] > 0 ? 1 : 0;
		sum = max(sum, r);
		visited[id]--;
		return;
	}
	if (Unvisited() <= 0)
	{
		visited[id]--;
		return;
	}
	for (int i = 0; i < city[id].next.size(); i++)
	{
		if (visited[city[id].next[i]] > 0) continue;
		Dfs(city[id].next[i], l - 1);
	}
	if (city[id].parent != id) Dfs(city[id].parent, l - 1);
	visited[id]--;
}

int main()
{
	cin >> n >> l;
	for (int i = 0; i < n - 1; i++)
	{
		int a;
		cin >> a;
		city[i].id = i;
		city[i + 1].parent = a;
		city[a].next.push_back(i + 1);
	}
	Dfs(0, l);
	Print();
	return 0;
}