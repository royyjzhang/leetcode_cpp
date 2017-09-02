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
	int min(int a, int b) {
		if (a > b)
			return b;
		else
			return a;
	}
	int minDepth(TreeNode* root) {
		if (root == NULL)
			return 0;
		else if (root->left == NULL)
			return minDepth(root->right) + 1;
		else if (root->right == NULL)
			return minDepth(root->left) + 1;
		else
			return min(minDepth(root->left), minDepth(root->right)) + 1;
	}
};

int main() {
	TreeNode *root, *p;
	Solution s;
	root = new TreeNode(0);
	p = new TreeNode(1);
	root->left = p;
	/*p = new TreeNode(2);
	root->right = p;
	p = new TreeNode(3);
	root->left->right = p;*/
	cout << s.minDepth(root) << endl;
	system("PAUSE");
	return 0;
}