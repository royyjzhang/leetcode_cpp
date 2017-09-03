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

class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		int slow = 0, fast = 0, finder = 0;
		while (true) {
			slow = nums[slow];
			fast = nums[nums[fast]];
			if (slow == fast)
				break;
		}
		while (true) {
			slow = nums[slow];
			finder = nums[finder];
			if (slow == finder)
				return finder;
		}
	}
};

int main() {
	vector<int> nums = { 2, 2, 1 };
	Solution s;
	cout << s.findDuplicate(nums) << endl;
	system("PAUSE");
	return 0;
}