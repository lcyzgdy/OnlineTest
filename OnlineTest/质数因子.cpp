/*��Ŀ����
����:����һ�������������մ�С�����˳����������������������ӣ���180����������Ϊ2 2 3 3 5 ��
���һ��������ҲҪ�пո�

��ϸ������

�����ӿ�˵����
public String getResult(long ulDataInput)
���������
long ulDataInput�������������
����ֵ��
String


��������:
����һ��long������
�������:
���մ�С�����˳����������������������ӣ��Կո���������һ��������ҲҪ�пո�
ʾ��1
����
180
���
2 2 3 3 5*/

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	long long t;
	cin >> t;
	while ((t & 1L) == 0L)
	{
		cout << 2 << ' ';
		t >>= 1;
	}
	for (int i = 3; i <= t; i += 2)
	{
		while (t % i == 0)
		{
			cout << i << ' ';
			t /= i;
		}
	}
	return 0;
}