#include<iostream>
#include<stack>
using namespace std;

class Solution
{
public:
	void push(int node) {
		while (!stack2.empty())
		{
			stack1.push(stack2.top());
			stack2.pop();
		}
		stack1.push(node);
	}

	int pop() {
		//while (!stack2.empty()) stack2.pop();
		while (!stack1.empty())
		{
			stack2.push(stack1.top());
			stack1.pop();
		}
		int t = stack2.top();
		stack2.pop();
		return t;
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};

int main()
{
	Solution a;
	for (int i = 0; i < 10; i++)
	{
		a.push(i);
	}
	for (int i = 0; i < 10; i++)
	{
		cout << a.pop() << ' ';
	}
	return 0;
}