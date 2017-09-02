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
	vector<int> inorderTraversal(TreeNode* root) {
		stack<pair<TreeNode*,int>> s;
		pair<TreeNode*, int> p;
		vector<int> result;
		if (root == NULL)
			return result;
		s.push(pair<TreeNode*,int>(root,0));
		while (!s.empty()) {
			p = s.top();
			s.pop();
			if (p.second == 0) {
				p.second = 1;
				if (p.first->right != NULL)
					s.push(pair<TreeNode*, int>(p.first->right,0));
				s.push(p);
				if (p.first->left != NULL)
					s.push(pair<TreeNode*, int>(p.first->left,0));
			}
			else
				result.push_back(p.first->val);
		}
		return result;
	}
};

int main() {
	vector<int> result;
	TreeNode *root, *p;
	Solution v;
	root = new TreeNode(1);
	p = new TreeNode(2);
	root->right = p;
	p = new TreeNode(3);
	root->right->left = p;
	result = v.inorderTraversal(root);
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << " ";
	system("PAUSE");
	return 0;
}