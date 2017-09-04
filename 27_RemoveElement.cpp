#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int len = nums.size(), now = 0;
		for (int i = 0; i < len; i++) {
			if (nums[i] != val) {
				nums[now] = nums[i];
				now++;
			}
		}
		return now;
	}
};

int main() {
	vector<int> nums = { 1, 2, 3, 4, 5, 5, 5, 6, 7, 8 };
	int val = 5;
	Solution s;
	cout << s.removeElement(nums, val) << endl;
	system("PAUSE");
	return 0;
}