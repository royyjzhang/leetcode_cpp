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
	vector<TreeNode*> generateBST(int i, int j) {
		vector<TreeNode*> result;
		if (i == j) {
			result.push_back(new TreeNode(i));
			return result;
		}
		for (int k = i; k <= j; k++) {
			vector<TreeNode*> ltree, rtree;
			if (k == i)
				ltree.push_back(NULL);
			else
				ltree = generateBST(i, k - 1);
			if (k == j)
				rtree.push_back(NULL);
			else
				rtree = generateBST(k + 1, j);
			for (int li = 0; li < ltree.size(); li++) {
				for (int ri = 0; ri < rtree.size(); ri++) {
					TreeNode *root = new TreeNode(k);
					root->left = ltree[li];
					root->right = rtree[ri];
					result.push_back(root);
				}
			}
		}
		return result;
	}
	vector<TreeNode*> generateTrees(int n) {
		return generateBST(1, n);
	}
};

int main() {
	vector<TreeNode*> result;
	int n = 3;
	Solution s;
	result = s.generateTrees(n);
	for (int i = 0; i < result.size(); i++)
		cout << result[i]->val << endl;
	system("PAUSE");
	return 0;
}