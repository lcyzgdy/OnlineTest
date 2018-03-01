#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		return *min_element(rotateArray.begin(), rotateArray.end());

	}
};

int main()
{
	Solution a;
	cout << a.minNumberInRotateArray({ 3,4,5,1,2 }) << endl;
}