#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct TreeNode
{
	int id;
	int parent;
	int depth;
	vector<int> next;
} city[51];
int visited[51];
int n, l;
int sum;


int Unvisited()
{
	int r = 0;
	for (int i = 0; i < n; i++) r += visited[i] > 0 ? 0 : 1;
	return r;
}

int Visited()
{
	int r = 0;
	for (int i = 0; i < n; i++) r += visited[i] > 0 ? 1 : 0;
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
	if (sum >= n) return;
	visited[id]++;
	if (Unvisited() <= 0)
	{
		int r = 0;
		for (int i = 0; i < n; i++) r += (visited[i] > 0 ? 1 : 0);
		sum = max(sum, r);
		visited[id]--;
		return;
	}
	if (l == 0)
	{
		int r = 0;
		for (int i = 0; i < n; i++) r += (visited[i] > 0 ? 1 : 0);
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
	if (city[id].parent >= 0) Dfs(city[id].parent, l - 1);
	visited[id]--;
}

int maxDepth;

int main()
{
	cin >> n >> l;
	for (int i = 0; i < n - 1; i++)
	{
		int a;
		cin >> a;
		city[i].id = i;
		city[i + 1].parent = a;
		city[i + 1].depth = city[a].depth + 1;
		maxDepth = max(city[i + 1].depth, maxDepth);
		city[a].next.push_back(i + 1);
	}
	city[0].parent = -1;
	//Dfs(0, l);
	if (maxDepth > l)
	{
		sum = l;
	}
	else
	{
		sum = (l - maxDepth) / 2 + maxDepth;
	}
	if (sum > n - 1) sum = n - 1;
	cout << sum + 1 << endl;
	//Print();
	return 0;
}