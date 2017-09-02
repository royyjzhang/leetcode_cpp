#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<stdlib.h>
#include<queue>
using namespace std;

class Solution {
public:
	int combinationSum4(vector<int>& nums, int target) {
		vector<int> dp(target + 1);
		int i, cur, len;
		len = nums.size();
		if (len == 0) {
			return 0;
		}
		if (target == 0) {
			return 0;
		}
		dp[0] = 1;
		for (cur = 1; cur <= target; cur++) {
			dp[cur] = 0;
			for (i = 0; i < len; i++) {
				if (cur - nums[i] >= 0) {
					dp[cur] += dp[cur - nums[i]];
				}
			}
		}
		return dp[target];
	}
};

int main()
{
	Solution s;
	vector<int> nums = { 1,2,3 };
	int target = 4;
	cout << s.combinationSum4(nums, target) << endl;
	system("PAUSE");
	return 0;
}