#include<iostream>
#include<algorithm>
using namespace std;

struct Point
{
	int x, y;
} p[55];

int Manhadun(Point& a, Point b)
{
	return abs(a.x - b.x) + abs(a.y - b.y);
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> p[i].x >> p[i].y;
	}
	sort(p, p + n, [](Point& a, Point& b) {if (a.x == b.x)return a.y < b.y; return a.x < b.x; });

}