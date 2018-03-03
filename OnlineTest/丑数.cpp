#include<queue>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
	int GetUglyNumber_Solution(int index) {
		if (index < 7) return index;
		vector<int> v(index);
		v[0] = 1;
		int t2 = 0, t3 = 0, t5 = 0;
		for (int i = 1; i < index; i++)
		{
			v[i] = min({ v[t2] * 2, v[t3] * 3, v[t5] * 5 });
			if (v[i] == v[t2] * 2) t2++;
			if (v[i] == v[t3] * 3) t3++;
			if (v[i] == v[t5] * 5) t5++;
		}
		return v[index - 1];
	}
};

int main()
{
	Solution a;
	cout << a.GetUglyNumber_Solution(1000000);
	return 0;
}