#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
using namespace std;

string Encode(const string& l)
{
	string r;
	for (char c : l)
	{
		if (c >= 'a' && c <= 'z')
		{
			r += ((c - 'a') + 27) % 26 + 'A';
		}
		else if (c >= 'A' && c <= 'Z')
		{
			r += ((c - 'A') + 27) % 26 + 'a';
		}
		else
		{
			r += ((c - '0') + 11) % 10 + '0';
		}
	}
	return std::move(r);
}

string Decode(const string& l)
{
	string r;
	for (char c : l)
	{
		if (c >= 'a' && c <= 'z')
		{
			r += ((c - 'a') + 25) % 26 + 'A';
		}
		else if (c >= 'A' && c <= 'Z')
		{
			r += ((c - 'A') + 25) % 26 + 'a';
		}
		else
		{
			r += ((c - '0') + 9) % 10 + '0';
		}
	}
	return std::move(r);
}

int main()
{
	string l1;
	while (cin >> l1)
	{
		cout << Encode(l1) << endl;
		cin >> l1;
		cout << Decode(l1) << endl;
	}
	return 0;
}