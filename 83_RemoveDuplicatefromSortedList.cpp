#include<iostream>
#include<vector>
#include<queue>
#include<stdlib.h>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode *now = head, *nextone;
		if ((now == NULL) || (now->next == NULL))
			return head;
		nextone = now->next;
		while (nextone != NULL) {
			if (now->val != nextone->val) {
				now = nextone;
				nextone = nextone->next;
			}
			else {
				now->next = nextone->next;
				delete nextone;
				nextone = now->next;
			}
		}
		return head;
	}
};

int main() {
	ListNode *head, *p, *newhead;
	Solution s;
	head = new ListNode(3);
	p = new ListNode(3);
	p->next = head;
	head = p;
	p = new ListNode(2);
	p->next = head;
	head = p;
	p = new ListNode(1);
	p->next = head;
	head = p;
	p = new ListNode(1);
	p->next = head;
	head = p;
	newhead = s.deleteDuplicates(head);
	p = newhead;
	while (p != NULL) {
		cout << p->val << " ";
		p = p->next;
	}
	system("PAUSE");
	return 0;
}