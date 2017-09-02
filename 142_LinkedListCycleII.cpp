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
	ListNode *detectCycle(ListNode *head) {
		ListNode *fast = head, *slow = head, *start=head;
		while ((fast != NULL) && (fast->next != NULL)) {
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow) {
				while (true) {
					if (fast == start)
						return fast;
					start = start->next;
					fast = fast->next;
				}
			}
		}
		return NULL;
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
	head->next->next->next = head;
	cout << s.detectCycle(head)->val << endl;
	system("PAUSE");
	return 0;
}