#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>
using namespace std;


int main()
{
	int n;
	while (cin >> n)
	{
		vector<pair<string, string>> dic;
		string l, sl;
		for (int i = 0; i < n; i++)
		{
			cin >> l;
			sl = l;
			sort(sl.begin(), sl.end());
			dic.emplace_back(pair<string, string>(l, sl));
		}
		sort(dic.begin(), dic.end(),
			[](pair<string, string>& a, pair<string, string>& b)
		{
			return a.first < b.first;
		});
		cin >> l >> n;
		sl = l;
		sort(sl.begin(), sl.end());
		int sum = 0;
		string result;
		for (int i = 0; i < dic.size(); i++)
		{
			if (sl == dic[i].second && l != dic[i].first)
			{
				sum++;
				n--;
				if (n == 0) result = dic[i].first;
			}
		}
		cout << sum << endl;
		//for (auto& i : result)
		//{
		//	cout << ' ' << result;
		//}
		if (result != "") cout << result << endl;
	}
	return 0;
}