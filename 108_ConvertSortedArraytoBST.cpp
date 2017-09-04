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
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		int len = nums.size();
		int mid;
		TreeNode *root;
		vector<int> tmp;
		if (len == 0) {
			return NULL;
		}
		if (len == 1) {
			root = new TreeNode(nums[0]);
			return root;
		}
		mid = (len - 1) / 2;
		root = new TreeNode(nums[mid]);
		for (int i = 0; i < mid; i++)
			tmp.push_back(nums[i]);
		root->left = sortedArrayToBST(tmp);
		tmp.clear();
		for (int i = mid+1; i < len; i++)
			tmp.push_back(nums[i]);
		root->right = sortedArrayToBST(tmp);
		return root;
	}
};

int main() {
	TreeNode *root;
	vector<int> nums = { 1, 2, 3, 4 };
	Solution s;	
	root = s.sortedArrayToBST(nums);
	system("PAUSE");
	return 0;
}