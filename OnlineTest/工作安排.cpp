#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int work[10];
int n, sum;
string l[6];

void Dfs(int k)
{
	if (k >= n)
	{
		sum++;
		return;
	}
	for (char c : l[k])
	{
		if (work[c - '0'] != 0) continue;
		work[c - '0'] = 1;
		Dfs(k + 1);
		work[c - '0'] = 0;
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> l[i];
	}
	for (char c : l[0])
	{
		work[c - '0'] = 1;
		Dfs(1);
		work[c - '0'] = 0;
	}
	cout << sum << endl;
	return 0;
}