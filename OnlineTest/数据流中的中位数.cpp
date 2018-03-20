#include<list>
#include<iostream>
using namespace std;

class Solution {
	list<int> l;
public:
	void Insert(int num)
	{
		if (l.size() == 0)
		{
			l.push_back(num);
			return;
		}
		if (*l.begin() > num)
		{
			l.push_front(num);
			return;
		}
		for (auto i = l.rbegin(); i != l.rend(); i++)
		{
			if (*i < num)
			{
				l.insert(i.base(), num);
				break;
			}
		}
	}

	double GetMedian()
	{
		if (l.size() == 1) return *l.begin();
		if (l.size() & 1)
		{
			list<int>::iterator it = l.begin();
			for (int i = 0; i < (l.size() - 1) / 2; i++)
			{
				++it;
			}
			//++it;
			return *it;
		}
		else
		{
			list<int>::iterator it = l.begin();
			for (int i = 0; i < (l.size() - 1) / 2; i++)
			{
				++it;
			}
			double a = *it;
			++it;
			return (a + (double)*it) / 2;
		}
	}

};

int main()
{
	int s[] = { 5,2,3,4,1,6,7,0,8 };
	Solution a;
	for (int i = 0; i < 9; i++)
	{
		a.Insert(s[i]);
		cout << a.GetMedian() << ' ';
	}
	return 0;
}