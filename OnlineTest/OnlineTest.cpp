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