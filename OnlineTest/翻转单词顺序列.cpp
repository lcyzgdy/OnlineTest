#include<string>
#include<sstream>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	string ReverseSentence(string str) {
		reverse(str.begin(), str.end());
		int la = 0;
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == ' ')
			{
				int a = la;
				int b = i - 1;
				while (a < b)
				{
					char c = str[a];
					str[a] = str[b];
					str[b] = c;
					a++;
					b--;
				}
				la = i + 1;
			}
		}
		int a = la;
		int b = str.length() - 1;
		while (a < b)
		{
			char c = str[a];
			str[a] = str[b];
			str[b] = c;
			a++;
			b--;
		}
		return str;
	}
};

int main()
{
	Solution a;
	cout << a.ReverseSentence("") << endl;
	return 0;
}