/*��Ŀ����
����һ��int�����������մ���������Ķ�˳�򣬷���һ�������ظ����ֵ��µ�������
��������:
����һ��int������
�������:
���մ���������Ķ�˳�򣬷���һ�������ظ����ֵ��µ�����
ʾ��1
����
9876673
���
37689
*/

#include<iostream>
#include<string>
#include<cstring>
using namespace std;

string l;
bool b[11];

int main()
{
	memset(b, 0, sizeof(b));
	cin >> l;
	for (int i = l.length() - 1; i >= 0; i--)
	{
		if (!b[l[i] - '0'])
		{
			cout << l[i];
			b[l[i] - '0'] = true;
		}
	}
	return 0;
}