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
private:
	vector<string> result, cur;
	vector<bool> checked;
public:
	void create(string s, unordered_set<string>& wordDict) {
		int n = s.length();
		for (int i = n - 1; i >= 0; i--) {
			if ((wordDict.find(s.substr(i)) != wordDict.end()) && checked[i]) {
				cur.push_back(s.substr(i));
				if (i == 0) {
					string t;
					t += cur.back();
					for (int j = (int)cur.size() - 2; j >= 0; j--) {
						t += " " + cur[j];
					}
					result.push_back(t);
				}
				else {
					create(s.substr(0, i), wordDict);
				}
				cur.pop_back();
			}
		}
	}
	vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
		int n = s.length(), i, j;
		string now;
		checked.resize(n + 1);
		for (i = 0; i < n + 1; i++)
			checked[i] = false;
		checked[0] = true;
		for (i = 1; i <= n; i++) {
			for (j = 0; j < i; j++) {
				now = s.substr(j, i - j);
				if ((checked[j]) && (wordDict.find(now) != wordDict.end())) {
					checked[i] = true;
				}
			}
		}
		create(s, wordDict);
		return result;
	}
};

int main() {
	Solution solution;
	string s = "catsanddog";
	unordered_set<string> wordDict = { "cat", "cats", "and", "sand", "dog" };
	vector<string> result;
	result = solution.wordBreak(s, wordDict);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}
	system("PAUSE");
	return 0;
}