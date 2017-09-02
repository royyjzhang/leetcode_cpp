#include<iostream>
#include<vector>
#include<queue>
#include<stdlib.h>
#include<string>
#include<algorithm>
#include<map>
#include<math.h>
#include<stdint.h>
#include<stack>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		bool flag = false;
		ListNode *a=l1, *b=l2, *newhead=NULL, *c, *prev_c=NULL;
		while ((a != NULL) && (b != NULL)) {
			c = new ListNode(a->val + b->val);
			a = a->next;
			b = b->next;
			if (flag) {
				c->val++;
				flag = false;
			}
			if (c->val > 9) {
				flag = true;
				c->val = c->val % 10;
			}
			if (newhead == NULL) {
				newhead = c;
				prev_c = newhead;
			}
			else {
				prev_c->next = c;
				prev_c = c;
			}
		}
		while (a != NULL) {
			c = new ListNode(a->val);
			a = a->next;
			if (flag)  {
				c->val++;
				flag = false;
			}
			if (c->val > 9) {
				flag = true;
				c->val = c->val % 10;
			}
			if (newhead == NULL) {
				newhead = c;
				prev_c = newhead;
			}
			else {
				prev_c->next = c;
				prev_c = c;
			}
		}
		while (b != NULL) {
			c = new ListNode(b->val);
			b = b->next;
			if (flag)  {
				c->val++;
				flag = false;
			}
			if (c->val > 9) {
				flag = true;
				c->val = c->val % 10;
			}
			if (newhead == NULL) {
				newhead = c;
				prev_c = newhead;
			}
			else {
				prev_c->next = c;
				prev_c = c;
			}
		}
		if (flag)   {
			c = new ListNode(1);
			flag = false;
			if (newhead == NULL) {
				newhead = c;
				prev_c = newhead;
			}
			else {
				prev_c->next = c;
				prev_c = c;
			}
		}
		return newhead;
	}	
};

int main() {
	ListNode *head1, *p, *head2, *head3;
	Solution s;
	head1 = new ListNode(3);
	p = new ListNode(4);
	p->next = head1;
	head1 = p;
	p = new ListNode(2);
	p->next = head1;
	head1 = p;
	head2 = new ListNode(4);
	p = new ListNode(6);
	p->next = head2;
	head2 = p;
	p = new ListNode(5);
	p->next = head2;
	head2 = p;
	p = s.addTwoNumbers(head1, head2);
	while (p != NULL) {
		cout << p->val << " ";
		p = p->next;
	}
	system("PAUSE");
	return 0;
}