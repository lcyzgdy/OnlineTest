#include<iostream>
#include<string>
using namespace std;

char s[30];

int A(int n)
{
	int r = 1;
	for (int i = 1; i <= n; i++) r *= i;
	return r;
}

int main()
{
	string l;
	cin >> l;
	for (char c : l)
	{
		s[c - 'A'] ++;
	}
	int count = 0;
	for (int i = 0; i < 26; i++)
	{
		if (s[i] > 0) count++;
	}
	if (count > 2) cout << 0 << endl;
	else
	{
		cout << A(count) << endl;
	}
	return 0;
}