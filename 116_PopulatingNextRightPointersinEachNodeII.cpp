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
		TreeLinkNode *parent = root, *current, *first;
		while (parent != NULL) {
			if ((parent->left == NULL) && (parent->right == NULL)) {
				parent = parent->next;
			}
			else {
				if (parent->left != NULL)
					current = parent->left;
				else
					current = parent->right;
				first = current;
				while (parent != NULL) {
					if ((parent->right != NULL) && (parent->right != current)) {
						current->next = parent->right;
						current = current->next;
					}
					parent = parent->next;
					if (parent!=NULL) {
						if (parent->left != NULL) {
							current->next = parent->left;
							current = current->next;
						}
					}
				}
				parent = first;
			}
		}
		return;
	}
};

int main() {
	TreeLinkNode *root, *p;
	root = new TreeLinkNode(2);
	p = new TreeLinkNode(1);
	root->left = p;
	p = new TreeLinkNode(3);
	root->right = p;
	p = new TreeLinkNode(0);
	root->left->left = p;
	p = new TreeLinkNode(7);
	root->left->right = p;
	p = new TreeLinkNode(9);
	root->right->left = p;
	p = new TreeLinkNode(7);
	root->right->right = p;
	p = new TreeLinkNode(2);
	root->left->left->left = p;
	p = new TreeLinkNode(1);
	root->left->right->left = p;
	p = new TreeLinkNode(0);
	root->left->right->right = p;
	p = new TreeLinkNode(8);
	root->right->right->left = p;
	p = new TreeLinkNode(8);
	root->right->right->right = p;
	p = new TreeLinkNode(7);
	root->left->right->left->left = p;
	Solution s;
	s.connect(root);
	//cout << root->left->right->next->val << endl;
	system("PAUSE");
	return 0;
}