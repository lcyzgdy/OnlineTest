#include<iostream>
#include<algorithm>
#include<sstream>
using namespace std;

int arr[200010];

int main()
{
	int n;
	stringstream ss;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	if (n & 1)
	{
		int t = n - 1;
		while (t >= 0)
		{
			ss << arr[t] << ' ';
			t -= 2;
		}
		t = 1;
		while (t < n)
		{
			ss << arr[t] << ' ';
			t += 2;
		}
	}
	else
	{
		int t = n - 1;
		while (t > 0)
		{
			ss << arr[t] << ' ';
			t -= 2;
		}
		t = 0;
		while (t < n)
		{
			ss << arr[t] << ' ';
			t += 2;
		}
	}
	cout << ss.str().substr(0, ss.str().length() - 1);
	return 0;
}