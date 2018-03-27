#include<iostream>
#include<algorithm>
using namespace std;

int n;
int tx[55], ty[55];
int gx, gy;
int walkTime, taxiTime;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tx[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> ty[i];
	}
	cin >> gx >> gy;
	cin >> walkTime >> taxiTime;
	int walk = walkTime * (abs(gx) + abs(gy));
	int taxi = 0x3f3f3f3f;
	for (int i = 0; i < n; i++)
	{
		taxi = min(taxi, walkTime * (abs(tx[i]) + abs(ty[i])) + taxiTime * (abs(gx - tx[i]) + abs(gy - ty[i])));
	}
	cout << min(walk, taxi) << endl;
	return 0;
}