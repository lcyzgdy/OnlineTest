#include<iostream>
#include<vector>
using namespace std;

vector<int> v1;
vector<int> v2;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int v;
		cin >> v;
		if (i == 0)
		{
			v1.push_back(v);
			v2.push_back(v);
			continue;
		}
		if (abs(*v2.rbegin() - v) <= abs(*v1.rbegin() - v))
		{
			v2.push_back(v);
		}
		else
		{
			v1.push_back(v);
		}
	}
	int sum = 0;
	if (abs(v1[0] - v1[1]) < abs(v2[0] - v2[1]))
	{
		for (int i = 1; i < v1.size(); i++)
		{
			sum += abs(v1[i] - v1[i - 1]);
		}
		for (int i = 2; i < v2.size(); i++)
		{
			sum += abs(v2[i] - v2[i - 1]);
		}
	}
	else
	{
		for (int i = 2; i < v1.size(); i++)
		{
			sum += abs(v1[i] - v1[i - 1]);
		}
		for (int i = 1; i < v2.size(); i++)
		{
			sum += abs(v2[i] - v2[i - 1]);
		}
	}
	cout << sum << endl;
	return 0;
}