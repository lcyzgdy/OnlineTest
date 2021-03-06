#include<iostream>
using namespace std;

int i = 0;

class A
{
public:
	A()
	{
		cout << i++ << endl;
	}
};

static A a;

int main()
{
	static A c;
}

/*
 * f[i][v]=max{f[i-1][v],f[i-1][v-c[i]]+w[i]}。 
 *
 * for i=1..N
 *  for v=V..0
 *   f[v]=max{f[v],f[v-c[i]]+w[i]}; 
 *
 *  for i=1..N for v=0..V f[v]=max{f[v],f[v-c[i]]+w[i]};
 *
 * f[i][v]=max{f[i-1][v-k*c[i]]+ k*w[i]|0<=k<=n[i]}。

 * for i=1..N 
 *  if 第 i 件物品是 01 背包 
 *   for v=V..0 f[v]=max{f[v],f[v-c[i]]+w[i]}; 
 *  else if 第 i 件物品是完全背包 
 *   for v=0..V f[v]=max{f[v],f[v-c[i]]+w[i]};
 */