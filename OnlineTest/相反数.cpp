#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	string l = to_string(n);
	reverse(l.begin(), l.end());
	int m = stoi(l);
	cout << m + n << endl;
	return 0;
}