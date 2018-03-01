#include<iostream>
using namespace std;

int main()
{
	int d, sum = 0;
	cin >> d;
	while (d)
	{
		sum += (d & 1);
		d >>= 1;
	}
	cout << sum;
	return 0;
}