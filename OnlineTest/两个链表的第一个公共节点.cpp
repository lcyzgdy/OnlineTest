#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

class Solution {
public:
	ListNode * FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
		vector<int> val;
		ListNode* head1 = pHead1;
		while (pHead1)
		{
			val.push_back(pHead1->val);
			pHead1->val = -0x3f3f3f3f;
			pHead1 = pHead1->next;
		}
		while (pHead2)
		{
			if (-0x3f3f3f3f == pHead2->val)
			{
				int i = 0;
				while (head1)
				{
					head1->val = val[i];
					i++;
					head1 = head1->next;
				}
				return pHead2;
			}
			pHead2 = pHead2->next;
		}
		return nullptr;
	}
};