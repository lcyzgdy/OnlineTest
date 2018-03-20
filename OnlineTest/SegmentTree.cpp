#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
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

	void Build(initializer_list<T> data)
	{
		for (m_size = 1; m_size < data.size(); m_size <<= 1);
		m_arr.reserve(m_size);
		for (int i = 0; i < data.size(); i++) m_arr[i + (m_size << 1)] = data[i];
		for (int i = m_size << 1; i; i--) m_arr[i] = max(m_arr[i << 1], m_arr[i << 1 | 1]);
	}

	void Build(const vector<T>& data)
	{
		for (m_size = 1; m_size < data.size() + 1; m_size <<= 1);
		m_arr.resize(m_size);
		for (int i = 0; i < data.size(); i++) m_arr[i + (m_size >> 1)] = data[i];
		for (int i = (m_size >> 1) - 1; i; i--)
			m_arr[i] = max(m_arr[i << 1], m_arr[i << 1 | 1]);
	}

	void Modify(int x, const T& v)
	{

	}

	T Max(int l, int r)
	{

	}

	T Sum(int l, int r)
	{
	}
};