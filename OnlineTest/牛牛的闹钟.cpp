#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct Clock
{
	int h, m;
	int GetTime()
	{
		return h * 60 + m;
	}
};

vector<Clock> v;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		Clock t;
		cin >> t.h >> t.m;
		v.emplace_back(t);
	}
	sort(v.begin(), v.end(), [](Clock& a, Clock& b) {return a.GetTime() > b.GetTime(); });
	int cost;
	cin >> cost;
	Clock ddl;
	cin >> ddl.h >> ddl.m;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].GetTime() + cost <= ddl.GetTime())
		{
			cout << v[i].h << ' ' << v[i].m;
			return 0;
		}
	}
	return 0;
}