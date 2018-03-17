#include<iostream>
using namespace std;

class Solution {
	static int m;
public:
	int Sum_Solution(int n) {
		int r = 0;
		n && (r = n + Sum_Solution(n - 1));
		return r;
	}
};

int main()
{
	Solution a;
	cout << a.Sum_Solution(10);
	return 0;
}