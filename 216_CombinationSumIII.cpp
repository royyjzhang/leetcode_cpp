#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<stdlib.h>
#include<queue>
using namespace std;

class Solution {
private:
	vector<vector<int>> result;
	vector<int> line;
public:
	void dfs(int start, int k, int n) {
		if ((line.size() == k) && (n == 0)) {
			result.push_back(line);
			return;
		}
		for (int i = start; i <= 9; i++) {
			if (n - i >= 0) {
				line.push_back(i);
				dfs(i + 1, k, n - i);
				line.pop_back();
			}
		}
	}
	vector<vector<int>> combinationSum3(int k, int n) {
		if (k == 0 || n == 0)
			return result;
		dfs(1, k, n);
		return result;
	}
};

int main()
{
	Solution s;
	vector<vector<int>> result;
	int k = 3, n = 9;
	result = s.combinationSum3(k, n);
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < k; j++) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	system("PAUSE");
	return 0;
}