#include<iostream>
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
	ListNode * Merge(ListNode* pHead1, ListNode* pHead2)
	{
		ListNode* head = nullptr;
		if (pHead1 != nullptr && pHead2 != nullptr)
		{
			if (pHead1->val < pHead2->val)
			{
				head = pHead1;
				pHead1 = pHead1->next;
			}
			else
			{
				head = pHead2;
				pHead2 = pHead2->next;
			}
		}
		ListNode* cur = head;
		while (pHead1 && pHead2)
		{
			if (pHead1->val < pHead2->val)
			{
				cur->next = pHead1;
				pHead1 = pHead1->next;
			}
			else
			{
				cur->next = pHead2;
				pHead2 = pHead2->next;
			}
			cur = cur->next;
		}

		while (pHead1)
		{
			if (cur == nullptr)
			{
				cur = head = pHead1;
				break;
			}
			cur->next = pHead1;
			pHead1 = pHead1->next;
		}
		while (pHead2)
		{
			if (cur == nullptr)
			{
				cur = head = pHead2;
				break;
			}
			cur->next = pHead2;
			pHead2 = pHead2->next;
		}
		return head;
	}
};

int main()
{
	Solution a;

	ListNode* aa[3];
	int c = 0;
	for (int i = 0; i < 3; i++)
	{
		aa[i] = new ListNode(c);
		c++;
	}
	for (int i = 0; i < 2; i++)
	{
		aa[i]->next = aa[i + 1];
	}
	aa[2]->next = nullptr;


	ListNode* bb[3];
	c = 0;
	for (int i = 0; i < 3; i++)
	{
		bb[i] = new ListNode(c);
		c++;
	}
	for (int i = 0; i < 2; i++)
	{
		bb[i]->next = bb[i + 1];
	}
	bb[2]->next = nullptr;

	ListNode* q = a.Merge(aa[0], nullptr);
	while (q)
	{
		cout << q->val << ' ';
		q = q->next;
	}
	return 0;
}