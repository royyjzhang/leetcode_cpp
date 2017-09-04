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
using namespace std;

class Solution {
private:
	vector<vector<int>> result;
	vector<int> line;
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		int n = nums.size();
		if (n == 0) {
			result.push_back(line);
			return result;
		}
		sort(nums.begin(), nums.end());
		search(nums, 0);
		return result;
	}
	void search(vector<int>& nums, int index) {
		if (find(result.begin(), result.end(), line) == result.end()) {
			result.push_back(line);
		}
		for (int i = index; i < nums.size(); i++) {
			line.push_back(nums[i]);
			search(nums, i + 1);
			line.pop_back();
		}
	}
};

int main() {
	Solution solution;
	vector<int> nums = { 1,2,2 };
	vector<vector<int>> result;
	result = solution.subsetsWithDup(nums);
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	system("PAUSE");
	return 0;
}