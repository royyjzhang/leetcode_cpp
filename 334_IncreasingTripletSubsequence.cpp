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
	bool increasingTriplet(vector<int>& nums) {
		int min1 = INT_MAX, min2 = INT_MAX;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] <= min1) {
				min1 = nums[i];
			}
			else if (nums[i] < min2) {
				min2 = nums[i];
			}
			else if (nums[i] > min2) {
				return true;
			}
		}
		return false;
	}
};

int main() {
	Solution solution;
	vector<int> nums = { 1,2,2,1 };
	if (solution.increasingTriplet(nums)) {
		cout << "True" << endl;
	}
	else {
		cout << "False" << endl;
	}
	system("PAUSE");
	return 0;
}