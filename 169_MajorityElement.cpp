#include<iostream>
#include<vector>
#include<queue>
#include<stdlib.h>
#include<string>
#include<map>
using namespace std;

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		map<int, int> check;
		map<int, int>::iterator p;
		int len = nums.size();
		for (int i = 0; i < len; i++) {
			p = check.find(nums[i]);
			if (p == check.end()) {
				check.insert(pair<int, int>(nums[i], 1));
			}
			else {
				p->second++;
			}
		}
		for (p=check.begin(); p != check.end(); p++) {
			if (p->second>(len / 2))
				return p->first;
		}
	}
};

int main() {
	vector<int> nums = { 1, 1, 1, 2 };
	Solution v;
	cout << v.majorityElement(nums) << endl;
	system("PAUSE");
	return 0;
}