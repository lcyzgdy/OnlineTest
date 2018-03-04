#include<vector>
using namespace std;

class Solution {
public:
	void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
		int t = data[0];
		for (int i = 1; i < data.size(); i++)
		{
			t ^= data[i];
		}
		int index = 0;
		for (int i = 0; i < 32; i++)
		{
			if (t & (1 << i))
			{
				index = i;
				break;
			}
		}
		index = (1 << index);
		vector<int> tmp1;
		vector<int> tmp2;
		for (int i : data)
		{
			if (i & index) tmp1.push_back(i);
			else tmp2.push_back(i);
		}
		t = tmp1[0];
		for (int i = 1; i < tmp1.size(); i++)
		{
			t ^= tmp1[i];
		}
		*num2 = t;
		t = tmp2[0];
		for (int i = 1; i < tmp2.size(); i++)
		{
			t ^= tmp2[i];
		}
		*num1 = t;
	}
};
#include<iostream>
int main()
{
	int a, b;
	Solution c;
	c.FindNumsAppearOnce({ 2,4,3,6,3,2,5,5 }, &a, &b);
	cout << a << ' ' << b << endl;
}