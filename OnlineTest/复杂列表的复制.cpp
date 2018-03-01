#include<iostream>
using namespace std;
struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
		label(x), next(NULL), random(NULL) {
	}
};

class Solution {
public:
	RandomListNode * Clone(RandomListNode* pHead)
	{
		RandomListNode* head = pHead;
		RandomListNode* newHead = nullptr;
		RandomListNode* cur = newHead;
		if (pHead)
		{
			newHead = new RandomListNode(head->label);
			cur = newHead;
			head = head->next;
		}
		else return nullptr;
		while (head)
		{
			RandomListNode* node = new RandomListNode(head->label);
			cur->next = node;
			cur = node;
			head = head->next;
		}
		head = pHead;
		cur = newHead;
		while (head)
		{
			auto tmp = pHead;
			while (tmp)
			{
				if (head->random == nullptr) break;
				if (tmp->label == head->random->label)
				{
					cur->random = tmp;
					break;
				}
				tmp = tmp->next;
			}
			head = head->next;
			cur = cur->next;
		}
		return newHead;
	}
};