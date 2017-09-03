#include<iostream>
#include<vector>
#include<queue>
#include<stdlib.h>
using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int len = nums.size(), i, max;
		if (len == 0)
			return 0;
		vector<int> dp(len+1, 0);
		for (i = 1; i <= len; i++) {
			if (nums[i - 1] + dp[i - 1] < nums[i - 1])
				dp[i] = nums[i - 1];
			else
				dp[i] = nums[i - 1] + dp[i - 1];
		}
		max = dp[1];
		for (i = 1; i <= len; i++) {
			if (dp[i] > max)
				max = dp[i];
		}
		return max;
	}
};

int main() {
	Solution s;
	vector<int> nums = { -2 };
	cout << s.maxSubArray(nums) << endl;
	system("PAUSE");
	return 0;
}