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
	int removeDuplicates(vector<int>& nums) {
		int result = 0, privot, now, count, n;
		n = nums.size();
		if (n == 0)
			return result;
		privot = nums[0];
		now = 1;
		result = 1;
		count = 1;
		while (now < n) {
			if (nums[now] != privot) {
				privot = nums[now];
				count = 1;
				nums[result] = nums[now];
				result++;
			}
			else if (count < 2) {
				nums[result] = nums[now];
				result++;
				count++;
			}
			now++;
		}
		return result;
	}
};

int main() {
	Solution solution;
	vector<int> nums = { 1,1,1,2,2,3 };
	int result;
	result = solution.removeDuplicates(nums);
	cout << result << endl;
	for (int i = 0; i < result; i++) {
		cout << nums[i] << " ";
	}
	cout << endl;
	system("PAUSE");
	return 0;
}