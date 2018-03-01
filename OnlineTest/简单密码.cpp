#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
using namespace std;

string l;

int main()
{
	while (cin >> l)
	{
		if (l == "END") break;
		for (int i = 0; i < l.length(); i++)
		{
			if (l[i] <= 'z' && l[i] >= 'w')
			{
				l[i] = '9';
			}
			else if (l[i] <= 'v' && l[i] >= 't')
			{
				l[i] = '8';
			}
			else if (l[i] <= 's' && l[i] >= 'p')
			{
				l[i] = '7';
			}
			else if (l[i] >= 'a' && l[i] <= 'o')
			{
				l[i] = '0' + (l[i] - 'a') / 3 + 2;
			}
			else if (l[i] >= 'A' && l[i] <= 'Z')
			{
				l[i] = (char)(((int)(l[i] - 'A') + 1) % 26) + 'a';
			}
		}
		cout << l << endl;
	}
	return 0;
}