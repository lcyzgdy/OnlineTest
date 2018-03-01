#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	void reOrderArray(vector<int> &array) {
		vector<int> odd, even;
		for (int i : array)
		{
			if (i & 1) odd.push_back(i);
			else even.push_back(i);
		}
		int p = 0;
		for (int i : odd)
		{
			array[p] = i;
			p++;
		}
		for (int i : even)
		{
			array[p] = i;
			p++;
		}
	}
};

int main()
{
	return 0;
}