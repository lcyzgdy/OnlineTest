#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> printMatrix(vector<vector<int> > matrix) {
		vector<int> result;
		int direction = 0;
		int x = 0, y = 0;
		int r = matrix.size();
		if (r == 0) return result;
		int c = matrix[0].size();
		if (c == 0) return result;
		int sum = r * c;
		while (sum--)
		{
			int tx = x, ty = y;
			result.push_back(matrix[x][y]);
			switch (direction)
			{
			case 0:
			{
				y++;
				if (y >= c || matrix[x][y] == -2147483647)
				{
					direction = 1;
					y--;
					x++;
				}
				break;
			}
			case 1:
			{
				x++;
				if (x >= r || matrix[x][y] == -2147483647)
				{
					direction = 2;
					x--;
					y--;
				}
				break;
			}
			case 2:
			{
				y--;
				if (y < 0 || matrix[x][y] == -2147483647)
				{
					direction = 3;
					y++;
					x--;
				}
				break;
			}
			case 3:
			{
				x--;
				if (x < 0 || matrix[x][y] == -2147483647)
				{
					direction = 0;
					x++;
					y++;
				}
			}
			default:
				break;
			}
			matrix[tx][ty] = -2147483647;
		}
		return result;
	}
};