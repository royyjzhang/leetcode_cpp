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
using namespace std;

class Solution {
public:
	int longestSubstring(string s, int k) {
		vector<int> check(26, 0);
		bool flag = false;
		int left, right, i;
		if ((s.length() == 0) || (k > s.length())) {
			return 0;
		}
		if (k == 0) {
			return s.size();
		}
		for (i = 0; i < s.length(); i++) {
			check[s[i] - 'a']++;
		}
		for (i = 0; i < s.length(); i++) {
			if (check[s[i] - 'a'] < k) {
				flag = true;
				break;
			}
		}
		if (!flag) {
			return s.size();
		}
		else {
			left = longestSubstring(s.substr(0, i), k);
			right = longestSubstring(s.substr(i+1, s.length()), k);
			if (left > right) {
				return left;
			}
			else {
				return right;
			}
		}
	}
};

int main() {
	Solution solution;
	string s = "aaabbc";
	int k = 3;
	cout << solution.longestSubstring(s, k) << endl;
	system("PAUSE");
	return 0;
}