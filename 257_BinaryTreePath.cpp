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
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {	
private:
	vector<string> result;
	stringstream ss;
	string temp;
public:
	vector<string> binaryTreePaths(TreeNode* root) {
		if (root == NULL)
			return result;
		searchPath(root, "");
		return result;
	}
	void searchPath(TreeNode* now, string CurrentPath) {
		if ((now->left == NULL) && (now->right == NULL)) {
			ss.clear();
			ss << now->val;
			ss >> temp;
			CurrentPath += temp;
			result.push_back(CurrentPath);
			return;
		}
		if (now->left != NULL) {
			ss.clear();
			ss << now->val;
			ss >> temp;
			searchPath(now->left, CurrentPath + temp + "->");
		}
		if (now->right != NULL) {
			ss.clear();
			ss << now->val;
			ss >> temp;
			searchPath(now->right, CurrentPath + temp + "->");
		}
	}
};

int main() {
	Solution s;
	TreeNode *root, *p;
	vector<string> result;
	root = new TreeNode(5);
	p = new TreeNode(4);
	root->left = p;
	p = new TreeNode(8);
	root->right = p;
	p = new TreeNode(11);
	root->left->left = p;
	p = new TreeNode(4);
	root->right->right = p;
	p = new TreeNode(13);
	root->right->left = p;
	p = new TreeNode(7);
	root->left->left->left = p;
	p = new TreeNode(2);
	root->left->left->right = p;
	p = new TreeNode(1);
	root->right->right->right = p;
	result = s.binaryTreePaths(root);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}
	system("PAUSE");
	return 0;
}