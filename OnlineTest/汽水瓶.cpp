#include<iostream>
using namespace std;

int n;

int main()
{
	while (cin >> n && n != 0)
	{
		int sum = 0;
		while (n > 0)
		{
			if (n < 3)
			{
				if (n == 2) sum++;
				break;
			}
			int newBottle = n / 3;
			sum += newBottle;
			n %= 3;
			n += newBottle;
		}
		cout << sum << endl;
	}
}