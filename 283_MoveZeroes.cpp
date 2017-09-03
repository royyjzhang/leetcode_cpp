#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int len = nums.size(), now = 0;
		for (int i = 0; i < len; i++) {
			if (nums[i] != 0) {
				nums[now] = nums[i];
				now++;
			}
		}
		for (int i = now; i < len; i++) {
			nums[i] = 0;
		}
	}
};

int main() {
	vector<int> nums = { 0, 1, 0, 3, 12 };
	Solution s;
	s.moveZeroes(nums);
	for (int i = 0; i < nums.size(); i++) {
		cout << nums[i] << endl;
	}
	system("PAUSE");
	return 0;
}