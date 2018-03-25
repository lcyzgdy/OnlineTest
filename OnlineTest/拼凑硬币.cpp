#include<iostream>
using namespace std;

int main()
{
	unsigned long long n;
	cout << 0x7fffffffffffffffLL << endl;
	while (cin >> n)
	{
		cout << (unsigned long long)log2l(n * 2) << endl;
	}
	return 0;
}