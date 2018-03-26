#include<iostream>
using namespace std;

int main()
{
	int n, t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		int a, b, c;
		a = b = c = 0;
		for (int i = 0; i < n; i++)
		{
			int d;
			cin >> d;
			if (d % 4 == 2)
			{
				c++;
			}
			else if (d % 4 == 0)
			{
				b++;
			}
			else
			{
				a++;
			}
		}
		if (a == b && (c & 1) == 0) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}