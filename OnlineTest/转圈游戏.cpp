#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
long long n, m, k, x;

long long FastPower(long long x, long long y)
{
	if (y == 0) return 1LL;
	if (y == 1) return x % n;
	long long c = FastPower(x, y >> 1) % n;
	return (((c*c) % n) * FastPower(x, y & 1) % n) % n;
}

int main()
{
	cin >> n >> m >> k >> x;
	cout << (x % n + m % n * FastPower(10, k) % n) % n;
	return 0;
}