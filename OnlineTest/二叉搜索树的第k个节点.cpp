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
	vector<int> kth;
	TreeNode* node;
	void MidOrder(TreeNode* r, int k)
	{
		if (kth.size() > k) return;
		if (r->left) MidOrder(r->left, k);
		kth.push_back(r->val);
		if (kth.size() == k) node = r;
		if (r->right) MidOrder(r->right, k);
	}
public:
	TreeNode * KthNode(TreeNode* pRoot, int k)
	{
		if (k == 0) return nullptr;
		if (!pRoot) return nullptr;
		MidOrder(pRoot, k);
		if (kth.size() < k) return nullptr;
		return node;
	}
};