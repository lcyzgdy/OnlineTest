#include"TemplateTest.h"
#include<iostream>
using namespace std;

int main()
{
	Test<int> a;
	cout << a.Add(2) << endl;
	return 0;
}