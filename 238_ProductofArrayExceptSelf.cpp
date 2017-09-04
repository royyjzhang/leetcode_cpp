#include<iostream>
#include<vector>
#include<queue>
#include<stdlib.h>
using namespace std;

class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		int len = nums.size();
		vector<int> forward(len, 1), backward(len, 1), result(len, 0);
		int f = 1, b = 1;
		for (int i = 1; i < len; i++) {
			f = f*nums[i - 1];
			forward[i] = f;
			b = b*nums[len - i];
			backward[i] = b;
		}
		for (int i = 0; i < len; i++) {
			result[i] = forward[i] * backward[len - i - 1];
		}
		return result;
	}
};

int main() {
	vector<int> nums = { 1, 2, 3, 4 }, result;
	Solution s;
	result = s.productExceptSelf(nums);
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << endl;
	system("PAUSE");
	return 0;
}