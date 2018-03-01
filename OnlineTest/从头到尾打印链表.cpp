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
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> r;
		while (head != nullptr)
		{
			r.push_back(head->val);
			head = head->next;
		}
		reverse(r.begin(), r.end());
		return r;
	}
};