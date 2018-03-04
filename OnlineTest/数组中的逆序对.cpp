#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
	struct Node
	{
		int data;
		int pos;
	};
	vector<Node*> m_d;

	vector<int> m_inverse;
	vector<int> m_ccount;
	int m_N;

	int Lowbit(int t)
	{
		return t & (-t);
	}

	void Modify(int pos, int num)
	{
		for (int i = pos; i <= m_N; i += Lowbit(i))
		{
			m_inverse[i] = ((num % 1000000007) + m_inverse[i]) % 1000000007;
		}
	}

	int Sum(int end)
	{
		int h = 0;
		for (int i = end; i > 0; i -= Lowbit(i))
		{
			h = (m_inverse[i] % 1000000007 + h) % 1000000007;
		}
		return h;
	}

public:
	int InversePairs(vector<int> data) {
		m_N = data.size() + 1;
		m_ccount.resize(m_N);
		m_inverse.resize(m_N);
		m_d.resize(m_N);
		m_N--;

		//memset(m_inverse, 0, sizeof(m_inverse)); //初始化
		//memset(m_ccount, 0, sizeof(m_ccount));
		for (int i = 1; i <= data.size(); i++)
		{
			Node* a = new Node();
			a->data = data[i - 1];
			a->pos = i;
			m_d[i] = a;
			//m_d[i].data = data[i];
			//m_d[i].pos = i;
		}//离散化

		//sort(m_d, m_d + data.size(), [](const Node& a, const Node& b) { return a.data - b.data; });
		sort(++m_d.begin(), m_d.end(), [](Node* a, Node* b) { return a->data < b->data; });

		int id = 1;
		m_ccount[m_d[1]->pos] = 1;
		for (int i = 2; i <= m_N; i++)
		{
			if (m_d[i]->data == m_d[i - 1]->data) m_ccount[m_d[i]->pos] = id;
			else m_ccount[m_d[i]->pos] = ++id;
		}

		/*找小到大顺序的逆序对时，先插入最大的*/
		int num = 0;
		for (int i = 1; i <= m_N; i++)
		{
			Modify(m_ccount[i], 1);
			num = ((i - Sum(m_ccount[i])) % 1000000007 + num) % 1000000007;
		}//用树状数组求和而不是线性的统计
		 /*如果为Sum(m_ccount[i])，则为顺序*/
		return num;
	}
};

int main()
{
	//cout << sizeof(Solution);
	Solution a;
	cout << a.InversePairs({ 1,2,3,4,5,6,7,0 }) << endl;
}