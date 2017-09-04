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
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int sumNumbers(TreeNode* root) {
		queue<pair<TreeNode*, int>> q;
		int result = 0;
		pair<TreeNode*, int> now, next;
		if (root == NULL) {
			return result;
		}
		now.first = root;
		now.second = root->val;
		q.push(now);
		while (!q.empty()) {
			now = q.front();
			q.pop();
			if ((now.first->left == NULL) && (now.first->right == NULL)) {
				result += now.second;
			}
			else {
				if (now.first->left != NULL) {
					next.first = now.first->left;
					next.second = now.second * 10 + now.first->left->val;
					q.push(next);
				}
				if (now.first->right != NULL) {
					next.first = now.first->right;
					next.second = now.second * 10 + now.first->right->val;
					q.push(next);
				}
			}
		}
		return result;
	}
};

int main() {
	Solution solution;
	TreeNode *root, *p;
	root = new TreeNode(1);
	p = new TreeNode(2);
	root->left = p;
	p = new TreeNode(3);
	root->right = p;
	cout << solution.sumNumbers(root) << endl;
	system("PAUSE");
	return 0;
}