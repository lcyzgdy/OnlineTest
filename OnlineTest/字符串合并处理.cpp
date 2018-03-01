#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
using namespace std;

string ProcessString(const string& l)
{
	string r;
	string l1, l2;
	for (int i = 0; i < l.length(); i++)
	{
		if (i & 1) l2 += l[i];
		else l1 += l[i];
	}
	sort(l1.begin(), l1.end());
	sort(l2.begin(), l2.end());
	if (l2.length() == l1.length())
	{
		for (int i = 0; i < l1.length(); i++)
		{
			r += l1[i];
			r += l2[i];
		}
	}
	else
	{
		for (int i = 0; i < l1.length()-1; i++)
		{
			r += l1[i];
			r += l2[i];
		}
		r += l1[l1.length() - 1];
	}
	for (int i = 0; i < r.length(); i++)
	{
		char c = r[i];
		unsigned char c1 = 0;
		int bit = 3;
		if (c >= '0' && c <= '9')
		{
			c1 = c - '0';
			unsigned char c2 = 0;
			while (c1)
			{
				unsigned char ccc = (c1 & 1);
				c2 += ccc << bit;
				bit--;
				c1 >>= 1;
			}
			if (c2 < 10)
			{
				r[i] = c2 + '0';
			}
			else
			{
				r[i] = c2 - 10 + 'A';
			}
		}
		else if (c >= 'A' && c <= 'F')
		{
			c1 = c - 'A' + 10;
			unsigned char c2 = 0;
			while (c1)
			{
				unsigned char ccc = (c1 & 1);
				c2 += ccc << bit;
				bit--;
				c1 >>= 1;
			}
			if (c2 < 10)
			{
				r[i] = c2 + '0';
			}
			else
			{
				r[i] = c2 - 10 + 'A';
			}
		}
		else if (c >= 'a' && c <= 'f')
		{
			c1 = c - 'a' + 10;
			unsigned char c2 = 0;
			while (c1)
			{
				unsigned char ccc = (c1 & 1);
				c2 += ccc << bit;
				bit--;
				c1 >>= 1;
			}
			if (c2 < 10)
			{
				r[i] = c2 + '0';
			}
			else
			{
				r[i] = c2 - 10 + 'A';
			}
		}
	}
	return r;
}

int main()
{
	string l1, l2;
	while (cin >> l1 >> l2)
	{
		l1 += l2;
		cout << ProcessString(l1) << endl;
		l1.clear();
		l2.clear();
	}
	return 0;
}