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
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		queue<pair<TreeNode*, int>> s;
		pair<TreeNode*, int> p;
		vector<vector<int>> result;
		vector<int> level;
		int nowlevel = 0;
		if (root == NULL)
			return result;
		s.push(pair<TreeNode*, int>(root, 0));
		while (!s.empty()) {
			p = s.front();
			s.pop();
			if (nowlevel != p.second) {
				result.push_back(level);
				level.clear();
				level.push_back(p.first->val);
				nowlevel = p.second;
			}
			else {
				level.push_back(p.first->val);
			}
			if (p.first->left != NULL)
				s.push(pair<TreeNode*, int>(p.first->left, nowlevel + 1));
			if (p.first->right != NULL)
				s.push(pair<TreeNode*, int>(p.first->right, nowlevel + 1));			
		}
		result.push_back(level);
		int len = result.size(),llen, tmp;
		for (int i = 1; i < len; i = i + 2) {
			level = result[i];
			llen = level.size();
			for (int j = 0; j < llen / 2; j++) {
				tmp = level[j];
				level[j] = level[llen - j - 1];
				level[llen - j - 1] = tmp;
			}
			result[i] = level;
		}
		return result;
	}
};

int main() {
	vector<vector<int>> result;
	vector<int> line;
	TreeNode *root, *p;
	Solution v;
	root = new TreeNode(1);
	p = new TreeNode(2);
	root->left = p;
	p = new TreeNode(3);
	root->right = p;
	p = new TreeNode(4);
	root->right->left = p;
	p = new TreeNode(5);
	root->right->right = p;
	result = v.zigzagLevelOrder(root);
	for (int i = 0; i < result.size(); i++) {
		line = result[i];
		for (int j = 0; j < line.size(); j++) {
			cout << line[j] << " ";
		}
		cout << endl;
	}
	system("PAUSE");
	return 0;
}