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

struct node {
	TreeNode* t;
	int level;
};

class Solution {
public:
	vector<int> rightSideView(TreeNode* root) {
		queue<node> q;
		vector<int> result;
		int currentlevel = 1;
		node temp, now, prev;
		if (root == NULL)
			return result;
		temp.t = root;
		temp.level = 1;
		q.push(temp);
		while (!q.empty()) {
			now = q.front();
			q.pop();
			if (now.level > currentlevel) {
				result.push_back(prev.t->val);
				currentlevel = now.level;
			}
			if (now.t->left != NULL) {
				temp.t = now.t->left;
				temp.level = now.level + 1;
				q.push(temp);
			}
			if (now.t->right != NULL) {
				temp.t = now.t->right;
				temp.level = now.level + 1;
				q.push(temp);
			}
			prev = now;
		}
		result.push_back(prev.t->val);
		return result;
	}
};

int main() {
	vector<int> line;
	TreeNode *root, *p;
	Solution v;
	root = new TreeNode(1);
	p = new TreeNode(2);
	root->left = p;
	p = new TreeNode(3);
	root->right = p;
	p = new TreeNode(4);
	root->right->right = p;
	p = new TreeNode(5);
	root->left->right = p;
	line = v.rightSideView(root);
	for (int i = 0; i < line.size(); i++) {
		cout << line[i] << " ";
	}
	cout << endl;
	system("PAUSE");
	return 0;
}