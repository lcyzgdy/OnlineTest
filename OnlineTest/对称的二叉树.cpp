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
	TreeNode* Mirror(TreeNode* pRoot)
	{
		if (pRoot == nullptr) return nullptr;
		TreeNode* mirrorRoot = new TreeNode(pRoot->val);
		if (pRoot->left) mirrorRoot->right = Mirror(pRoot->left);
		if (pRoot->right) mirrorRoot->left = Mirror(pRoot->right);
		return mirrorRoot;
	}

	bool MidOrder(TreeNode* root, TreeNode* mirrorRoot)
	{
		if (root == nullptr && mirrorRoot == nullptr) return true;
		if (root == nullptr || mirrorRoot == nullptr) return false;
		if (root->val != mirrorRoot->val) return false;
		if (MidOrder(root->left, mirrorRoot->left) && MidOrder(root->right, mirrorRoot->right)) return true;
		return false;
	}
public:
	bool isSymmetrical(TreeNode* pRoot)
	{
		TreeNode* mirror = Mirror(pRoot);
		return MidOrder(pRoot, mirror);
	}
};

int main()
{
	Solution a;
	TreeNode* aa[5] = { new TreeNode(1),new TreeNode(2),new TreeNode(2),new TreeNode(3),new TreeNode(3) };
	aa[0]->left = aa[1];
	aa[0]->right = aa[2];
	aa[1]->left = aa[3];
	aa[2]->right = aa[4];
	cout << a.isSymmetrical(aa[0]);
}