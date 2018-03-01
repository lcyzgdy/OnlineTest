#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
using namespace std;

int n;
set<int> a;

int main()
{
	while (cin >> n)
	{
		a.clear();
		for (int i = 0; i < n; i++)
		{
			int a;
			cin >> a;
			a.emplace(a);
		}
		for (auto i = a.begin(); i != a.end(); i++)
		{
			cout << *i << endl;
		}
	}
	return 0;
}