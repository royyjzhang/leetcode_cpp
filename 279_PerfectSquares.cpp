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
public:
	int numSquares(int n) {
		if (n == 0)
			return 0;
		vector<int> dp(n + 1, 0);
		int i, j, min;
		for (i = 1; i <= n; i++) {
			min = i;
			for (j = 1; j <= sqrt(i); j++) {
				if (dp[i - j*j] + 1 < min) {
					min = dp[i - j*j] + 1;
				}
			}
			dp[i] = min;
		}
		return dp[n];
	}
};

int main() {
	Solution solution;
	int n = 12;
	cout << solution.numSquares(n) << endl;
	system("PAUSE");
	return 0;
}