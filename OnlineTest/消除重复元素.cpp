#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;

set<int> rs;
vector<int> r;
int s[100];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	for (int i = n - 1; i >= 0; i--)
	{
		if (rs.find(s[i]) == rs.end())
		{
			r.push_back(s[i]);
			rs.emplace(s[i]);
		}
	}
	reverse(r.begin(), r.end());
	cout << r[0];
	for (int i = 1; i < r.size(); i++)
	{
		cout << ' ' << r[i];
	}
	return 0;
}