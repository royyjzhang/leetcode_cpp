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
	vector<vector<int>> threeSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int i, j, k, len = nums.size();
		vector<vector<int>> result;
		if (len < 3) {
			return result;
		}
		for (i = 0; i <= len - 3; i++) {
			if (((i != 0) && (nums[i] != nums[i - 1])) || (i==0)) {
				j = i + 1;
				k = len - 1;
				while (j < k) {
					if (nums[i] + nums[j] + nums[k] < 0) {
						j++;
					}
					else if (nums[i] + nums[j] + nums[k] == 0) {
						result.push_back({ nums[i],nums[j],nums[k] });
						j++;
						k--;
						while ((j < k) && (nums[j] == nums[j - 1])) {
							j++;
						}
						while ((j < k) && (nums[k] == nums[k + 1])) {
							k++;
						}
					}
					else {
						k--;
					}
				}
			}
		}
		return result;
	}
};

int main() {
	Solution s;
	vector<int> nums = { 0,0,0 };
	vector<vector<int>> result;
	result = s.threeSum(nums);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i][0] << " " << result[i][1] << " " << result[i][2] << endl;
	}
	system("PAUSE");
	return 0;
}