#include<iostream>
#include<bitset>
using namespace std;

class Solution {
public:
	int  NumberOf1(int n) {
		unsigned a = n;
		int sum = 0;
		while (a)
		{
			if (a & 1)  sum++;
			a >>= 1;
		}
		return sum;
	}
};

int main()
{
	Solution a;
	cout << a.NumberOf1(-8) << endl;
	return 0;
}