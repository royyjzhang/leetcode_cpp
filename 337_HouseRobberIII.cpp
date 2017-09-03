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
	int rob(TreeNode* root) {
		if (root == NULL)
			return 0;
		return robmoney(root);
	}
	int robmoney(TreeNode* node) {
		if (node == NULL)
			return 0;
		int moneyrobnode = 0, moneynotrobnode = 0;
		moneyrobnode += node->val;
		if (node->left != NULL) {
			moneyrobnode += robmoney(node->left->left);
			moneyrobnode += robmoney(node->left->right);
			moneynotrobnode += robmoney(node->left);
		}
		if (node->right != NULL) {
			moneyrobnode += robmoney(node->right->left);
			moneyrobnode += robmoney(node->right->right);
			moneynotrobnode += robmoney(node->right);
		}
		if (moneynotrobnode > moneyrobnode)
			return moneynotrobnode;
		else
			return moneyrobnode;
	}
};

int main() {
	int result;
	vector<int> line;
	TreeNode *root, *p;
	Solution v;
	root = new TreeNode(3);
	p = new TreeNode(2);
	root->left = p;
	p = new TreeNode(3);
	root->right = p;
	p = new TreeNode(3);
	root->left->right = p;
	p = new TreeNode(1);
	root->right->right = p;
	result = v.rob(root);
	cout << result << endl;
	system("PAUSE");
	return 0;
}