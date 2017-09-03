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
		TreeNode *result = root, *tmp;
		if (p->val > q->val) {
			tmp = p;
			p = q;
			q = tmp;
		}
		while (result != NULL) {
			if ((result->val >= p->val) && (result->val <= q->val))
				return result;
			if ((result->val < q->val))
				result = result->right;
			else
				result = result->left;
		}
		return result;
	}
};

int main() {
	TreeNode *root,*ancestor,*a,*b;	
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