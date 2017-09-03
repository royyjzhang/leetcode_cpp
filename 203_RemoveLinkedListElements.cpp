#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};

class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		ListNode* first = head;
		ListNode *p, *q;
		while ((first != NULL) && (first->val == val)) {
			p = first;
			first = first->next;
			delete p;
		}
		if (first == NULL)
			return NULL;
		p = first->next;
		q = first;
		while (p != NULL) {
			if (p->val == val) {
				q->next = p->next;
				delete p;
				p = q->next;
			}
			else {
				q = p;
				p = p->next;
			}
		}
		return first;
	}
};

int main() {
	Solution s;
	ListNode *first, *p;
	first = new ListNode(1);
	p = new ListNode(4);
	p->next = first;
	first = p;
	p = new ListNode(2);
	p->next = first;
	first = p;
	p = new ListNode(4);
	p->next = first;
	first = p;
	p = new ListNode(3);
	p->next = first;
	first = p;
	p = new ListNode(4);
	p->next = first;
	first = p;
	p = new ListNode(4);
	p->next = first;
	first = p;
	p = new ListNode(4);
	p->next = first;
	first = p;
	p = new ListNode(4);
	p->next = first;
	first = p;
	first = s.removeElements(first, 4);
	p = first;
	while (p != NULL) {
		cout << p->val << endl;
		p = p->next;
	}
	system("PAUSE");
	return 1;
}