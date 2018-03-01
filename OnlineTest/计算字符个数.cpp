#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
using namespace std;

string l;
char c;

int main()
{
	getline(cin, l);
	cin >> c;
	int sum = 0;
	for (int i = 0; i < l.length(); i++)
	{
		if (l[i] < 'a') l[i] = l[i] - 'A' + 'a';
	}
	if (c < 'a') c = c - 'A' + 'a';
	for (char i : l)
	{
		if (i == c)
			sum++;
	}
	cout << sum;
	return 0;
}