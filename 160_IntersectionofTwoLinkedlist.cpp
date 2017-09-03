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
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode *a = headA, *b = headB;
		while (a != b) {
			if (a == NULL) {
				a = headB;
			}
			else {
				a = a->next;
			}
			if (b == NULL) {
				b = headA;
			}
			else {
				b = b->next;
			}
		}
		return a;
	}
};

int main() {
	Solution s;
	ListNode *heada, *headb, *temp, *inter, *result;
	heada = new ListNode(1);
	temp = new ListNode(2);
	heada->next = temp;
	temp = new ListNode(3);
	heada->next->next = temp;
	headb = new ListNode(-1);
	temp = new ListNode(-2);
	headb->next = temp;
	inter = new ListNode(4);
	heada->next->next->next = inter;
	headb->next->next = inter;
	temp = new ListNode(5);
	inter->next = temp;
	temp = new ListNode(6);
	inter->next->next = temp;
	result = s.getIntersectionNode(heada, headb);
	cout << result->val << endl;
	system("PAUSE");
	return 0;
}