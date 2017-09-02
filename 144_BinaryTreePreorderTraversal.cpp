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
	vector<int> preorderTraversal(TreeNode* root) {
		stack<TreeNode*> s;
		TreeNode *p;
		vector<int> result;
		if (root == NULL)
			return result;
		s.push(root);
		while (!s.empty()) {
			p = s.top();
			s.pop();
			result.push_back(p->val);
			if (p->right != NULL)
				s.push(p->right);
			if (p->left != NULL)
				s.push(p->left);

		}
		return result;
	}
};

int main() {
	vector<int> result;
	TreeNode *root,*p;
	Solution v;
	root = new TreeNode(1);
	p = new TreeNode(2);
	root->right = p;
	p = new TreeNode(3);
	root->right->left = p;
	result = v.preorderTraversal(root);
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << " ";
	system("PAUSE");
	return 0;
}