#include<iostream>
#include<vector>
#include<queue>
#include<stdlib.h>
using namespace std;

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
	void connect(TreeLinkNode *root) {
		if (root == NULL)
			return;
		if (root->left != NULL) {
			root->left->next = root->right;
			if (root->next) {
				root->right->next = root->next->left;
			}
		}
		connect(root->left);
		connect(root->right);
	}
};

int main() {
	TreeLinkNode *root, *p;
	root = new TreeLinkNode(1);
	p = new TreeLinkNode(2);
	root->left = p;
	p = new TreeLinkNode(3);
	root->right = p;
	Solution s;
	s.connect(root);
	cout << root->left->next->val << endl;
	system("PAUSE");
	return 0;
}