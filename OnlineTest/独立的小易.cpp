#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int x, f, d, p;
	int day;
	cin >> x >> f >> d >> p;
	if (f * x > d)
	{
		day = d / x;
	}
	else
	{
		day = (d - f * x) / (x + p) + f;
	}
	cout << day << endl;
	return 0;
}