#include<iostream>
#include<algorithm>
using namespace std;

int n, d;
int arr[101][101];
int sumX[101][101];
int sumY[101][101];
int maxn;

int main()
{
	cin >> n >> d;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			if (j > 0) sumY[i][j] = sumY[i][j - 1] + arr[i][j];
			else sumY[i][j] = arr[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - d + 1; j++)
		{
			int sum = 0;
			for (int k = 0; k < d; k++)
			{
				sum += arr[i][j + k];
			}
			maxn = max(sum, maxn);
		}
	}
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < n - d + 1; i++)
		{
			int sum = 0;
			for (int k = 0; k < d; k++)
			{
				sum += arr[i + k][j];
			}
			maxn = max(sum, maxn);
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i + d > n) continue;
			if (j + d > n) continue;
			int sum = 0;
			for (int k = 0; k < d; k++)
			{
				sum += arr[i + k][j + k];
			}
			maxn = max(sum, maxn);
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i + d > n) continue;
			if (j - d + 1 < 0) continue;
			int sum = 0;
			for (int k = 0; k < d; k++)
			{
				sum += arr[i + k][j - k];
			}
			maxn = max(sum, maxn);
		}
	}
	cout << maxn << endl;
	return 0;
}