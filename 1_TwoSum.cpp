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

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> Check;
		vector<int> result;
		int now;
		for (int i = 0; i < nums.size(); i++) {
			now = target - nums[i];
			if (Check.find(now) != Check.end()) {
				result.push_back(Check[now]);
				result.push_back(i);
				break;
			}
			Check[nums[i]] = i;
		}
		return result;
	}
};

int main() {
	Solution s;
	vector<int> result, nums = { 2,7,11,15 };
	int target = 9;
	result = s.twoSum(nums, target);
	cout << result[0] << " " << result[1] << endl;
	system("PAUSE");
	return 0;
}