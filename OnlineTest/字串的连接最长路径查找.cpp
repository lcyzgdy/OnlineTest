#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

string arr[1010];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << endl;
	}
	return 0;
}