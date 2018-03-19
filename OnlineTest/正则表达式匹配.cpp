/* ��ʵ��һ����������ƥ�����'.'��'*'��������ʽ��
 * ģʽ�е��ַ�'.'��ʾ����һ���ַ�����'*'��ʾ��ǰ����ַ����Գ�������Σ�����0�Σ���
 * �ڱ����У�ƥ����ָ�ַ����������ַ�ƥ������ģʽ��
 * ���磬�ַ���"aaa"��ģʽ"a.a"��"ab*ac*a"ƥ�䣬������"aa.a"��"ab*a"����ƥ��
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