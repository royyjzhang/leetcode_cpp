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
	bool hasCycle(ListNode *head) {
		ListNode *fast = head, *slow = head;
		while ((fast != NULL) && (fast->next != NULL)) {
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow)
				return true;
		}
		return false;
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
	if (s.hasCycle(head))
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	system("PAUSE");
	return 0;
}