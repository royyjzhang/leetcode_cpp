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
	int wiggleMaxLength(vector<int>& nums) {
		int n, i, flag = 0, result = 0;
		n = nums.size();
		if (n == 0) {
			return 0;
		}
		if (n == 1) {
			return 1;
		}
		for (i = 1; i < n; i++) {
			if (nums[i] < nums[i - 1]) {
				if ((flag == 0) || (flag == 1)) {
					result++;
					flag = -1;
				}
			}
			else if (nums[i] > nums[i - 1]) {
				if ((flag == 0) || (flag == -1)) {
					result++;
					flag = 1;
				}
			}
		}
		return result + 1;
	}
};

int main() {
	Solution solution;
	vector<int> nums = { 1,7,4,9,2,5 };
	cout << solution.wiggleMaxLength(nums) << endl;
	system("PAUSE");
	return 0;
}