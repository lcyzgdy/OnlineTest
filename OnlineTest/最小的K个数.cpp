#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		sort(input.begin(), input.end());
		vector<int> res;
		if (k > input.size()) return res;
		for (int i = 0; i < k; i++) res.push_back(input[i]);
		return res;
	}
};