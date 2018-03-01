#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
using namespace std;

string line;
int sum[10];
bool flag;
char last;

int main()
{
	while (cin >> line)
	{
		if (line == "END") break;
		if (line.length() <= 8)
		{
			cout << "NG" << endl;
			continue;
		}
		memset(sum, 0, sizeof(sum));
		last = 0;
		flag = 0;
		bool success = true;
		for (int i = 0; i < line.length(); i++)
		{
			char c = line[i];
			if (c == last && flag)
			{
				cout << "NG" << endl;
				success = false;
				break;
			}
			if (c >= '0' && c <= '9') sum[0]++;
			else if (c >= 'a' && c <= 'z') sum[1]++;
			else if (c >= 'A' && c <= 'Z') sum[2]++;
			else sum[3]++;
		}

		for (int i = 3; i < line.length(); i++)
		{
			for (int j = 0; j < i; j++)
			{
				string l1 = line.substr(i, 3);
				string l2 = line.substr(j, 3);
				if (l1 == l2)
				{
					cout << "NG" << endl;
					success = false;
					break;
				}
			}
			if (!success) break;
		}

		int zeroCount = 0;
		for (int i = 0; i < 4; i++)
		{
			if (sum[i] == 0) zeroCount++;
		}
		if (zeroCount > 1)
		{
			cout << "NG" << endl;
			continue;
		}

		if (success) cout << "OK" << endl;
	}
	return 0;
}