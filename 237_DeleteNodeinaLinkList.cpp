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
	void deleteNode(ListNode* node) {
		ListNode* n = node;
		ListNode* next_n = node->next;;
		n->val = n->next->val;
		n->next = n->next->next;		
		delete next_n;
	}
};

int main() {
	Solution s;
	ListNode *first, *p, *t;
	first = new ListNode(1);
	p = new ListNode(2);
	t = p;
	p->next = first;
	first = p;
	p = new ListNode(3);
	p->next = first;
	first = p;
	p = new ListNode(4);
	p->next = first;
	first = p;
	s.deleteNode(t);
	p = first;
	while (p != NULL) {
		cout << p->val << endl;
		p = p->next;
	}
	system("PAUSE");
	return 1;
}