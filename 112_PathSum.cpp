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

struct TNode {
	int val;
	TreeNode *n;
	TNode *parent;
	TNode(TreeNode* x) : val(0), n(x), parent(NULL){}
};

class Solution {
public:
	bool hasPathSum(TreeNode* root, int sum) {
		if (root == NULL)
			return false;
		TNode *troot, *newt;
		TreeNode *now;
		queue<TNode*> q;
		troot = new TNode(root);
		troot->val = root->val;
		q.push(troot);
		while (!q.empty()) {
			troot = q.front();
			q.pop();
			if (troot->parent != NULL) {
				troot->val = troot->parent->val + troot->n->val;
			}
			if ((troot->n->left == NULL) && (troot->n->right == NULL)) {
				if (troot->val == sum)
					return true;
			}
			if (troot->n->left != NULL) {
				newt = new TNode(troot->n->left);
				newt->parent = troot;
				q.push(newt);
			}
			if (troot->n->right != NULL) {
				newt = new TNode(troot->n->right);
				newt->parent = troot;
				q.push(newt);
			}
		}
		return false;
	}
};

int main() {
	Solution s;
	TreeNode *root, *p;
	int sum = 22;
	root = new TreeNode(5);
	p = new TreeNode(4);
	root->left = p;
	p = new TreeNode(8);
	root->right = p;
	p = new TreeNode(11);
	root->left->left = p;
	p = new TreeNode(4);
	root->right->right = p;
	p = new TreeNode(13);
	root->right->left = p;
	p = new TreeNode(7);
	root->left->left->left = p;
	p = new TreeNode(2);
	root->left->left->right = p;
	p = new TreeNode(1);
	root->right->right->right = p;
	if (s.hasPathSum(root,sum)) {
		cout << "True" << endl;
	}
	else {
		cout << "False" << endl;
	}
	system("PAUSE");
	return 0;
}