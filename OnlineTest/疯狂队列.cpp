#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;

deque<int> q;

int main()
{
	int n;
	int s[55];
	cin >> n;
	for (int i = 0; i < n; i++) cin >> s[i];
	sort(s, s + n);
	q.push_back(s[0]);
	int l = 1, r = n - 1;
	while (l <= r)
	{
		if (abs(q.front() - s[r]) < abs(q.back() - s[r]))
		{
			q.push_back(s[r]);+
		}
		else
		{
			q.push_front(s[r]);
		}
		r--;
		if (l > r) break;
		if (abs(q.front() - s[l]) < abs(q.back() - s[l]))
		{
			q.push_back(s[l]);
		}
		else
		{
			q.push_front(s[l]);
		}
		l++;
	}
	int sum = 0;
	for (int i = 1; i < q.size(); i++)
	{
		sum += abs(q[i] - q[i - 1]);
	}
	cout << sum << endl;
	return 0;
}