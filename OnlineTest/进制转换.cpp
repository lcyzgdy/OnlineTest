/* ��Ŀ����
	д��һ�����򣬽���һ��ʮ�����Ƶ���ֵ�ַ������������ֵ��ʮ�����ַ�����������ͬʱ���� ��
   ��������:
	����һ��ʮ�����Ƶ���ֵ�ַ�����
   �������:
	�������ֵ��ʮ�����ַ�����
   ʾ��1
   ����
	0xA
   ���
	10
*/

#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
	string l;
	while (cin >> l)
	{
		bool negitive = false;
		int firstInt = 2;
		int result = 0;
		if (l[0] == '-')
		{
			negitive = true;
			firstInt = 3;
		}
		for (int i = firstInt; i < l.length(); i++)
		{
			if (l[i] <= '9' && l[i] >= '0')
			{
				int a = l[i] - '0';
				result = result * 16 + a;
			}
			else
			{
				int a = l[i] - 'A' + 10;
				result = result * 16 + a;
			}
		}
		cout << result << endl;
	}
	return 0;
}