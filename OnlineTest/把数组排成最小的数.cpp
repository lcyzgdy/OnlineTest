#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<sstream>
using namespace std;

class Solution {
public:
	string PrintMinNumber(vector<int> numbers) {
		sort(numbers.begin(), numbers.end(), [this](int a, int b) ->bool {
			string&& s1 = to_string(a) + to_string(b);
			string&& s2 = to_string(b) + to_string(a);
			return s1 < s2;
		});
		stringstream ss;
		for (int i : numbers)
		{
			ss << i;
		}
		return ss.str();
	}
};

int main()
{
	Solution a;
	cout << a.PrintMinNumber({ 3,323,32123 }) << endl;
}