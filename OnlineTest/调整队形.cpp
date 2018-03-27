#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

class TreeArray
{
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
			m_inverse[i] = num + m_inverse[i];
		}
	}

	int Sum(int end)
	{
		int h = 0;
		for (int i = end; i > 0; i -= Lowbit(i))
		{
			h += m_inverse[i];
		}
		return h;
	}

public:
	int InversePairs(vector<int>& data)
	{
		m_N = data.size() + 1;
		m_ccount.resize(m_N);
		m_inverse.resize(m_N);
		m_d.resize(m_N);
		m_N--;

		for (int i = 1; i <= data.size(); i++)
		{
			Node* a = new Node();
			a->data = data[i - 1];
			a->pos = i;
			m_d[i] = a;
		}

		sort(++m_d.begin(), m_d.end(), [](Node* a, Node* b) { return a->data < b->data; });

		int id = 1;
		m_ccount[m_d[1]->pos] = 1;
		for (int i = 2; i <= m_N; i++)
		{
			if (m_d[i]->data == m_d[i - 1]->data) m_ccount[m_d[i]->pos] = id;
			else m_ccount[m_d[i]->pos] = ++id;
		}

		int num = 0;
		for (int i = 1; i <= m_N; i++)
		{
			Modify(m_ccount[i], 1);
			num = ((i - Sum(m_ccount[i])) % 1000000007 + num) % 1000000007;
		}
		return num;
	}
};

int main()
{
	TreeArray a,b;
	string l;
	cin >> l;
	vector<int> v1, v2;
	for (char c : l)
	{
		v1.push_back(c == 'G' ? 1 : 2);
		v2.push_back(c == 'B' ? 1 : 2);
	}
	cout << min(a.InversePairs(v1), b.InversePairs(v2)) << endl;
}