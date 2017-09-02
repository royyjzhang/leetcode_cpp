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
};

int main() {
	TreeNode *root, *p;
	Solution s;
	root = new TreeNode(0);
	p = new TreeNode(1);
	root->left = p;
	p = new TreeNode(2);
	root->right = p;
	p = new TreeNode(3);
	root->left->right = p;
	cout << s.maxDepth(root) << endl;
	system("PAUSE");
	return 0;
}