#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#include<bitset>
using namespace std;

int main()
{
	string l;
	cin >> l;
	unsigned int ip = 0;
	int temp = 0;
	for (int i = 0; i < l.length(); i++)
	{
		if (l[i] == '.')
		{
			ip = (ip << 8) | temp;
			temp = 0;
			continue;
		}
		temp = temp * 10 + (l[i] - '0');
	}
	ip = (ip << 8) | temp;
	cout << ip << endl;

	unsigned int n;
	cin >> n;
	bitset<32> b(n);

	bitset<8> ipb0(b.to_string().substr(0, 8));
	bitset<8> ipb1(b.to_string().substr(8, 8));
	bitset<8> ipb2(b.to_string().substr(16, 8));
	bitset<8> ipb3(b.to_string().substr(24, 8));

	cout << ipb0.to_ulong() << '.' << ipb1.to_ulong() << '.' << ipb2.to_ulong() << '.' << ipb3.to_ulong() << endl;
	return 0;
}