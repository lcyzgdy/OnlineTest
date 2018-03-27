#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	int sum = 0;
	sum = (1 + (n - k)) * (n - k) / 2;
	for (int i = k; i <= n; i++)
	{
		for (int j = k; j <= n; j++)
		{
			if (j > i) break;
			if (i%j >= k) sum++;
		}
	}
	cout << sum;
	return 0;
}