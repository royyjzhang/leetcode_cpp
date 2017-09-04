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
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		queue<TreeNode*> q;
		TreeNode *node1, *node2;
		if (root == NULL) {
			return true;
		}
		q.push(root->left);
		q.push(root->right);
		while (!q.empty()) {
			node1 = q.front();
			q.pop();
			node2 = q.front();
			q.pop();
			if ((node1 != NULL) && (node2 != NULL)) {
				if (node1->val != node2->val) {
					return false;
				}
				else {
					q.push(node1->left);
					q.push(node2->right);
					q.push(node1->right);
					q.push(node2->left);
				}
			}
			else if ((node1 == NULL) || (node2 == NULL)) {
				if (!((node1 == NULL) && (node2 == NULL))) {
					return false;
				}
			}
		}
		return true;
	}
};

int main() {
	Solution s;
	TreeNode *root, *p;
	root = new TreeNode(1);
	p = new TreeNode(2);
	root->left = p;
	p = new TreeNode(2);
	root->right = p;
	p = new TreeNode(4);
	root->left->right = p;
	p = new TreeNode(3);
	root->right->right = p;
	p = new TreeNode(4);
	root->right->left = p;
	p = new TreeNode(3);
	root->left->left = p;
	if (s.isSymmetric(root)) {
		cout << "True" << endl;
	}
	else {
		cout << "False" << endl;
	}
	system("PAUSE");
	return 0;
}