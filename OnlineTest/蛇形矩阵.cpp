#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int stepX = 2;
	int stepY = 1;
	int value = 1;
	for (int i = 0; i < n; i++)
	{
		int temp = value;
		int temp1 = stepX;
		bool spaceFlag = false;
		for (int j = n - i; j > 0; j--)
		{
			if (!spaceFlag)
			{
				cout << value;
				spaceFlag = true;
			}
			else
			{
				cout << ' ' << value;
			}
			value += stepX;
			stepX++;
		}
		cout << endl;
		value = temp + stepY;
		stepX = ++temp1;
		stepY++;
	}

	return 0;
}