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
	bool wordPattern(string pattern, string str) {
		unordered_map<char, string> check1;
		unordered_map<string, char> check2;
		int space, start;
		string word;
		if ((pattern.length() == 0) || (str.length() == 0)) {
			if ((pattern.length() == 0) && (str.length() == 0)) {
				return true;
			}
			else {
				return false;
			}
		}
		space = str.find_first_of(' ');
		if ((space == string::npos) && (pattern.length() == 1)) {
			return true;
		}
		else if (space == string::npos) {
			return false;
		}
		else {
			start = 0;
			for (int i = 0; i < pattern.length(); i++) {
				word = str.substr(start, space - start);
				if ((check1.find(pattern[i]) != check1.end()) && (check1[pattern[i]] != word)) {
					return false;
				}
				else if ((check2.find(word) != check2.end()) && (check2[word] != pattern[i])) {
					return false;
				}
				check1[pattern[i]] = word;
				check2[word] = pattern[i];
				start = space + 1;
				space = str.find_first_of(' ', start + 1);
			}
			space = str.find_last_of(' ');
			if ((start > space) && (space != string::npos))
				return false;
			else
				return true;
		}
	}
};

int main() {
	Solution s;
	string ss = "aaaa", t = "cat dog dog cat";
	if (s.wordPattern(ss, t))
		cout << "True" << endl;
	else
		cout << "False" << endl;
	system("PAUSE");
	return 0;
}