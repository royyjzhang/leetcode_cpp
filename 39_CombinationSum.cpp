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
	void search(vector<int>& candidates, int target, int pos) {
		if (target == 0) {
			result.push_back(line);
			return;
		}
		if ((target < 0) || (pos >= candidates.size())) {
			return;
		}
		if (target < candidates[pos]) {
			return;
		}
		line.push_back(candidates[pos]);
		search(candidates, target - candidates[pos], pos);
		line.pop_back();
		search(candidates, target, pos + 1);
	}
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		if (candidates.size() == 0)
			return result;
		sort(candidates.begin(), candidates.end());
		search(candidates, target, 0);
		return result;
	}
};

int main() {
	Solution solution;
	vector<int> candidates = { 2,3,6,7 };
	int target = 7;
	vector<vector<int>> result;
	result = solution.combinationSum(candidates, target);
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	system("PAUSE");
	return 0;
}