#include<iostream>
#include<vector>
#include<queue>
#include<stdlib.h>
#include<string>
#include<algorithm>
#include<map>
#include<math.h>
#include<stdint.h>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		ListNode *newhead, *newend, *link;
		int len = 1, move;
		if ((head == NULL) || (k==0))
			return head;
		link = head;
		while (link->next != NULL) {
			len++;
			link = link->next;
		}
		newhead = head;
		newend = head;
		if ((k%len) == 0)
			return head;
		move = len - (k%len);
		while ((move > 0) && (newhead->next!=NULL)) {
			newend = newhead;
			newhead = newhead->next;
			move--;
		}
		link->next = head;
		newend->next = NULL;
		return newhead;
	}
};

int main() {
	ListNode *head, *p, *newhead;
	Solution v;
	head = new ListNode(5);
	/*p = new ListNode(4);
	p->next = head;
	head = p;
	p = new ListNode(3);
	p->next = head;
	head = p;
	p = new ListNode(2);
	p->next = head;
	head = p;
	p = new ListNode(1);
	p->next = head;
	head = p;*/
	newhead = v.rotateRight(head, 5);
	p = newhead;
	while (p!= NULL){
		cout << p->val << endl;
		p = p->next;
	}
	system("PAUSE");
	return 0;
}