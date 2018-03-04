#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> FindContinuousSequence(int sum) {
		vector<vector<int>> res;
		for (int i = 1; i <= sum / 2 + 1; i++)
		{
			vector<int> q;
			int s = 0;
			for (int j = i; j <= sum / 2 + 1; j++)
			{
				q.push_back(j);
				s += j;
				if (s == sum && q.size() > 1)
				{
					res.emplace_back(q);
					break;
				}
				if (s > sum) break;
			}
		}
		return res;
	}
};