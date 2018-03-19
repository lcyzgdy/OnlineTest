#include<iostream>
#include<string>
#include<deque>
using namespace std;

class Solution
{
	deque<char> unique;
	string l;
public:
	//Insert one char from stringstream
	void Insert(char ch)
	{
		if (unique.size() == 0)
		{
			unique.push_back(ch);
		}
		else if (auto it = find(unique.begin(), unique.end(), ch); unique.end() != it)
		{
			unique.erase(it);
		}
		else
		{
			unique.push_back(ch);
		}
	}
	//return the first appearence once char in current stringstream
	char FirstAppearingOnce()
	{
		if (unique.size() == 0) return '#';
		else
		{
			return unique.front();
		}
	}
};

int main()
{
	Solution a;
	char p[] = "google";
	for (int i = 0; i < 6; i++)
	{
		a.Insert(p[i]);
		cout << a.FirstAppearingOnce();
	}
	return 0;
}