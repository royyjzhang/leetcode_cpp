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
	ListNode* reverseList(ListNode* head) {
		if ((head == NULL) || (head->next == NULL))
			return head;
		ListNode *newhead, *tmp, *now, *prev;
		prev = head;
		now = head->next;
		prev->next = NULL;
		while (now != NULL) {
			tmp = now->next;
			now->next = prev;
			prev = now;
			now = tmp;
		}
		return prev;
	}
};

int main() {
	ListNode *head, *p, *newhead;
	Solution s;
	head = new ListNode(4);
	p = new ListNode(3);
	p->next = head;
	head = p;
	p = new ListNode(2);
	p->next = head;
	head = p;
	/*p = new ListNode(1);
	p->next = head;
	head = p;*/
	/*p = new ListNode(0);
	p->next = head;
	head = p;*/
	newhead = s.reverseList(head);
	p = newhead;
	while (p != NULL) {
		cout << p->val << " ";
		p = p->next;
	}
	system("PAUSE");
	return 0;
}