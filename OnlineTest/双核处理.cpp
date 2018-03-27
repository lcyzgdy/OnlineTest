#include<iostream>
#include<algorithm>
using namespace std;

int s[55];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	sort(s, s + n);
	int c1 = 0, c2 = 0;
	for (int i = 0; i < n; i++)
	{
		if (c1 <= c2)
		{
			c1 += s[i];
		}
		else
		{
			c2 += s[i];
		}
	}
	cout << max(c1, c2) << endl;
	return 0;
}