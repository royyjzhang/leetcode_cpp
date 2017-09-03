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
#include<iomanip>
using namespace std;

/**
* Definition for singly-linked list.*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct cmp {
	bool operator()(ListNode* a, ListNode* b) {
		return a->val > b->val;
	}
};
class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode *result, *p, *now;
		priority_queue<ListNode*, vector<ListNode*>, cmp> heap;
		if (lists.size() == 0) {
			return NULL;
		}
		if (lists.size() == 1) {
			return lists[0];
		}
		for (int i = 0; i < lists.size(); i++) {
			if (lists[i] != NULL) {
				heap.push(lists[i]);
			}
		}
		result = NULL;
		p = NULL;
		while (!heap.empty()) {
			now = heap.top();
			heap.pop();
			if (now->next != NULL) {
				heap.push(now->next);
			}
			if (result == NULL) {
				result = now;
				p = now;
			}
			else {
				p->next = now;
				p = p->next;
			}
		}
		return result;
	}
};

int main() {
	Solution solution;
	vector<ListNode*> list;
	ListNode *head, *p, *result;
	head = new ListNode(1);
	p = new ListNode(2);
	head->next = p;
	p = new ListNode(4);
	head->next->next = p;
	list.push_back(head);
	head = new ListNode(3);
	p = new ListNode(5);
	head->next = p;
	p = new ListNode(7);
	head->next->next = p;
	list.push_back(head);
	head = new ListNode(6);
	p = new ListNode(8);
	head->next = p;
	p = new ListNode(9);
	head->next->next = p;
	list.push_back(head);
	result = solution.mergeKLists(list);
	while (result != NULL) {
		cout << result->val << " ";
		result = result->next;
	}
	cout << endl;
	system("PAUSE");
	return 0;
}