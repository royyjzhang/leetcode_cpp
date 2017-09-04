#include<iostream>
#include<vector>
#include<queue>
#include<stdlib.h>
using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int l = nums.size();
		if (l == 0)
			return 0;
		for (int i = 0; i < l; i++) {
			if (nums[i]>target)
				return i;
			if (nums[i] == target)
				return i;
		}
		return l;
	}
};

int main() {
	vector<int> num = { 1, 3, 5, 6 };
	int target = 7;
	Solution s;
	cout << s.searchInsert(num,target) << endl;
	system("PAUSE");
	return 0;
}