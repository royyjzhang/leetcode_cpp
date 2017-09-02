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
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> result;
		int i, j, k, l, len = nums.size(), sum;
		for (i = 0; i <= len - 4; i++) {
			if ((i > 0) && (nums[i] == nums[i - 1])) {
				continue;
			}
			if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) {
				break;
			}
			if (nums[i] + nums[len - 3] + nums[len - 2] + nums[len - 1] < target) {
				continue;
			}
			for (j = len - 1; j > i + 2; j--) {
				if ((j < len - 1) && (nums[j] == nums[j + 1])) {
					continue;
				}
				if (nums[i] + nums[j] + nums[i + 1] + nums[i + 2] > target) {
					continue;
				}
				if (nums[i] + nums[j] + nums[j - 1] + nums[j - 2] < target) {
					break;
				}
				k = i + 1;
				l = j - 1;
				while (k < l) {
					sum = nums[i] + nums[j] + nums[k] + nums[l];
					if (sum == target) {
						result.push_back({ nums[i],nums[j],nums[k],nums[l] });
						k++;
						l--;
						while ((k < l) && (nums[k] == nums[k - 1])) {
							k++;
						}
						while ((k < l) && (nums[l] == nums[l + 1])) {
							l--;
						}
					}
					else if (sum < target) {
						k++;
						while ((k < l) && (nums[k] == nums[k - 1])) {
							k++;
						}
					}
					else {
						l--;
						while ((k < l) && (nums[l] == nums[l + 1])) {
							l--;
						}
					}
				}
			}			
		}
		return result;
	}
};

int main() {
	Solution s;
	vector<int> nums = { 1,0,-1,0,-2,2 };
	vector<vector<int>> result;
	int target = 0;
	result = s.fourSum(nums, target);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i][0] << " " << result[i][1] << " " << result[i][2] << " " << result[i][3] << endl;
	}
	system("PAUSE");
	return 0;
}