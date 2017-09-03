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
	bool isSubsequence(string s, string t) {
		int lens = s.length(), lent = t.length(), nows, nowt;
		if (lens == 0) {
			return true;
		}
		if (lent == 0) {
			return false;
		}
		nows = 0;
		nowt = 0;
		while ((nows < lens) && (nowt < lent)) {
			if (s[nows] == t[nowt]) {
				nows++;
			}
			nowt++;
		}
		if (nows == lens) {
			return true;
		}
		else {
			return false;
		}
	}
};

int main() {
	Solution solution;
	string s = "abc", t = "ahbgdc";
	if (solution.isSubsequence(s, t)) {
		cout << "True" << endl;
	}
	else {
		cout << "False" << endl;
	}
	system("PAUSE");
	return 0;
}