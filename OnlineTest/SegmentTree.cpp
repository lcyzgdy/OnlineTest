#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

template<typename T>
class ZkwSegmengTree
{
	vector<T> m_arr;
public:
	ZkwSegmengTree() = default;
	ZkwSegmengTree(int size)
	{
		
		m_arr.reserve(size);
	};

	void Add(int l, int r, T&& v)
	{
		while (r > m_arr.size())
		{
			m_arr.emplace_back(T a);
		}
	}

	void Add(int l, int r, const T& v)
	{
	}

	T&& Sum(int l, int r)
	{
	}

	T Sum(int l, int r)
	{
	}
};