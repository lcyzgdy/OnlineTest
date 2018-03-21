#include<queue>
#include<map>
using namespace std;

class Solution {
	queue<pair<int, int>> q;
	bool his[10000];

	int BitSum(int x, int y)
	{
		int r = 0;
		while (x)
		{
			r += x % 10;
			x /= 10;
		}
		while (y)
		{
			r += y % 10;
			y /= 10;
		}
		return r;
	}
public:
	int movingCount(int threshold, int rows, int cols)
	{
		memset(his, 0, sizeof(his));
		his[0] = true;
		int count = 0 <= threshold ? 1 : 0;
		q.push({ 0, 0 });
		while (!q.empty())
		{
			auto[x, y] = q.front();
			q.pop();
			if (x + 1 < rows && !his[cols * (x + 1) + y] && BitSum(x + 1, y) <= threshold)
			{
				his[cols * (x + 1) + y] = true;
				q.push({ x + 1,y });
				count++;
			}
			if (x - 1 >= 0 && !his[cols * (x - 1) + y] && BitSum(x - 1, y) <= threshold)
			{
				his[cols * (x - 1) + y] = true;
				q.push({ x - 1, y });
				count++;
			}
			if (y + 1 < cols && !his[cols * x + y + 1] && BitSum(x, y + 1) <= threshold)
			{
				his[cols * x + y + 1] = true;
				q.push({ x, y + 1 });
				count++;
			}
			if (y - 1 >= 0 && !his[cols * x + y - 1] && BitSum(x, y - 1) <= threshold)
			{
				his[cols * x + y - 1] = true;
				q.push({ x, y - 1 });
				count++;
			}
		}
		return count;
	}
};