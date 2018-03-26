#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	string l;
	cin >> n;
	while (n)
	{
		if (n & 1)
		{
			n = (n - 1) >> 1;
			l += "1";
		}
		else
		{
			n = (n - 2) >> 1;
			l += "2";
		}
	}
	reverse(l.begin(), l.end());
	cout << l << endl;
}