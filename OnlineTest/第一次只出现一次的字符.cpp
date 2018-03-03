#include<string>
using namespace std;

class Solution {
public:
	int FirstNotRepeatingChar(string str) {
		int c[256];
		memset(c, 0, sizeof(c));
		for (char i : str)
		{
			c[i]++;
		}
		for (int i = 0; i < str.length(); i++)
		{
			if (c[str[i]] == 1) return i;
		}
		return -1;
	}
};