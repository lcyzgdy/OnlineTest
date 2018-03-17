class Solution {
public:
	int LastRemaining_Solution(int n, int m)
	{
		int r = 0;
		if (n == 0 || m == 0) return -1;
		for (int i = 2; i <= n; i++)
		{
			r = (r + m) % i;
		}
		return r + 1;
	}
};