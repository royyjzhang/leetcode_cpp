#include<iostream>
#include<vector>
#include<queue>
#include<stdlib.h>
#include<string>
#include<algorithm>
#include<map>
#include<math.h>
#include<stdint.h>
using namespace std;

class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int len = nums.size();
		if (len == 0)
			return 0;
		int result = len*(len + 1) / 2;
		for (int i = 0; i < len; i++) {
			result -= nums[i];
		}
		return result;
	}
};

int main() {
	vector<int> nums = { 0, 1, 3, 4 };
	Solution v;
	cout << v.missingNumber(nums) << endl;
	system("PAUSE");
	return 0;
}