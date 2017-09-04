#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		vector<int> result(2, 0);
		int r = 0, different;
		for (int i = 0; i < nums.size(); i++) {
			r = r^nums[i];
		}
		different = r & (~(r - 1));
		for (int i = 0; i < nums.size(); i++) {
			if ((different & nums[i]) != 0) {
				result[0] = result[0] ^ nums[i];
			}
			else
				result[1] = result[1] ^ nums[i];
		}
		return result;
	}
};

int main() {
	vector<int> nums = { 1, 1, 4, 2, 2, 5, 3, 3 };
	Solution s;
	cout << s.singleNumber(nums)[0] << s.singleNumber(nums)[1] << endl;
	system("PAUSE");
	return 0;
}