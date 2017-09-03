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
* Definition for a binary tree node.*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	void flatten(TreeNode* root) {
		TreeNode *now, *temp;
		now = root;
		while (now != NULL) {
			if (now->left != NULL) {
				temp = now->left;
				while (temp->right != NULL) {
					temp = temp->right;
				}
				temp->right = now->right;
				now->right = now->left;
				now->left = NULL;
			}
			now = now->right;
		}
	}
};

int main() {
	Solution solution;
	TreeNode *root, *p;
	root = new TreeNode(1);
	p = new TreeNode(2);
	root->left = p;
	p = new TreeNode(3);
	root->left->left = p;
	p = new TreeNode(4);
	root->left->right = p;
	p = new TreeNode(5);
	root->right = p;
	p = new TreeNode(6);
	root->right->right = p;
	solution.flatten(root);
	p = root;
	while (p != NULL) {
		cout << p->val << " ";
		p = p->right;
	}
	cout << endl;
	system("PAUSE");
	return 0;
}