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
#include<thread>
#include<mutex>
#include<Windows.h>
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
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		if ((inorder.size() == 0) || (postorder.size() == 0)) {
			return NULL;
		}
		else {
			return buildRoot(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
		}
	}
	TreeNode *buildRoot(vector<int> &inorder, int inorderStart, int inorderEnd, vector<int> &postorder, int postStart, int postEnd) {
		if (inorderStart > inorderEnd) {
			return NULL;
		}
		TreeNode *root = new TreeNode(postorder[postEnd]);
		int i;
		for (i = inorderStart; i <= inorderEnd; i++) {
			if (inorder[i] == root->val)
				break;
		}
		root->left = buildRoot(inorder, inorderStart, i - 1, postorder, postStart, postStart + (i - inorderStart) - 1);
		root->right= buildRoot(inorder, i + 1, inorderEnd, postorder, postStart + (i - inorderStart), postEnd - 1);
		return root;
	}
};

void printTree(TreeNode *root) {
	if (root == NULL) {
		return;
	}
	cout << root->val << " ";
	printTree(root->left);
	printTree(root->right);
}

int main() {
	Solution solution;
	vector<int> inorder = { 2,3,1,5,4 }, postorder = { 3,2,4,5,1 };
	TreeNode *root;
	root = solution.buildTree(inorder, postorder);
	printTree(root);
	system("PAUSE");
	return 0;
}