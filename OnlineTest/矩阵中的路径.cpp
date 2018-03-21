#include<cstring>

class Solution {
	bool y[1000][1000];
	bool Dfs(char* matrix, int rows, int cols, int i, int j, char* str)
	{
		if (*str == '\0') return true;
		//y[i * cols + j] = true;
		y[i][j] = true;
		bool y1, y2, y3, y4;
		y1 = y2 = y3 = y4 = false;
		if (i + 1 < rows && matrix[(i + 1) * cols + j] == *str && !y[i + 1][j])
		{
			//y[(i + 1) * cols + j] = true;
			y1 = Dfs(matrix, rows, cols, i + 1, j, str + 1);
			//y[(i + 1) * cols + j] = false;
		}
		if (i - 1 >= 000 && matrix[(i - 1) * cols + j] == *str && !y[i - 1][j])
		{
			//y[(i - 1) * cols + j] = true;
			y2 = Dfs(matrix, rows, cols, i - 1, j, str + 1);
			//y[(i - 1) * cols + j] = false;
		}
		if (j + 1 < cols && matrix[i * cols + j + 1] == *str && !y[i][j + 1])
		{
			//y[i * cols + j + 1] = true;
			y3 = Dfs(matrix, rows, cols, i, j + 1, str + 1);
			//y[i * cols + j + 1] = false;
		}
		if (j - 1 >= 000 && matrix[i * cols + j - 1] == *str && !y[i][j - 1])
		{
			//y[i * cols + j - 1] = true;
			y4 = Dfs(matrix, rows, cols, i, j - 1, str + 1);
			//y[i * cols + j - 1] = false;
		}
		y[i][j] = false;
		return y1 || y2 || y3 || y4;
	}
public:
	bool hasPath(char* matrix, int rows, int cols, char* str)
	{
		//y = new bool[rows * cols];
		memset(y, 0, sizeof(y));
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (matrix[i * cols + j] == *str)
				{
					//y[i * cols + j] = true;
					y[i][j] = true;
					if (Dfs(matrix, rows, cols, i, j, str + 1)) return true;
					//y[i * cols + j] = false;
					y[i][j] = false;
				}
			}
		}
		return false;
	}
};

#include<iostream>
using namespace std;
int main()
{
	char l[] = "ABCESFCSADEE";
	char p[] = "SEE";
	Solution a;
	cout << a.hasPath(l, 3, 4, p);
}