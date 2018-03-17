#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	int StrToInt(string str) {
		if (str.length() == 0) return 0;
		long long r = 0ll;
		int sign = 1;
		for (int i = 0; i < str.length(); i++)
		{
			if (i == 0)
			{
				if (str[i] != '+' && str[i] != '-' && str[i] <'0' && str[i] >'9') break;
				if (str[i] == '+') sign = 1;
				else if (str[i] == '-') sign = -1;
				else r = str[i] - '0';
			}
			else
			{
				if (str[i] < '0' || str[i] > '9') return 0;
				r = r * 10ll + (str[i] - '0');
			}
		}
		return r * sign;
	}
};

int main()
{
	Solution a;
	cout << a.StrToInt("-2147483647");
	return 0;
}