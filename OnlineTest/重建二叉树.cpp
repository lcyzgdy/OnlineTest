#include<iostream>
#include<vector>
using namespace std;
//Definition for binary tree
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode * reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		int p = -1;
		for (int i = 0; i < pre.size(); i++)
		{
			if (find(vin.begin(), vin.end(), pre[i]) != vin.end())
			{
				p = i;
				break;
			}
		}
		if (p == -1) return nullptr;
		TreeNode* root = new TreeNode(pre[p]);
		if (vin.size() > 1)
		{
			auto it = find(vin.begin(), vin.end(), pre[p]);
			{
				vector<int> newVin;
				for (auto i = vin.begin(); i != it; i++)
				{
					newVin.push_back(*i);
				}
				root->left = reConstructBinaryTree(pre, newVin);
			}
			{
				vector<int> newVin;
				for (auto i = ++it; i != vin.end(); i++)
				{
					newVin.push_back(*i);
				}
				root->right = reConstructBinaryTree(pre, newVin);
			}
		}
		return root;
	}
};

int main()
{
	vector<int> pre;
	vector<int> vin;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		pre.push_back(a);
	}
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		vin.push_back(a);
	}

	Solution a;
	TreeNode* pp = a.reConstructBinaryTree(pre, vin);
	return 0;
}