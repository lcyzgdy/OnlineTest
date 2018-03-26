#include<iostream>
#include<algorithm>
using namespace std;

int s[100];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> s[i];
	sort(s, s + n);
	int x = s[1] - s[0];
	for (int i = 1; i < n; i++)
	{
		if (s[i] - s[i - 1] != x)
		{
			cout << "Impossible" << endl;
			return 0;
		}
	}
	cout << "Possible" << endl;
	return 0;
}