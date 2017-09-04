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
#include<set>
#include<algorithm>
#include<sstream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		ListNode *result, *prev, *now, *next, *pprev;
		if (head == NULL) {
			return head;
		}
		if (head->next == NULL) {
			return head;
		}
		prev = head;
		now = head->next;
		next = now->next;
		result = now;
		now->next = prev;
		prev->next = next;
		pprev = prev;
		prev = next;
		if (next == NULL) {
			now = NULL;
		}
		else {
			now = next->next;
		}
		while ((prev != NULL) && (now != NULL)) {
			next = now->next;
			pprev->next = now;
			now->next = prev;
			prev->next = next;
			pprev = prev;
			prev = next;
			if (next == NULL) {
				now = NULL;
			}
			else {
				now = next->next;
			}
		}
		if (prev != NULL) {
			pprev->next = prev;
		}
		return result;
	}
};

int main() {
	Solution s;
	ListNode *head, *p, *result, *temp;
	head = new ListNode(1);
	p = head;
	temp = new ListNode(2);
	p->next = temp;
	/*p = temp;
	temp = new ListNode(3);
	p->next = temp;
	p = temp;
	temp = new ListNode(4);
	p->next = temp;
	p = temp;
	temp = new ListNode(5);
	p->next = temp;
	p = temp;*/
	p = head;
	while (p != NULL) {
		cout << p->val << "->";
		p = p->next;
	}
	cout << endl;
	result = s.swapPairs(head);
	p = result;
	while (p != NULL) {
		cout << p->val << "->";
		p = p->next;
	}
	cout << endl;
	system("PAUSE");
	return 0;
}