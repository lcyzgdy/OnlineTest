#include<iostream>
#include<queue>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

class Solution {
	queue<TreeNode*> q1;
	queue<TreeNode*> q2;
public:
	vector<vector<int> > Print(TreeNode* pRoot) {
		vector<vector<int>> r;
		vector<int> o;
		if (pRoot == nullptr) return r;
		q1.push(pRoot);
		for (int i = 2; i; i++)
		{
			o.clear();
			if (i & 1)
			{
				while (!q2.empty())
				{
					auto h = q2.front();
					q2.pop();
					if (h->left) q1.push(h->left);
					if (h->right) q1.push(h->right);
					o.push_back(h->val);
				}
				reverse(o.begin(), o.end());
				r.emplace_back(o);
				if (q1.empty()) break;
			}
			else
			{
				while (!q1.empty())
				{
					auto h = q1.front();
					q1.pop();
					if (h->left) q2.push(h->left);
					if (h->right) q2.push(h->right);
					o.push_back(h->val);
				}
				r.emplace_back(o);
				if (q2.empty()) break;
			}
		}
		return r;
	}

};