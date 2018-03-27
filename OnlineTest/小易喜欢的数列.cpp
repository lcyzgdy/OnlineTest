#include<iostream>
#include<fstream>
using namespace std;

int sum;
int arr[15];
int n, k;

ofstream out("table.txt");

void Dfs(int layer)
{
	if (layer == n)
	{
		sum = (sum + 1) % 1000000007;
		return;
	}
	for (int i = 1; i <= k; i++)
	{
		arr[layer] = i;
		if (arr[layer - 1] <= arr[layer] || arr[layer - 1] % arr[layer] != 0)
		{
			Dfs(layer + 1);
		}
	}
}

int main()
{
	for (n = 1; n <= 10; n++)
	{
		for (k = 1; k <= 100000; k++)
		{
			sum = 0;
			if (n == 1) sum = k;
			else for (int i = 1; i <= k; i++)
			{
				arr[0] = i;
				Dfs(1);
			}
			out << sum << ' ';
		}
	}
}