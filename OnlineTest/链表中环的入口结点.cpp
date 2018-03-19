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
	ListNode * EntryNodeOfLoop(ListNode* pHead)
	{
		if (pHead == nullptr || pHead->next == nullptr) return nullptr;
		ListNode* fast = pHead;
		ListNode* slow = pHead;
		while (fast != nullptr && fast->next != nullptr)
		{
			slow = slow->next;
			fast = fast->next->next;
			if (fast == slow) break;
		}
		if (fast == nullptr || fast->next == nullptr) return nullptr;
		ListNode* tail = fast;
		ListNode* nHead1 = tail->next;
		ListNode* nHead2 = pHead;

		ListNode* p1 = nHead1;
		int len1 = 1;
		while (p1 != tail)
		{
			p1 = p1->next;
			len1++;
		}

		ListNode* p2 = nHead2;
		int len2 = 1;
		while (p2 != tail)
		{
			p2 = p2->next;
			len2++;
		}

		p1 = nHead1;
		p2 = nHead2;
		if (len1 > len2)
		{
			int d = len1 - len2;
			while (d--)
			{
				p1 = p1->next;
			}
		}
		else
		{
			int d = len2 - len1;
			while (d--)
			{
				p2 = p2->next;
			}
		}
		while (p1 != p2)
		{
			p1 = p1->next;
			p2 = p2->next;
		}
		return p1;
	}
};