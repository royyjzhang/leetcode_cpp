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

struct cmp {
	bool operator() ( int a, int b ) {
		return a > b;
	}
};

class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		int n = nums.size(), i;
		priority_queue<int, vector<int>, cmp> queue;
		for (i = 0; i < k; i++) {
			queue.push(nums[i]);
		}
		for (i = k; i < nums.size(); i++) {
			if (queue.top() < nums[i]) {
				queue.pop();
				queue.push(nums[i]);
			}
		}
		return queue.top();
	}
};

int main() {
	Solution solution;
	vector<int> nums = { 3,2,1,5,6,4 };
	cout << solution.findKthLargest(nums, 2) << endl;
	system("PAUSE");
	return 0;
}