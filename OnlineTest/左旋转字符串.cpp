#include<string>
using namespace std;

class Solution {
public:
	string LeftRotateString(string str, int n) {
		string l;
		int len = str.length();
		if (len == 0) return l;
		for (int i = 0; i < len; i++)
		{
			l += str[(i + n) % len];
		}
		return l;
	}
};