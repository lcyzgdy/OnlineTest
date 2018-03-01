#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
using namespace std;

string l1, l2;

int main()
{
	while (cin >> l1)
	{
		for (int i = 0; i < l1.length(); i += 8)
		{
			string l = l1.substr(i, 8);
			while (l.length() < 8) l += '0';
			cout << l << endl;
		}
	}
	return 0;
}