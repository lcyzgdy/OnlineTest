#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
	vector<string> Permutation(string str) {
		vector<string> res;
		sort(str.begin(), str.end());
		if (str.length() > 0) res.emplace_back(str);
		while (next_permutation(str.begin(), str.end()))
		{
			res.emplace_back(str);
		}
		return std::move(res);
	}
};

int main()
{
	Solution a;
	for (auto& i : a.Permutation("aabc"))
	{
		cout << i << endl;
	}
	return 0;
}