#include<iostream>
#include<vector>
#include<queue>
#include<stdlib.h>
using namespace std;

class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int len = nums.size(), i, max;
		if (len == 0)
			return 0;
		vector<int> maxone(len + 1, 1), minone(len + 1, 1);
		for (i = 1; i <= len; i++) {
			if (nums[i - 1] > 0) {
				if (nums[i - 1] < maxone[i - 1] * nums[i - 1]) {
					maxone[i] = maxone[i - 1] * nums[i - 1];
				}
				else {
					maxone[i] = nums[i - 1];
				}
				if (nums[i - 1] < minone[i - 1] * nums[i - 1]) {
					minone[i] = nums[i - 1];
				}
				else {
					minone[i] = minone[i - 1] * nums[i - 1];
				}
			}
			else {
				if (nums[i - 1] > maxone[i - 1] * nums[i - 1]) {
					minone[i] = maxone[i - 1] * nums[i - 1];
				}
				else {
					minone[i] = nums[i - 1];
				}
				if (nums[i - 1] > minone[i - 1] * nums[i - 1]) {
					maxone[i] = nums[i - 1];
				}
				else {
					maxone[i] = minone[i - 1] * nums[i - 1];
				}
			}
		}
		max = maxone[1];
		for (i = 1; i <= len; i++) {
			if (maxone[i]>max)
				max = maxone[i];
		}
		return max;
	}
};

int main() {
	Solution s;
	vector<int> nums = { -4, -3 };
	cout << s.maxProduct(nums) << endl;
	system("PAUSE");
	return 0;
}