#include<iostream>
#include<vector>
#include<queue>
#include<stdlib.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	TreeNode* sortedListToBST(ListNode* head) {
		TreeNode *root;
		ListNode *first, *second, *tmp;
		if (head == NULL) {
			return NULL;
		}
		if (head->next == NULL) {
			root = new TreeNode(head->val);
			return root;
		}
		first = head;
		second = head;
		tmp = head;
		while ((first != NULL) && (first->next != NULL)) {
			first = first->next->next;
			tmp = second;
			second = second->next;
		}
		root = new TreeNode(second->val);
		tmp->next = NULL;
		if (second!=head)
			root->left = sortedListToBST(head);
		root->right = sortedListToBST(second->next);
		return root;
	}
};

int main() {
	TreeNode *root;
	ListNode *head, *p;
	Solution s;
	head = new ListNode(4);
	p = new ListNode(3);
	p->next = head;
	head = p;
	p = new ListNode(2);
	p->next = head;
	head = p;
	/*p = new ListNode(1);
	p->next = head;
	head = p;*/
	root = s.sortedListToBST(head);
	system("PAUSE");
	return 0;
}