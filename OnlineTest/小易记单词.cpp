#include<iostream>
#include<map>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

map<string, int> dic;
int n, m;

int main()
{
	cin >> n >> m;
	vector<string> cache;
	for (int i = 0; i < n; i++)
	{
		string l;
		cin >> l;
		cache.emplace_back(l);
	}
	for (int i = 0; i < m; i++)
	{
		string l;
		cin >> l;
		dic[l] = 0;
	}
	int source = 0;
	for (auto l : cache)
	{
		if (dic.find(l) != dic.end() && dic[l] == 0)
		{
			source += l.length() * l.length();
			dic[l]++;
		}
	}
	cout << source << endl;
	return 0;
}