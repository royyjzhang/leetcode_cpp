#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (root == NULL)
			return root;
		TreeNode *tmp;
		tmp = root->left;
		root->left = root->right;
		root->right = tmp;
		invertTree(root->left);
		invertTree(root->right);
		return root;
	}
};

int main() {
	TreeNode *root, *p;
	Solution s;
	root = new TreeNode(1);
	p = new TreeNode(2);
	root->right = p;
	p = new TreeNode(3);
	root->right->right = p;
	root = s.invertTree(root);
	system("PAUSE");
	return 0;
}