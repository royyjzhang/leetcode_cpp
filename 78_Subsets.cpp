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
private:
	vector<vector<int>> result;
	vector<int> line;
	void search(vector<int> &nums, int index) {
		result.push_back(line);
		for (int i = index; i < nums.size(); i++) {
			line.push_back(nums[i]);
			search(nums, i + 1);
			line.pop_back();
		}
	} 
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		search(nums, 0);
		return result;
	}
};

int main() {
	Solution solution;
	vector<int> nums = { 1,2,3 };
	vector<vector<int>> result;
	result = solution.subsets(nums);
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	system("PAUSE");
	return 0;
}