#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int HP, AP, HM, AM, b, d;
int minn = 0x3f3f3f3f;

void Dfs(int hp, int ap, int hm, int am, int step)
{
	if (step >= minn) return;
	if (step + hm / (ap + 1) >= minn) return;
	if (hm <= 0)
	{
		minn = min(minn, step);
		return;
	}
	if (ap <= 0 && b <= 0)
	{
		return;
	}

	if (am < 0) am = 0;


	if (ap <= HM && b > 0 && hp - am > 0)
	{
		Dfs(hp - am, ap + b, hm, am, step + 1);
	}// Xiulian

	if ((hp - am > 0 || hm - ap <= 0) && ap > 0)
	{
		Dfs(hp - am, ap, hm - ap, am, step + 1);
	}// Gongji

	if (am > 0 && d > 0)
	{
		if (hp - am + d > 0)
		{
			Dfs(hp - am + d, ap, hm, am - d, step + 1);
		}
	}// Xueruo

	if (HP - am > 0 && HP - am > hp)
	{
		Dfs(HP - am, ap, hm, am, step + 1);
	}// Huixue
}

int main()
{
	cin >> HP >> AP >> HM >> AM >> b >> d;
	Dfs(HP, AP, HM, AM, 0);
	if (minn == 0x3f3f3f3f) cout << "IMPOSSIBLE";
	else cout << minn;
	return 0;
}