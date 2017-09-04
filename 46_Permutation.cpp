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
#include<set>
#include<algorithm>
using namespace std;

class Solution {
private:
	vector<vector<int>> result;
	void search(vector<int>& nums, int current) {
		if (current == nums.size()) {
			result.push_back(nums);
			return;
		}
		for (int i = current; i < nums.size(); i++) {
			int temp;
			temp = nums[current];
			nums[current] = nums[i];
			nums[i] = temp;
			search(nums, current + 1);
			temp = nums[current];
			nums[current] = nums[i];
			nums[i] = temp;
		}
	}
public:
	vector<vector<int>> permute(vector<int>& nums) {
		search(nums, 0);
		return result;
	}
};

int main() {
	Solution s;
	vector<int> nums = { 1,2,3 };
	vector<vector<int>> result;
	result = s.permute(nums);
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	system("PAUSE");
	return 0;
}