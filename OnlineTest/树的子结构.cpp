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
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if (pRoot2 == nullptr) return false;
		if (pRoot1 == nullptr &&  pRoot2 == nullptr) return true;
		if (pRoot1 == nullptr) return false;
		if (pRoot1->val == pRoot2->val)
		{
			bool a = true, b = true;
			if (pRoot1->left != nullptr && pRoot2->left != nullptr) a = HasSubtree(pRoot1->left, pRoot2->left);
			else if (pRoot1->left == nullptr && pRoot2->left != nullptr) a = false;
			if (pRoot1->right != nullptr && pRoot2->right != nullptr) b = HasSubtree(pRoot1->right, pRoot2->right);
			else if (pRoot1->right == nullptr && pRoot2->right != nullptr) b = false;
			if (a && b) return true;
		}
		bool a = false, b = false;
		if (pRoot1->left != nullptr) a = HasSubtree(pRoot1->left, pRoot2);
		if (pRoot1->right != nullptr) b = HasSubtree(pRoot1->right, pRoot2);
		return a || b;
	}
};

int main()
{
	Solution a;
	TreeNode* s[7];
	TreeNode* d[3];
	s[0] = new TreeNode(8);
	s[1] = new TreeNode(8);
	s[2] = new TreeNode(7);
	s[3] = new TreeNode(9);
	s[4] = new TreeNode(2);
	s[5] = new TreeNode(4);
	s[6] = new TreeNode(7);

	d[0] = new TreeNode(8);
	d[1] = new TreeNode(9);
	d[2] = new TreeNode(2);

	s[0]->left = s[1];
	s[0]->right = s[2];
	s[1]->left = s[3];
	s[1]->right = s[4];
	s[3]->right = s[5];
	s[4]->left = s[6];

	d[0]->left = d[1];
	d[0]->right = d[2];

	cout << a.HasSubtree(s[0], d[0]) << endl;
	return 0;
}