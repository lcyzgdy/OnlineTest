#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

string l;

int main()
{
	getline(cin, l);
	cout << l.length() - l.find_last_of(' ') - 1;
	return 0;
}