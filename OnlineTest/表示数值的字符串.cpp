/* 请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
 * 例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。
 * 但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是
 */
#include<algorithm>
#include<string>
using namespace std;

class Solution {
public:
	bool isNumeric(char* string)
	{
		//if (*string == '\0') return false;
		//if (*string == '+' || *string == '-') return stateMachine_sign(string + 1);
		//else if (*string >= '0' && *string <= '9') return stateMachine_int(string + 1);
		try
		{
			stof(string);
			return true;
		}
		catch (exception e)
		{
			return false;
		}
	}

	bool isNumeric_StateMachine(char* string)
	{
		if (*string == '\0') return false;
		if (*string == '+' || *string == '-') return stateMachine_sign(string + 1);
		else if (*string >= '0' && *string <= '9') return stateMachine_int(string + 1);
	}
private:
	bool stateMachine_sign(char* string)
	{
		if (*string >= '0' && *string <= '9') return stateMachine_int(string + 1);
		if (*string == '.') return stateMachine_dot(string + 1);
		return false;
	}

	bool stateMachine_int(char* string)
	{
		while (*string >= '0' && *string <= '9') string++;
		if (*string == '.') return stateMachine_dot(string + 1);
		if (*string == 'e' || *string == 'E') return stateMachine_pow(string + 1);
		if (*string == '\0') return true;
		return false;
	}

	bool stateMachine_dot(char* string)
	{
		//if (*string == '-') return stateMachine_sign(string + 1);
		if (*string >= '0' && *string <= '9') return stateMachine_int3(string + 1);
		return false;
	}

	bool stateMachine_pow(char* string)
	{
		if (*string == '\0') return false;
		if (*string == '+' || *string == '-') return stateMachine_sign2(string + 1);
		else if (*string >= '0' && *string <= '9') return stateMachine_int2(string + 1);
	}

	bool stateMachine_sign2(char* string)
	{
		if (*string >= '0' && *string <= '9') return stateMachine_int2(string + 1);
		return false;
	}

	bool stateMachine_int2(char* string)
	{
		while (*string >= '0' && *string <= '9') string++;
		if (*string == '\0') return true;
		return false;
	}

	bool stateMachine_int3(char* string)
	{
		while (*string >= '0' && *string <= '9') string++;
		if (*string == 'e' || *string == 'E') return stateMachine_pow(string + 1);
		if (*string == '\0') return true;
	}
};
#include<iostream>
#include<chrono>
using namespace std;
int main()
{
	Solution a;
	char aa[] = "-..123";
	chrono::steady_clock::time_point t1 = chrono::steady_clock::now();
	a.isNumeric(aa);
	chrono::steady_clock::time_point t2 = chrono::steady_clock::now();
	a.isNumeric_StateMachine(aa);
	chrono::steady_clock::time_point t3 = chrono::steady_clock::now();

	chrono::duration<double> d1 = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
	chrono::duration<double> d2 = chrono::duration_cast<chrono::duration<double>>(t3 - t2);
	cout << d1.count() << ' ' << d2.count() << endl;
	return 0;
}