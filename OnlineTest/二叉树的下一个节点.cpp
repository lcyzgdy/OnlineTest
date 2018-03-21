#include<iostream>
using namespace std;

struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;
	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

	}
};

class Solution {
public:
	TreeLinkNode * GetNext(TreeLinkNode* pNode)
	{
		if (pNode->right != nullptr) return pNode->right;
		else
		{
			if (pNode->next == nullptr)
			{
				TreeLinkNode* left = nullptr;
				pNode = pNode->right;
				if (pNode->left)
				{
					while (pNode->left)
					{
						pNode = pNode->left;
					}
				}
				return pNode;
			}
			else if (pNode->next->left == pNode)
			{
				return pNode->next;
			}
			else
			{
				TreeLinkNode* pa = pNode->next;
				while (pa && pa->right == pNode)
				{
					pNode = pa;
					pa = pa->next;
				}
				return pa;
			}
		}
	}
};