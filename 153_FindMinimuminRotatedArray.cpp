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
		int start = 0, end = nums.size() - 1, mid;
		while (end > start) {
			mid = start + (end - start) / 2;
			if (nums[mid] < nums[end])
				end = mid;
			else
				start = mid + 1;
		}
		return nums[start];
	}
};

int main() {
	vector<int> nums = { 4, 5, 6, 7, 0, 1, 2, 3 };
	Solution s;
	cout << s.findMin(nums) << endl;
	system("PAUSE");
	return 0;
}