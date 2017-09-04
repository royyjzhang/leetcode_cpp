#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int len = nums.size(),result=0;
		for (int i = 0; i < len; i++) {
			result = result^nums[i];
		}
		return result;
	}
};

int main() {
	vector<int> nums = { 1, 2, 3, 4, 5, 4, 3, 2, 1 };
	Solution s;
	cout << s.singleNumber(nums) << endl;
	system("PAUSE");
	return 0;
}