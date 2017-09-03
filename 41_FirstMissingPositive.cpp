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
	int firstMissingPositive(vector<int>& nums) {
		int len = nums.size(), tmp, j=1;
		for (int i = 0; i < len; i++) {
			while ((nums[i]>0) && (nums[i] < len+1) && (nums[nums[i]-1] != nums[i])) {
				tmp = nums[i];
				nums[i] = nums[nums[i]-1];
				nums[tmp-1] = tmp;
			}
		}
		while ((j < len + 1) && (nums[j - 1] == j))
			j++;
		return j;
	}
};

int main() {
	vector<int> nums = { 3, 4, -1, 1 };
	Solution v;
	cout << v.firstMissingPositive(nums) << endl;
	system("PAUSE");
	return 0;
}