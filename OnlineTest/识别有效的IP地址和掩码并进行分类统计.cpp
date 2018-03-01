#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
using namespace std;

string line;

bool CheckMask(const string& mask)
{

	int temp = 0;
	unsigned int bit = 0;
	for (char c : mask)
	{
		if (c == '.')
		{
			//cout << temp << ' ';
			bit = (bit << 8) + temp;
			temp = 0;
			continue;
		}
		temp = temp * 10 + (c - '0');
	}
	//cout << temp << ' ';
	bit = (bit << 8) + temp;
	//cout << bit << endl;
	temp = 0;
	if (bit == 0xffffffff) return true;
	while (bit)
	{
		if (temp == 0 && (bit & 1) == 1) { temp = 1; }
		else if ((bit & 1) == 0 && temp == 1)
		{
			return true;
		}
		bit >>= 1;
	}
	return false;
}

bool CheckIp(const string& ip)
{
	for (int i = 0; i < ip.length(); i++)
	{
		if (ip[i] == '.')
		{
			if (i == ip.length() - 1) return true;
			if (ip[i + 1] < '0' || ip[i + 1] > '9') return true;
		}
	}
	return false;
}

int main()
{
	int A, B, C, D, E, errorIpOrMask, privateIp;
	A = B = C = D = E = errorIpOrMask = privateIp = 0;
	while (cin >> line)
	{
		if (line == "END")  break;
		string ip = line.substr(0, line.find('~'));
		string mask = line.substr(line.find('~') + 1);

		if (CheckIp(ip) || CheckMask(mask))
		{
			errorIpOrMask++;
			continue;
		}

		int first = 0, second = 0;
		for (char c : ip)
		{
			if (c == '.') break;
			first = first * 10 + (c - '0');
		}
		for (int i = ip.find_first_of('.') + 1; i < ip.length(); i++)
		{
			if (ip[i] == '.') break;
			second = second * 10 + (ip[i] - '0');
		}

		if (first == 10 || (first == 172 && (second >= 16 && second <= 31)) || (first == 192 && second == 168))
		{
			privateIp++;
		}
		if (first > 0 && first < 127)
		{
			A++;
		}
		else if (first >= 128 && first <= 191)
		{
			B++;
		}
		else if (first >= 192 && first <= 223)
		{
			C++;
		}
		else if (first >= 224 && first <= 239)
		{
			D++;
		}
		else if (first >= 240 && first <= 255)
		{
			E++;
		}
	}
	cout << A << ' ' << B << ' ' << C << ' ' << D << ' ' << E << ' ' << errorIpOrMask << ' ' << privateIp << endl;
	return 0;
}