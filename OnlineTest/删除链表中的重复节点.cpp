#include<iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode() :
		val(0), next(NULL) {
	}
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

class Solution {
public:
	ListNode * deleteDuplication(ListNode* pHead)
	{
		if (pHead == nullptr) return nullptr;
		if (pHead->next == nullptr) return pHead;
		ListNode* head = new ListNode(0x3f3f3f3f); // 防止头节点被删除
		head->next = pHead;

		ListNode* p = head;
		ListNode* last = nullptr;

		while (p)
		{
			if (p->next && p->next->val == p->val)
			{
				while (p->next && p->next->val == p->val)
				{
					p->next = p->next->next;
				}
				last->next = p->next;
				p = p->next;
				continue;
			}
			last = p;
			p = p->next;
		}

		return head->next;
	}
};

int main()
{
	Solution a;
	ListNode* b[7] = { new ListNode(), new ListNode(), new ListNode(), new ListNode(), new ListNode(), new ListNode(), new ListNode() };
	b[0]->val = 1; b[0]->next = b[1];
	b[1]->val = 1; b[1]->next = b[2];
	b[2]->val = 3; b[2]->next = b[3];
	b[3]->val = 3; b[3]->next = b[4];
	b[4]->val = 3; b[4]->next = b[5];
	b[5]->val = 4; b[5]->next = b[6];
	b[6]->val = 5; //b[4]->next = b[5];
	ListNode* p = a.deleteDuplication(b[0]);
	while (p)
	{
		cout << p->val << ' ';
		p = p->next;
	}
}