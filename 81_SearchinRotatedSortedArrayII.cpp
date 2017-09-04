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
	bool linearsearch(vector<int> &nums, int left, int right, int target) {
		for (int i = left; i < right; i++) {
			if (nums[i] == target)
				return true;
		}
		return false;
	}

	bool search(vector<int>& nums, int target) {
		int mid, left, right;
		if (nums.size() == 0) {
			return false;
		}
		left = 0;
		right = nums.size() - 1;
		while (left <= right) {
			mid = (left + right) >> 1;
			if (nums[mid] == target) {
				return true;
			}
			if ((nums[mid] == nums[left]) && (nums[mid] == nums[right])) {
				return linearsearch(nums, left, right, target);
			}
			else if (nums[mid] == nums[left]) {
				if (linearsearch(nums, left, mid, target)) {
					return true;
				}
				left = mid + 1;
			}
			else if (nums[mid] == nums[right]) {
				if (linearsearch(nums, mid, right, target)) {
					return true;
				}
				right = mid - 1;
			}
			else if (nums[mid] > nums[right]) {
				if ((target >= nums[left]) && (target < nums[mid])) {
					right = mid - 1;
				}
				else {
					left = mid + 1;
				}
			}
			else if (nums[mid] < nums[left]) {
				if ((target > nums[mid]) && (target <= nums[right])) {
					left = mid + 1;
				}
				else {
					right = mid - 1;
				}
			}
			else {
				if (nums[mid] < target) {
					left = mid + 1;
				}
				else {
					right = mid - 1;
				}
			}
		}
		return false;
	}
};

int main() {
	vector<int> nums = { 1,3,5 };
	int target = 1;
	Solution solution;
	if (solution.search(nums, target)) {
		cout << "True" << endl;
	}
	else {
		cout << "False" << endl;
	}
	system("PAUSE");
	return 0;
}