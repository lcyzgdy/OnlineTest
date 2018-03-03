#include<iostream>
using namespace std;

class Solution {
public:
	int NumberOf1Between1AndN_Solution(int n)
	{
		if (n < 1) return 0;
		int sum, base, round;
		sum = 0;
		base = 1;
		round = n;
		while (round)
		{
			int weight = round % 10;
			round /= 10;
			sum += round * base;
			if (weight == 1)
			{
				sum += (n % base) + 1;
			}
			else if (weight > 1)
			{
				sum += base;
			}
			base *= 10;
		}
		return sum;
	}
};