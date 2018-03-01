#include<iostream>
#include<vector>
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
	vector<vector<int> >result;
	vector<int> temp;

	void Dfs(TreeNode* root, int conn)
	{
		temp.push_back(root->val);
		if (conn - root->val == 0 && !(root->left) && !(root->right)) result.push_back(temp);
		else
		{
			if (root->left) Dfs(root->left, conn - root->val);
			if (root->right) Dfs(root->right, conn - root->val);
		}
		temp.pop_back();
	}

public:
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber)
	{
		if (root) Dfs(root, expectNumber);
		return result;
	}
};