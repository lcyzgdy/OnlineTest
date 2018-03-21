#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

template<typename T>
class ZkwSegmentTree
{
	vector<T> m_arr;
	int m_size;
public:
	ZkwSegmentTree() = default;
	ZkwSegmentTree(int size)
	{
		m_arr.reserve(size);
	};

	void Build(const vector<T>& data)
	{
		for (m_size = 1; m_size < data.size() * 2; m_size <<= 1);
		m_arr.resize(m_size);
		for (int i = 0; i < data.size(); i++) m_arr[i + (m_size >> 1)] = data[i];
		for (int i = (m_size >> 1) - 1; i; i--)
			m_arr[i] = max(m_arr[i << 1], m_arr[i << 1 | 1]);
	}

	T Max(int l, int r)
	{
		T maxn;
		if (typeid(T) == typeid(int)) maxn = 0xf3f3f3f3;
		for (l = l + (m_size >> 1) - 1, r = r + (m_size >> 1) + 1; l ^ r ^ 1; l >>= 1, r >>= 1)
		{
			if (~l & 1) maxn = max(maxn, m_arr[l ^ 1]);
			if (r & 1) maxn = max(maxn, m_arr[r ^ 1]);
		}
		return maxn;
	}
};

class Solution {
public:
	vector<int> maxInWindows(const vector<int>& num, unsigned int size)
	{
		vector<int> r;
		if (num.size() == 0) return r;
		if (size > num.size()) return r;
		if (size == 0) return r;
		ZkwSegmentTree<int> st;
		st.Build(num);
		for (int i = 0; i <= num.size() - size; i++)
		{
			r.push_back(st.Max(i, i + size - 1));
		}
		return r;
	}
};

int main()
{
	Solution a;
	auto i = a.maxInWindows({ 2,3,4,2,6,2,5 }, 3);
	for (auto c : i)
	{
		cout << c << ' ';
	}
	return 0;
}