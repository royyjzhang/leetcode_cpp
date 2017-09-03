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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode *now1, *now2, *result, *now;
		now1 = l1;
		now2 = l2;
		if ((now1 == NULL) && (now2 == NULL)) {
			return NULL;
		}
		else if (now1 == NULL) {
			return now2;
		}
		else if (now2 == NULL) {
			return now1;
		}
		else {
			if (now1->val >= now2->val) {
				result = now2;
				now2 = now2->next;
			}
			else {
				result = now1;
				now1 = now1->next;
			}
		}		
		now = result;
		while ((now1 != NULL) && (now2 != NULL)) {
			if (now1->val >= now2->val) {
				now->next = now2;
				now2 = now2->next;
				now = now->next;
			}
			else {
				now->next = now1;
				now1 = now1->next;
				now = now->next;
			}
		}
		if (now1 != NULL) {
			now->next = now1;
		}
		if (now2 != NULL) {
			now->next = now2;
		}
		return result;
	}
};

int main() {
	Solution s;
	ListNode *l1, *l2, *result, *p, *temp;
	l1 = new ListNode(1);
	p = l1;
	temp = new ListNode(3);
	p->next = temp;
	p = p->next;
	temp = new ListNode(5);
	p->next = temp;
	p = p->next;
	l2 = new ListNode(2);
	p = l2;
	temp = new ListNode(4);
	p->next = temp;
	p = p->next;
	temp = new ListNode(6);
	p->next = temp;
	p = p->next;
	result = s.mergeTwoLists(l1, l2);
	p = result;
	while (p != NULL) {
		cout << p->val << endl;
		p = p->next;
	}
	system("PAUSE");
	return 1;
}