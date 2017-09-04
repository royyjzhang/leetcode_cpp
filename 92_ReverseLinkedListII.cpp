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
	vector<ListNode*> reverseList(ListNode* head) {
		vector<ListNode*> result(2, NULL);
		if (head == NULL)
			return result;
		if (head->next == NULL) {
			result[0] = head;
			result[1] = head;
			return result;
		}
		ListNode *tmp, *now, *prev;
		prev = head;
		now = head->next;
		prev->next = NULL;
		while (now != NULL) {
			tmp = now->next;
			now->next = prev;
			prev = now;
			now = tmp;
		}
		result[0] = prev;
		result[1] = head;
		return result;
	}
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		ListNode *start = head, *end = head, *start_prev=NULL, *end_next=NULL;
		vector<ListNode*> inter;
		for (int i = 1; i < m; i++) {
			start_prev = start;
			start = start->next;
		}
		for (int i = 1; i < n; i++) {
			end = end->next;
		}
		end_next = end->next;
		end->next = NULL;
		inter = reverseList(start);
		if (start_prev != NULL)
			start_prev->next = inter[0];
		if (end_next != NULL)
			inter[1]->next = end_next;
		if (start_prev == NULL)
			return inter[0];
		else
			return head;
	}
};

int main() {
	ListNode *head, *p;
	Solution s;
	head = new ListNode(5);
	p = new ListNode(4);
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
	head = p;
	p = s.reverseBetween(head, 1, 1);
	while (p != NULL) {
		cout << p->val << " ";
		p = p->next;
	}
	system("PAUSE");
	return 0;
}