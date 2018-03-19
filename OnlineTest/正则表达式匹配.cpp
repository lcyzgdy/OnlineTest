/* 请实现一个函数用来匹配包括'.'和'*'的正则表达式。
 * 模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（包含0次）。
 * 在本题中，匹配是指字符串的所有字符匹配整个模式。
 * 例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配
 */

class Solution {
public:
	bool match(char* str, char* pattern)
	{
		char last = '\0';
		char* pp = pattern;
		if (*str == '\0')
		{
			if (*pp == '\0') return true;
			if (*(pp + 1) == '*') return true;
		}
		if (*pp == '\0') return false;
		while (*str != '\0')
		{
			if (*str == *pp)
			{
				last = *str;
				pp++;
				str++;
			}
			else if (*pp == '.')
			{
				str++;
				pp++;
			}
			else if (*pp == '*')
			{
				while (*str == last) str++;
				pp++;
			}
			else
			{
				if (pp[1] == '*')
				{
					last = *pp;
					pp++;
				}
				else
				{
					pp = pattern;
					str++;
				}
			}
		}
		if (*pp == '\0') return true;
		if (*pp == '*' || *(pp + 1) == '*' && *(pp + 2) == '\0') return true;
		return false;
	}
};
#include<iostream>
using namespace std;

int main()
{
	Solution a;
	char aa[] = "aaa";
	char bb[] = "a*a";
	cout << a.match(aa, bb) << endl;
	return 0;
}