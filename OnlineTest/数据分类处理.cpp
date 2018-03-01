#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<sstream>
using namespace std;

int n, m;
unsigned int I[5001];
unsigned int R[5001];

unsigned int tenStep(long long num)
{
	//if (num == 0L) return 10;
	unsigned int s[10] = { 1000000000,100000000,10000000,1000000,100000,10000,1000,100,10,0 };
	for (int i = 0; i < 11; i++)
	{
		if (s[i] <= num)
		{
			return s[i - 1];
		}
	}
	return 10;
}

int main()
{
	while (cin >> n)
	{
		stringstream temp;
		for (int i = 0; i < n; i++)
		{
			cin >> I[i];
		}
		cin >> m;
		for (int i = 0; i < m; i++)
		{
			cin >> R[i];
		}

		//int iiii = tenStep(0);

		sort(R, R + m);
		int numberCount = 0;
		for (int t = 0; t < m; t++)
		{
			int k = R[t];
			if (t > 0 && k == R[t - 1]) continue;
			int result = 0;
			stringstream ss;
			for (int i = 0; i < n; i++)
			{
				int u = I[i];
				if (u == k)
				{
					ss << i << ' ' << I[i] << ' ';
					result++;
					numberCount += 2;
				}
				else while (u > 0)
				{
					if (u % tenStep(k) == k)
					{
						ss << i << ' ' << I[i] << ' ';
						result++;
						numberCount += 2;
						break;
					}
					u /= 10;
				}
			}
			if (result > 0)
			{
				numberCount += 2;
				temp << k << ' ' << result << ' ' << ss.str();
			}
		}
		cout << numberCount << ' ' << temp.str().substr(0, temp.str().find_last_of(' ')) << endl;;
	}
	return 0;
}