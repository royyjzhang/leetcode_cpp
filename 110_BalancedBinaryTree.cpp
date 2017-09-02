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
	int max(int a, int b) {
		if (a > b)
			return a;
		else
			return b;
	}
	int maxDepth(TreeNode* root) {
		if (root == NULL)
			return 0;
		else
			return max(maxDepth(root->left), maxDepth(root->right)) + 1;
	}
	bool isBalanced(TreeNode* root) {
		if (root == NULL)
			return true;
		if ((isBalanced(root->left)) && (isBalanced(root->right)) && (abs(maxDepth(root->left) - maxDepth(root->right)) < 2))
			return true;
		else
			return false;
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
	if (s.isBalanced(root))
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	system("PAUSE");
	return 0;
}