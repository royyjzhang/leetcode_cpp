#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<stdlib.h>
using namespace std;

/**
* Definition for singly-linked list.
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
	int len = 0;
	ListNode *h;
public:
	/** @param head The linked list's head.
	Note that the head is guaranteed to be not null, so it contains at least one node. */
	Solution(ListNode* head) {
		ListNode *cur;
		h = head;
		cur = head;
		len = 0;
		while (cur != NULL) {
			len++;
			cur = cur->next;
		}
	}

	/** Returns a random node's value. */
	int getRandom() {
		int tag = rand() % len, result;
		ListNode *cur;
		result = h->val;
		cur = h;
		while (tag != 0) {
			tag--;
			cur = cur->next;
			result = cur->val;
		}
		return result;
	}
};

/**
* Your Solution object will be instantiated and called as such:
* Solution obj = new Solution(head);
* int param_1 = obj.getRandom();
*/

int main()
{
	ListNode *head, *newnode, *cur;
	newnode = new ListNode(1);
	head = newnode;
	cur = head;
	newnode = new ListNode(2);
	cur->next = newnode;
	cur = cur->next;
	newnode = new ListNode(3);
	cur->next = newnode;
	cur = cur->next;
	newnode = new ListNode(4);
	cur->next = newnode;
	cur = cur->next;
	cur = head;
	while (cur != NULL) {
		cout << cur->val << endl;
		cur = cur->next;
	}
	Solution s(head);
	for (int i = 0; i < 20; i++) {
		cout << i << ":" << s.getRandom() << endl;
	}
	system("PAUSE");
	return 0;
}