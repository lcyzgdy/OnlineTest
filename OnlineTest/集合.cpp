#include<iostream>
#include<set>
using namespace std;

int main()
{
	int w, x, y, z;
	set<float> s;
	cin >> w >> x >> y >> z;
	for (int i = w; i <= x; i++)
	{
		for (int j = y; j <= z; j++)
		{
			s.insert((float)i / (float)j);
		}
	}
	cout << s.size() << endl;
	return 0;
}