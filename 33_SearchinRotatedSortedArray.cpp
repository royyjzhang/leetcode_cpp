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
#include<unordered_set>
#include<time.h>
using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int left, right, mid;
		if (nums.size() == 0) {
			return -1;
		}
		left = 0;
		right = nums.size() - 1;
		while (left<=right) {
			mid = (left + right) >> 1;
			if (nums[mid] == target)
				return mid;
			else if (nums[mid] >= nums[left]) {
				if ((target >= nums[left]) && (target < nums[mid])) {
					right = mid - 1;
				}
				else {
					left = mid + 1;
				}
			}
			else {
				if ((target > nums[mid]) && (target <= nums[right])) {
					left = mid + 1;
				}
				else {
					right = mid - 1;
				}
			}
		}
		return -1;
	}
};

int main() {
	vector<int> nums = { 1,3,5 };
	int target = 1;
	Solution solution;
	cout << solution.search(nums, target) << endl;
	system("PAUSE");
	return 0;
}