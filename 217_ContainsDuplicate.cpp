#include<iostream>
#include<vector>
#include<queue>
#include<stdlib.h>
#include<string>
#include<set>
using namespace std;

class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		set<int> check;
		int len = nums.size();
		for (int i = 0; i < len; i++) {
			check.insert(nums[i]);
		}
		return len != check.size();
	}
};

int main() {
	vector<int> nums = { 1, 2, 3, 4, 5 };
	Solution v;
	cout << v.containsDuplicate(nums) << endl;
	system("PAUSE");
	return 0;
}