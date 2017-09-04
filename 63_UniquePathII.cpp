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
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		vector<vector<int>> dp;
		vector<int> temp;
		int m, n, i, j;
		n = obstacleGrid.size();
		m = obstacleGrid[0].size();
		if ((n == 0) || (m == 0)) {
			return 0;
		}
		temp.resize(m);
		for (i = 0; i < m; i++) {
			temp[i] = 0;
		}
		for (j = 0; j < n; j++) {
			dp.push_back(temp);
		}
		if (obstacleGrid[0][0] == 1) {
			return 0;
		}
		dp[0][0] = 1;
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				if (obstacleGrid[j][i] == 1) {
					dp[j][i] == 0;
				}
				else {
					if (i > 0) {
						dp[j][i] += dp[j][i - 1];
					}
					if (j > 0) {
						dp[j][i] += dp[j - 1][i];
					}
				}
			}
		}
		return dp[n - 1][m - 1];
	}
};

int main() {
	Solution s;
	int i;
	vector<vector<int>> obstaclegrid = { {0,0} };
	cout << s.uniquePathsWithObstacles(obstaclegrid) << endl;
	system("PAUSE");
	return 0;
}