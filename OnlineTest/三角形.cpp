#include<iostream>
using namespace std;

int main()
{
	int h;
	cin >> h;
	for (int i = 0; i < h; i++)
	{
		int space = h - i - 1;
		for (int j = 0; j < space; j++) cout << '.';
		cout << '*';
		if (i == 0)
		{
			if (i != h - 1)cout << endl;
			continue;
		}
		if (i != h - 1) for (int j = 0; j < 2 * i - 1; j++) cout << '.';
		else
		{
			for (int j = 0; j < 2 * i - 1; j++) cout << '*';
		}
		cout << '*';
		if (i != h - 1) cout << endl;
	}
	return 0;
}