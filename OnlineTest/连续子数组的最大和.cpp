#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		int start, sum;
		start = sum = array[0];
		for (int i = 1; i < array.size(); i++)
		{
			start = max(start + array[i], array[i]);
			sum = max(start, sum);
		}
		return sum;
	}
};