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
	int findMin(vector<int>& nums) {
		int i = 0, left, right, len=nums.size();
		while (i<len/2) {
			left = i * 2 + 1;
			right = i * 2 + 2;
			if ((left<len) && (nums[i]>nums[left]))
				return nums[left];
			if ((right<len) && (nums[i]>nums[right]))
				return nums[right];
			i++;
		}
		return nums[0];
	}
};

int main() {
	vector<int> nums = { 4, 4, 4, 4, 0, 1, 2, 3 };
	Solution s;
	cout << s.findMin(nums) << endl;
	system("PAUSE");
	return 0;
}