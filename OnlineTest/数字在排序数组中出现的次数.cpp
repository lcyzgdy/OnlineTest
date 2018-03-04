#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int GetNumberOfK(vector<int> data, int k) {
		//int sum = 0;
		return count(data.begin(), data.end(), k);
		
		/*for (int i : data)
		{
			if (i == k) sum++;
			if (i > k) break;
		}
		return sum;*/
	}
};