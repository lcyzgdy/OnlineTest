#include<iostream>
using namespace std;

int sss[20] = { 11,12,14,15,17,18,20,21,23,24,26,27,29,30,32,33,35,36,38,39 };

int GetSum(int i)
{
	int r = 0;
	while (i)
	{
		r += i % 10;
		i /= 10;
	}
	return r;
}

int main()
{
	int l, r;
	cin >> l >> r;
	int sum = 0;
	if (r <= 10)
	{
		for (int i = l; i <= r; i++)
		{
			int lll = 0;
			for (int j = 1; j <= i; j++)
			{
				lll += GetSum(j);
			}
			if (lll % 3 == 0) sum++;
		}
	}
	else
	{
		sum = 6;
		int l3 = (l + 10) % 30;
		int r3 = (r + 10) % 30;
		sum += ((r + 10) / 30) * 20 - (l + 10) / 30 * 20;
		for (int i = 0; i < 20; i++)
		{
			if (l3 + 10 >= sss[i])
			{
				sum -= i;
				break;
			}
		}
		for (int i = 19; i >= 0; i--)
		{
			if (r3 + 10 < sss[i])
			{
				sum += i;
			}
		}
	}
	cout << sum << endl;
	return 0;
}