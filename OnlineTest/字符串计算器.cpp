#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;

vector<string> strs;
stack<int> nums;
stack<char> opes;
stack<int> com;
queue<int> q;
string l;

int Pri(char op)
{
	switch (op)
	{
	case '+':
		return 1;
	case '-':
		return 1;
	case '*':
		return 3;
	case '/':
		return 3;
	case '@':
		return 5;
	default:
		return 0;
	}
}

void Zzh()
{
	string temp;
	for (int i = 0; i < l.length(); i++)
	{
		if (i == 0)
		{
			if (l[i] == '-') opes.push('-');
			else if (l[i] == '~') opes.push('~');
			else temp += l[i];
			continue;
		}
		if (l[i] == '*' || l[i] == '/' || l[i] == '+' || l[i] == '-' || l[i] == '(' || l[i] == ')' || l[i] == '~')
		{
			strs.push_back(temp);
			temp.clear();
			if (Pri(l[i]) < opes.top()) opes.push(Pri(l[i]));
			else
			{
				while (Pri(l[i]) < opes.top())
				{
					q.push(nums.top());
					nums.pop();
					q.push(nums.top());
					nums.pop();
				}
				opes.push(Pri(l[i]));

			}
		}
		else if (l[i] == '(')
		{

		}
		else if (l[i] == ')')
		{
		}
		else
		{
			temp += l[i];
		}
	}
	strs.push_back(temp);

}

string Compute(string& a, string& b, char ch)
{
	switch (ch)
	{
	case '+':
		return std::move(a + b);
	case '-':
		if (a.find(b) != -1)
		{
			return a.erase(a.find_first_of(b), b.length());
		}
		else return a;
	case '*':
	{
		string r;
		for (int i = 0; i < a.length(); i++)
		{
			r += a[i] + b;
		}
		return r;
	}
	case '/':
	{
		string r(a);
		while (r.find(b) != -1)
		{
			r = r.erase(r.find_first_of(b), b.length());
		}
		return r;
	}
	default:
		break;
	}
}

void Hz()
{
	while (!q.empty())
	{
		if (-q.front() > 0)
		{
			string num1 = strs[com.top()];
			com.pop();
			string num2 = strs[com.top()];
			com.pop();
			strs.push_back(Compute(num1, num2, -q.front()));
			com.push(strs.size() - 1);
		}
		else
		{
			com.push(q.front());
			q.pop();
		}
	}
	cout << strs[com.top()];
}

int main()
{
	cin >> l;
	Zzh();
	Hz();
	return 0;
}