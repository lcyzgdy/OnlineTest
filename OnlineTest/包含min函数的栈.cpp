#include<vector>
#include<algorithm>
using namespace std;

class Solution {
	vector<int> m_stack;
public:
	void push(int value) {
		m_stack.push_back(value);
	}
	void pop() {
		m_stack.pop_back();
	}
	int top() {
		return *m_stack.rbegin();
	}
	int min() {
		return *min_element(m_stack.begin(), m_stack.end());
	}
};