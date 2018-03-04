#include<vector>
using namespace std;

class Solution {
public:
	vector<int> FindNumbersWithSum(vector<int> array, int sum) {
		int a = 0;
		int b = 0;
		for (int i = 0; i < array.size(); i++)
		{
			for (int j = i + 1; j < array.size(); j++)
			{
				int c = array[i];
				int d = array[j];
				if (c + d > sum) break;
				if (c + d == sum)
				{
					if (a * b == 0 || a * b > c * d)
					{
						a = c;
						b = d;
					}
				}
			}
		}

		vector<int> res;
		if (a * b)
		{
			res.push_back(a);
			res.push_back(b);
		}
		return res;
	}
};

int main()
{
	Solution a;
	a.FindNumbersWithSum({ 1,2,4,7,11,15 }, 15);
}