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
		ListNode *now = head, *nextone, *newhead=NULL ,*prev=NULL;
		bool sethead = false, deletenow = false;
		if ((now == NULL) || (now->next == NULL))
			return head;
		nextone = now->next;
		while (nextone != NULL) {
			if (now->val != nextone->val) {
				if (!deletenow) {
					if (newhead == NULL) {
						newhead = now;
					}
					prev = now;
					now = nextone;
					nextone = nextone->next;
					sethead = true;
				}
				else {
					deletenow = false;
					if (sethead) {
						prev->next = nextone;
						delete now;
						now = nextone;
						if (nextone!=NULL)
							nextone = nextone->next;
					}
					else {
						delete now;
						now = nextone;
						if (nextone != NULL) {
							nextone = nextone->next;
							newhead = now;
						}
						else {
							newhead = NULL;
						}
					}
				}
			}
			else {
				now->next = nextone->next;
				delete nextone;
				nextone = now->next;
				deletenow = true;
			}
		}
		if (deletenow) {
			if ((newhead == now) || (newhead==NULL)) {
				delete now;
				return NULL;
			}
			nextone = newhead;
			while (nextone->next != now)
				nextone = nextone->next;
			nextone->next = NULL;
			delete now;
		}
		return newhead;
	}
};

int main() {
	ListNode *head, *p, *newhead;
	Solution s;
	head = new ListNode(0);
	p = new ListNode(0);
	p->next = head;
	head = p;
	p = new ListNode(1);
	p->next = head;
	head = p;
	p = new ListNode(1);
	p->next = head;
	head = p;
	p = new ListNode(2);
	p->next = head;
	head = p;
	p = new ListNode(3);
	p->next = head;
	head = p;
	p = new ListNode(3);
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