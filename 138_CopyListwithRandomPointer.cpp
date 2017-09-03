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
#include<sstream>
#include<unordered_map>
#include<unordered_set>
#include<time.h>
using namespace std;

/**
* Definition for singly-linked list with a random pointer.*/
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		RandomListNode *newhead, *cur, *org;
		if (head == NULL) {
			return NULL;
		}
		org = head;
		while (org != NULL) {
			cur = new RandomListNode(org->label);
			cur->next = org->next;
			org->next = cur;
			org = cur->next;
		}
		org = head;
		while (org != NULL) {
			if (org->random != NULL) {
				org->next->random = org->random->next;
			}
			org = org->next->next;
		}
		newhead = head->next;
		org = head;
		cur = newhead;
		while (org != NULL) {
			org->next = cur->next;
			if (org->next != NULL) {
				cur->next = org->next->next;
			}
			org = org->next;
			cur = cur->next;
		}
		return newhead;
	}
};

int main() {
	Solution solution;
	RandomListNode *head, *p;
	head = new RandomListNode(0);
	p = new RandomListNode(1);
	head->next = p;
	p = new RandomListNode(2);
	head->next->next = p;
	head->random = p;
	p = new RandomListNode(3);
	head->next->next->next = p;
	p = new RandomListNode(4);
	head->next->next->next->next = p;
	head->next->random = p;
	p = head;
	while (p != NULL) {
		cout <<"Label: "<< p->label << endl;
		cout << "Next: " << p->next << endl;
		cout << "Random:" << p->random << endl;
		p = p->next;
	}
	cout << endl;
	p = solution.copyRandomList(head);
	while (p != NULL) {
		cout << "Label: " << p->label << endl;
		cout << "Next: " << p->next << endl;
		cout << "Random:" << p->random << endl;
		p = p->next;
	}
	system("PAUSE");
	return 0;
}