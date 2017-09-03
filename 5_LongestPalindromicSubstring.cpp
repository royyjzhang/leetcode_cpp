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
public:
	string longestPalindrome(string s) {
		int n = s.length(), r, j, i, k, maxpos=0, maxcag=1, maxr = 0;
		string result;
		if (n == 0) {
			return s;
		}
		if (n == 1) {
			return s;
		}
		vector<vector<int>> dp(2, vector<int>(n + 1, 0));
		s = '@' + s + '#';
		for (j = 0; j <= 1; j++) {
			i = 1;
			r = 0;
			dp[j][0] = 0;
			while (i <= n) {
				while (s[i - r - 1] == s[i + j + r]) {
					r++;
				}
				dp[j][i] = r;
				if (dp[j][i] + j > maxr) {
					maxr = dp[j][i];
					maxcag = j;
					maxpos = i;
				}
				k = 1;
				while ((dp[j][i - k] != r - k) && (k < r)) {
					dp[j][i + k] = max(dp[j][i - k], r - k);
					k++;
				}
				r = max(r - k, 0);
				i += k;
			}
		}
		s = s.substr(1, n);
		if (maxr == 0) {
			result = s[0];
		}
		else {
			result = s.substr(maxpos - maxr - 1, 2 * maxr + maxcag);
		}
		return result;
	}
};

int main() {
	Solution solution;
	string s = "aaa";
	cout << solution.longestPalindrome(s) << endl;
	system("PAUSE");
	return 0;
}