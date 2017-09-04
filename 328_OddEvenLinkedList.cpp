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
	ListNode* oddEvenList(ListNode* head) {
		ListNode *first = head, *second, *p_f, *q_f, *p_s, *q_s;
		bool flag_f = true, flag_s = true;
		if ((head == NULL) || (head->next == NULL) || (head->next->next==NULL))
			return head;
		second = head->next;
		p_f = first->next->next;
		p_s = second->next->next;
		q_f = first;
		q_s = second;
		while ((p_f!=NULL) || (p_s!=NULL)) {
			q_f->next = p_f;
			q_s->next = p_s;
			q_f = p_f;
			q_s = p_s;
			if ((p_s != NULL) && (p_s->next != NULL)) {
				p_f = p_f->next->next;
				p_s = p_s->next->next;
			}
			else
				break;
		}
		q_f->next = second;
		return first;
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
	newhead=s.oddEvenList(head);
	p = newhead;
	while (p != NULL) {
		cout << p->val << " ";
		p = p->next;
	}
	system("PAUSE");
	return 0;
}