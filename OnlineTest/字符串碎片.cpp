#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

int main()
{
	string l;
	cin >> l;
	int n = 1;
	for (int i = 1; i < l.length(); i++)
	{
		if (l[i] == l[i - 1]) continue;
		n++;
	}
	printf("%0.2f", (float)l.length() / (float)n);
	return 0;
}