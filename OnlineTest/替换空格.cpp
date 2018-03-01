#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
using namespace std;

class Solution {
public:
	void replaceSpace(char *str, int length) {
		string l(str, length);
		for (int i = 0; i < l.length(); i++)
		{
			if (l[i] == ' ')
			{
				l[i] = '\%';
				l.insert(i + 1, "20");
			}
		}
		memcpy(str, l.c_str(), l.size());
	}
};

int main()
{
	Solution a;
	char l[256];
	memset(l, 0, sizeof(l));
	cin.getline(l, 256);
	a.replaceSpace(l, strlen(l));
	puts(l);
	return 0;
}