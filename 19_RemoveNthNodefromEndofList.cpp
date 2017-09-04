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
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode *prev, *pointer, *result, *now;
		int count = 0;
		if (head == NULL) {
			return head;
		}
		if (n == 0) {
			return head;
		}
		pointer = head;
		while (count < n) {
			pointer = pointer->next;
			count++;
		}
		if (pointer == NULL) {
			result = head->next;
			return result;
		}
		else {
			result = head;
			now = head;
			prev = head;
			while (pointer != NULL) {
				prev = now;
				now = now->next;
				pointer = pointer->next;				
			}
			prev->next = prev->next->next;
			return result;
		}
	}
};

int main() {
	Solution s;
	ListNode *head, *temp, *result;
	head = new ListNode(1);
	temp = new ListNode(2);
	head->next = temp;
	temp = new ListNode(3);
	head->next->next = temp;
	temp = new ListNode(4);
	head->next->next->next = temp;
	temp = new ListNode(5);
	head->next->next->next->next = temp;
	result = s.removeNthFromEnd(head, 2);
	temp = result;
	while (temp != NULL) {
		cout << temp->val << " ";
		temp = temp->next;
	}
	cout << endl;
	system("PAUSE");
	return 0;
}