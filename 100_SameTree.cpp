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
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if ((p == NULL) && (q == NULL))
			return true;
		else if ((p == NULL) || (q == NULL))
			return false;
		if ((p->val == q->val) && (isSameTree(p->left, q->left)) && (isSameTree(p->right, q->right)))
			return true;
		else
			return false;
	}
};

int main() {
	TreeNode *root, *p, *root2;
	Solution s;
	root = new TreeNode(1);
	p = new TreeNode(2);
	root->right = p;
	p = new TreeNode(3);
	root->right->right = p;
	root2 = root;
	if (s.isSameTree(root, root2))
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	system("PAUSE");
	return 0;
}