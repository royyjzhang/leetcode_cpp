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
* Definition for a binary tree node. */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isSubtree(TreeNode* s, TreeNode* t) {
		if (t == NULL)
			return true;
		if (s != NULL)
			return (same(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t));
		else
			return false;
	}
private:
	bool same(TreeNode* s, TreeNode* t) {
		if ((s == NULL) && (t == NULL)) {
			return true;
		}
		if ((s != NULL) && (t != NULL) && (s->val == t->val) && (same(s->left, t->left)) && (same(s->right, t->right))) {
			return true;
		}
		return false;
	}
};

int main() {
	Solution solution;
	TreeNode *s, *t, *p;
	s = new TreeNode(3);
	t = new TreeNode(4);
	p = new TreeNode(4);
	s->left = p;
	p = new TreeNode(1);
	s->left->left = p;
	p = new TreeNode(2);
	s->left->right = p;
	p = new TreeNode(5);
	s->right = p;
	p = new TreeNode(1);
	t->left = p;
	p = new TreeNode(2);
	t->right = p;
	p = new TreeNode(0);
	t->left->right = p;
	if (solution.isSubtree(s, t)) {
		cout << "True" << endl;
	}
	else {
		cout << "False" << endl;
	}
	system("PAUSE");
	return 0;
}