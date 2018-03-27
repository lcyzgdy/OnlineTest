#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
	int num;
	char c;
	string l;
	cin >> l;
	c = l[0];
	num = 1;
	for (int i = 1; i < l.length(); i++)
	{
		if (l[i] == l[i - 1])
		{
			num++;
		}
		else
		{
			cout << num << c;
			c = l[i];
			num = 1;
		}
	}
	cout << num << c;
	num = 1;
	return 0;
}