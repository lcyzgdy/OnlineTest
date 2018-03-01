#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		sort(numbers.begin(), numbers.end());
		int c = 1;
		if (numbers.size() == 1) return numbers[0];
		for (int i = 1; i < numbers.size(); i++)
		{
			if (numbers[i] == numbers[i - 1])
			{
				c++;
				if (c > numbers.size() / 2) return numbers[i];
			}
			else
			{
				c = 1;
			}
		}
		return 0;
		/*multiset<int> ms;
		for (int i : numbers)
		{
			ms.emplace(i);
		}
		for (auto&& i = ms.begin(); i != ms.end(); i++)
		{
			int c = *i;
			if (ms.count(c) > numbers.size() / 2)
			{
				return c;
			}
		}
		return 0;*/
	}
};

int main()
{
	Solution a;
	cout << a.MoreThanHalfNum_Solution({ 1,2,3,2,2,2,5,4,2 }) << endl;
	return 0;
}