#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

vector<string> arr;

int main()
{
	string l;
	while (cin >> l)
	{
		arr.emplace_back(l);
	}
	reverse(arr.begin(), arr.end());
	cout << arr[0];
	for (int i = 1; i < arr.size(); i++)
	{
		cout << ' ' << arr[i];
	}
	return 0;
}