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

class BSTIterator {
private:
	stack<TreeNode*> s;
	bool flag = false;
public:
	BSTIterator(TreeNode *root) {
		TreeNode* now;
		if (root == NULL) {
			flag = false;
		}
		else {
			now = root;
			flag = true;
			while (now != NULL) {
				s.push(now);
				now = now->left;
			}
		}
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return flag;
	}

	/** @return the next smallest number */
	int next() {
		TreeNode *now, *temp;
		now = s.top();
		s.pop();
		if (now->right!= NULL) {
			temp = now->right;
			s.push(temp);
			temp = temp->left;
			while (temp != NULL) {
				s.push(temp);
				temp = temp->left;
			}
		}
		if (s.empty()) {
			flag = false;
		}
		return now->val;
	}
};

/**
* Your BSTIterator will be called like this:
* BSTIterator i = BSTIterator(root);
* while (i.hasNext()) cout << i.next();
*/

int main() {
	vector<int> result;
	TreeNode *root, *p;	
	root = new TreeNode(3);
	p = new TreeNode(5);
	root->right = p;
	p = new TreeNode(6);
	root->right->right = p;
	p = new TreeNode(4);
	root->right->left = p;
	p = new TreeNode(1);
	root->left = p;
	p = new TreeNode(2);
	root->left->right = p;
	BSTIterator v(root);
	while (v.hasNext()) {
		cout << v.next() << endl;
	}
	system("PAUSE");
	return 0;
}