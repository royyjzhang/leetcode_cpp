#include<iostream>
#include<vector>
#include<queue>
#include<stdlib.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> result;
		vector<int> nowlevel;
		queue<TreeNode*> q;
		queue<int> l;
		TreeNode* now;
		int nlevel,lastlevel=0;
		if (root == NULL)
			return result;
		q.push(root);
		l.push(0);
		while (!q.empty()) {
			nlevel = l.front();
			now = q.front();
			l.pop();
			q.pop();
			if (nlevel != lastlevel) {
				result.push_back(nowlevel);
				nowlevel.clear();
			}
			nowlevel.push_back(now->val);
			if (now->left != NULL) {
				q.push(now->left);
				l.push(nlevel + 1);
			}
			if (now->right != NULL) {
				q.push(now->right);
				l.push(nlevel + 1);
			}
			lastlevel = nlevel;
		}
		result.push_back(nowlevel);
		nowlevel.clear();
		return result;
	}
};

int main() {
	TreeNode *root, *p;
	Solution s;
	root = new TreeNode(0);
	p = new TreeNode(1);
	root->left = p;
	p = new TreeNode(2);
	root->right = p;
	p = new TreeNode(3);
	root->left->right = p;
	vector<vector<int>> result; 
	vector<int> line;
	result = s.levelOrder(root);
	for (int i = 0; i < result.size(); i++) {
		line = result[i];
		for (int j = 0; j < line.size(); j++) {
			cout << line[j] << ' ';
		}
		cout << endl;
	}
	system("PAUSE");
	return 0;
}