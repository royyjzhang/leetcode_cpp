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
#include<sstream>
#include<unordered_map>
#include<unordered_set>
#include<time.h>
#include<iomanip>
using namespace std;

/**
* Definition for a binary tree node.*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	bool valid(TreeNode *now, TreeNode* &prev) {
		if (now == NULL) {
			return true;
		}
		if (!valid(now->left, prev)) {
			return false;
		}
		if ((prev != NULL) && (prev->val >= now->val)) {
			return false;
		}
		prev = now;
		return valid(now->right, prev);
	}
public:
	bool isValidBST(TreeNode* root) {
		TreeNode *prev = NULL;
		return valid(root, prev);
	}
};

int main() {
	Solution solution;
	TreeNode *root, *p;
	root = new TreeNode(2);
	p = new TreeNode(1);
	root->left = p;
	p = new TreeNode(3);
	root->right = p;
	p = new TreeNode(4);
	root->left->right = p;
	if (solution.isValidBST(root)) {
		cout << "True" << endl;
	}
	else {
		cout << "False" << endl;
	}
	system("PAUSE");
	return 0;
}