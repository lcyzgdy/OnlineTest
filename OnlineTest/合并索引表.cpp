/*��Ŀ����
���ݱ��¼��������������ֵ����Ա�������ͬ�ļ�¼���кϲ���������ͬ��������ֵ����������㣬�������keyֵ������������
��������:
�������ֵ�Եĸ���
Ȼ������ɶԵ�index��valueֵ���Կո����
�������:
����ϲ���ļ�ֵ�ԣ����У�
ʾ��1
����
4
0 1
0 2
1 2
3 4
���
0 3
1 2
3 4
*/

#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

map<int, int> index;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		index[a] += b;
	}
	for (auto i : index)
	{
		cout << i.first << ' ' << i.second << endl;
	}
	return 0;
}