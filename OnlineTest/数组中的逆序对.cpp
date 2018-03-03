#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
	struct Node
	{
		int data;
		int pos;
	} m_d[200000 + 1];

	int m_inverse[200000 + 1];
	int m_ccount[200000 + 1];
	int m_N;

	int Lowbit(int t)
	{
		return t & (t ^ (t - 1));
	}

	void Modify(int pos, int num)
	{
		while (pos <= m_N) {
			m_inverse[pos] += num % 1000000007;
			m_inverse[pos] %= 1000000007;
			pos += Lowbit(pos);
		}
	}

	int Sum(int end)
	{
		int sum = 0;
		while (end > 0) {
			sum = ((sum % 1000000007) + (m_inverse[end] % 1000000007)) % 1000000007;
			end -= Lowbit(end);
		}
		return sum;
	}

public:
	int InversePairs(vector<int> data) {
		m_N = data.size();

		memset(m_inverse, 0, sizeof(m_inverse)); //初始化
		memset(m_ccount, 0, sizeof(m_ccount));
		for (int i = 0; i < data.size(); i++)
		{
			m_d[i].data = data[i];
			m_d[i].pos = i;
		}//离散化

		sort(m_d, m_d + data.size(), [](const Node& a, const Node& b) { return a.data - b.data; });

		int id = 0;
		m_ccount[m_d[0].pos] = 1;
		for (int i = 1; i < m_N; i++)
		{
			if (m_d[i].data == m_d[i - 1].data) m_ccount[m_d[i].pos] = id;
			else m_ccount[m_d[i].pos] = ++id;
		}

		/*找小到大顺序的逆序对时，先插入最大的*/
		int num = 0;
		for (int i = 0; i < m_N; i++)
		{
			Modify(m_ccount[i], 1);
			num += i - Sum(m_ccount[i]);
		}//用树状数组求和而不是线性的统计
		 /*如果为Sum(m_ccount[i])，则为顺序*/
		return num;
	}
};

int main()
{
	cout << sizeof(Solution);
	//a.InversePairs({ 1, 2, 3, 4, 5, 6, 7, 8, 9 });
}