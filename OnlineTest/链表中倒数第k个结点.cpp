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
	ListNode * FindKthToTail(ListNode* pListHead, unsigned int k) {
		int c = 0;
		ListNode* head = pListHead;
		while (head != nullptr)
		{
			head = head->next;
			c++;
		}
		c -= k;
		if (c < 0) return nullptr;
		head = pListHead;
		while (c--)
		{
			head = head->next;
		}
		return head;
	}
};