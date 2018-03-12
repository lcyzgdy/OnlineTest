#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	bool IsContinuous(vector<int> numbers) {
		if (numbers.size() == 0) return false;
		sort(numbers.begin(), numbers.end());
		int zero = 0;
		int ii = 0;
		for (; ii < numbers.size(); ii++)
		{
			if (numbers[ii] != 0)
			{
				break;
			}
		}
		for (int i = ii + 1; i < numbers.size(); i++)
		{
			if (numbers[i] - numbers[i - 1] != 1)
			{
				int c = numbers[i] - numbers[i - 1];
				if (c == 0) return false;
				ii -= c - 1;
				if (ii >= 0) continue;
				return false;
			}
		}
		return true;
	}
};

#include<iostream>

int main()
{
	Solution a;
	cout << a.IsContinuous({ 1,3,2,6,4 }) << endl;
	return 0;
}