#include<iostream>
#include<vector>
#include<queue>
#include<stdlib.h>
#include<string>
#include<map>
using namespace std;

class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		map<int, int> check;
		map<int, int>::iterator p;
		int len = nums.size();
		if (len == 0)
			return false;
		for (int i = 0; i < len; i++) {
			p = check.find(nums[i]);
			if (p == check.end())
				check.insert(pair<int, int>(nums[i], i));
			else {
				if ((i - p->second) <= k)
					return true;
				p->second = i;
			}
		}
		return false;
	}
};

int main() {
	vector<int> nums = { 1, 1, 1, 2 };
	int k = 2;
	Solution v;
	cout << v.containsNearbyDuplicate(nums,k) << endl;
	system("PAUSE");
	return 0;
}