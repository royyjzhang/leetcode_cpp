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
		return prev;
	}
	bool isPalindrome(ListNode* head) {
		if ((head == NULL) || (head->next == NULL))
			return true;
		ListNode *tail, *half, *newstart, *now;
		tail = head;
		half = head;
		while ((tail->next != NULL) && (tail->next->next != NULL)) {
			half = half->next;
			tail = tail->next->next;
		}
		newstart = reverseList(half->next);
		now = head;
		while (newstart != NULL) {
			if (now->val != newstart->val)
				return false;
			now = now->next;
			newstart = newstart->next;
		}
		return true;
	}
};

int main() {
	ListNode *head, *p;
	Solution s;
	head = new ListNode(4);
	p = new ListNode(4);
	p->next = head;
	head = p;
	/*p = new ListNode(4);
	p->next = head;
	head = p;*/
	/*p = new ListNode(1);
	p->next = head;
	head = p;*/
	/*p = new ListNode(0);
	p->next = head;
	head = p;*/
	if (s.isPalindrome(head))
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	system("PAUSE");
	return 0;
}