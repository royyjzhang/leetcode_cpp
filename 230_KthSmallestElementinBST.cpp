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
	int kthSmallest(TreeNode* root, int k) {
		if (root == NULL)
			return INT_MAX;
		stack<TreeNode*> s;
		TreeNode *now=root;
		while ((!s.empty()) || (now != NULL)) {
			while (now != NULL) {
				s.push(now);
				now = now->left;
			}
			now = s.top();
			k--;
			if (k == 0)
				return now->val;
			s.pop();
			now = now->right;
		}
		return INT_MIN;
	}
};

int main() {
	int result,k=2;
	vector<int> line;
	TreeNode *root, *p;
	Solution v;
	root = new TreeNode(3);
	p = new TreeNode(1);
	root->left = p;
	p = new TreeNode(5);
	root->right = p;
	p = new TreeNode(2);
	root->left->right = p;
	p = new TreeNode(6);
	root->right->right = p;
	result = v.kthSmallest(root,k);
	cout << result << endl;
	system("PAUSE");
	return 0;
}