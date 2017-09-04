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
	int removeDuplicates(vector<int>& nums) {
		int result = 0, now;
		if (nums.size() == 0) {
			return result;
		}
		else {
			now = nums[0];
			result++;
			for (int i = 1; i < nums.size(); i++) {
				if (now != nums[i]) {
					nums[result] = nums[i];
					result++;
					now = nums[i];
				}
			}
			return result;
		}
	}
};

int main() {
	Solution s;
	vector<int> nums = { 1,1,2 };
	int result;
	result = s.removeDuplicates(nums);
	cout << result << endl;
	for (int i = 0; i < result; i++) {
		cout << nums[i] << " ";
	}
	cout << endl;
	system("PAUSE");
	return 0;
}