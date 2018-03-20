#include<iostream>
#include<vector>
#include"SegmentTree.cpp"
using namespace std;

class Solution {
public:
	vector<int> maxInWindows(const vector<int>& num, unsigned int size)
	{
		vector<int> r;
		ZkwSegmentTree<int> st;
		st.Build(num);
		return r;
	}
};

int main()
{
	Solution a;
	a.maxInWindows({ 2,3,4,2,6,2,5,1 }, 3);
}