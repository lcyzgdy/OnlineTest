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
	ListNode * ReverseList(ListNode* pHead) {
		if (pHead == nullptr) return nullptr;
		//ListNode* cur = pHead;
		ListNode* last = nullptr;
		ListNode* next = pHead->next;
		while (pHead != nullptr)
		{
			next = pHead->next;
			pHead->next = last;
			last = pHead;
			pHead = next;
		}
		return last;
	}
};