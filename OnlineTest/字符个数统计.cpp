/*��Ŀ����
��дһ�������������ַ����к��еĲ�ͬ�ַ��ĸ������ַ���ACSII�뷶Χ��(0~127)�����ڷ�Χ�ڵĲ���ͳ�ơ�
��������:
����N���ַ����ַ���ACSII�뷶Χ�ڡ�
�������:
�����Χ��(0~127)�ַ��ĸ�����
ʾ��1
����
abc
���
3
*/

#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int main()
{
	bool y[128];
	string l;
	memset(y, 0, sizeof(y));
	cin >> l;
	for (char c : l)
	{
		y[(int)c]++;
	}
	int sum = 0;
	for (int i = 0; i < 128; i++)
	{
		sum += y[i];
	}
	cout << sum;
	return 0;
}