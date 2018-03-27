#include<iostream>
#include<algorithm>
using namespace std;

int height[55];

int main()
{
	int n;
	cin >> n;
	int sum = 0, ave;
	for (int i = 0; i < n; i++)
	{
		cin >> height[i];
		sum += height[i];
	}
	ave = sum / 2;
	if (ave * 2 != sum)
	{
		cout << -1 << endl;
		return 0;
	}
	sort(height, height + n);
	int l = 0, r = 0;
	int len = height[l];
	while (len != ave)
	{
		if (len < ave)
		{
			r++;
			len += height[r];
		}
		else if (len > ave)
		{
			len -= height[l];
			l++;
		}
		if (r >= n || l > r) break;
	}
	if (len == ave) cout << ave;
	else cout << -1;
	return 0;
}