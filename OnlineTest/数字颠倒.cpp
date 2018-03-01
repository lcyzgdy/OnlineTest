#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

string l;

int main()
{
	cin >> l;
	reverse(l.begin(), l.end());
	cout << l;
	return 0;
}