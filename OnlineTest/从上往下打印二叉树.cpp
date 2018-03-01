#include<vector>
#include<deque>
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
	vector<int> PrintFromTopToBottom(TreeNode* root) {
		vector<int> result;
		if (root == nullptr) return result;
		deque<TreeNode*> next;
		next.push_back(root);
		while (!next.empty())
		{
			for (int i = 0; i < next.size(); i++)
			{
				result.push_back(next[i]->val);
			}
			int c = next.size();
			for (int i = 0; i < c; i++)
			{
				if (next[0]->left != nullptr) next.push_back(next[0]->left);
				if (next[0]->right != nullptr) next.push_back(next[0]->right);
				next.pop_front();
			}
		}
		return result;
	}
};