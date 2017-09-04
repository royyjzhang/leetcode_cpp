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
#include<thread>
#include<mutex>
#include<Windows.h>
using namespace std;

class Solution {
public:
	bool wordBreak(string s, unordered_set<string>& wordDict) {
		int n = s.length(), i, j;
		if (n == 0)
			return false;
		vector<bool> checked(n + 1, false);
		string now;
		checked[0] = true;
		for (i = 1; i <= n; i++) {
			for (j = 0; j < i; j++) {
				now = s.substr(j, i - j);
				if ((checked[j]) && (wordDict.find(now) != wordDict.end())) {
					checked[i] = true;
				}
			}
		}
		if (checked[n]) {
			return true;
		}
		else {
			return false;
		}
	}
};

int main() {
	Solution solution;
	string s = "leetcode";
	unordered_set<string> wordDict = { "leet","code" };
	if (solution.wordBreak(s, wordDict)) {
		cout << "True" << endl;
	}
	else {
		cout << "False" << endl;
	}
	system("PAUSE");
	return 0;
}