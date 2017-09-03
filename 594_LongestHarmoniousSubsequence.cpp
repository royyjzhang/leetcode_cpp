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
#include<unordered_set>
#include<time.h>
#include<iomanip>
using namespace std;

class Solution {
public:
	int findLHS(vector<int>& nums) {
		unordered_map<int, int> nums_map;
		int result = 0, now;
		for (int i = 0; i < nums.size(); i++) {
			if (nums_map.find(nums[i]) == nums_map.end()) {
				nums_map.insert(pair<int, int>(nums[i], 1));
			}
			else {
				nums_map[nums[i]]++;
			}
		}
		for (unordered_map<int, int>::iterator it = nums_map.begin(); it != nums_map.end(); ++it) {
			now = 0;
			if (nums_map.find(it->first + 1) != nums_map.end()) {
				now = it->second + nums_map[it->first + 1];
			}
			if (now > result) {
				result = now;
			}
		}
		return result;
	}
};

int main() {
	Solution solution;
	vector<int> nums = { 1, 3, 2, 2, 5, 2, 3, 7 };
	cout << solution.findLHS(nums) << endl;
	system("PAUSE");
	return 0;
}