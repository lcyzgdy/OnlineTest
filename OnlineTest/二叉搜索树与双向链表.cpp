#include<iostream>
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
public:
	TreeNode * Convert(TreeNode* pRootOfTree)
	{
		if (pRootOfTree == nullptr) return nullptr;
		TreeNode* m = nullptr;
		Convert(pRootOfTree, m);

		TreeNode* m1 = pRootOfTree;
		while (m1)
		{
			m1 = m1->left;
		}
		return m1;
	}

	void Convert(TreeNode* root, TreeNode*& m)
	{
		if (root == nullptr) return;
		Convert(root->left, m);
		root->left = m;
		if (m) m->right = root;
		m = root;
		Convert(root->right, m);
	}
};