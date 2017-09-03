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
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == NULL)
			return root;
		if ((root == p) || (root == q))
			return root;
		TreeNode *left, *right;
		left = lowestCommonAncestor(root->left, p, q);
		right = lowestCommonAncestor(root->right, p, q);
		if (left && right)
			return root;
		else if (left)
			return left;
		else
			return right;
	}
};

int main() {
	TreeNode *root, *ancestor, *a, *b;
	Solution s;
	root = new TreeNode(6);
	a = new TreeNode(2);
	root->left = a;
	a = new TreeNode(0);
	root->left->left = a;
	a = new TreeNode(4);
	root->left->right = a;
	a = new TreeNode(3);
	root->left->right->left = a;
	a = new TreeNode(5);
	root->left->right->right = a;
	a = new TreeNode(8);
	root->right = a;
	a = new TreeNode(7);
	root->right->left = a;
	a = new TreeNode(9);
	root->right->right = a;
	a = root->left->right->left;
	b = root->right->right;
	ancestor = s.lowestCommonAncestor(root, a, b);
	cout << ancestor->val << endl;
	system("PAUSE");
	return 0;
}