#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
	int num1, num2;
	char op;
	cin >> num1;
	cin >> op;
	while (cin >> num2)
	{
		switch (op)
		{
		case '+':
			num1 = num1 + num2;
			break;
		case '-':
			num1 = num1 - num2;
			break;
		case '*':
			num1 = num1 * num2;
			break;
		default:
			break;
		}
		cin >> op;
	}
	cout << num1 << endl;
	return 0;
}