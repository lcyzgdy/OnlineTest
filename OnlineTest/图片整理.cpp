#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
using namespace std;

int main()
{
	string l;
	cin >> l;
	sort(l.begin(), l.end());
	cout << l << endl;
	return 0;
}