#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		stack<int> s;
		int p = 0;
		for (int i = 0; i < pushV.size(); i++)
		{
			s.push(pushV[i]);
			while (!s.empty() && s.top() == popV[p])
			{
				s.pop();
				p++;
			}
		}
		return p == popV.size();
	}
};

int main()
{
	Solution a;
	cout << a.IsPopOrder({ 1,2,3,4,5 }, { 4,3,5,1,2 }) << endl;
	return 0;
}