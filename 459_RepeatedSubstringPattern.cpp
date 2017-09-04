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
#include<iomanip>
using namespace std;

class Solution {
public:
	bool repeatedSubstringPattern(string s) {
		int len = s.length();
		for (int i = len / 2; i >= 1; i--) {
			if (len % i == 0) {
				int m = len / i;
				string subs = s.substr(0, i);
				string res = "";
				for (int j = 0; j < m; j++) {
					res += subs;
				}
				if (s == res) {
					return true;
				}
			}
		}
		return false;
	}
};

int main() {
	Solution solution;
	string s = "abab";
	if (solution.repeatedSubstringPattern(s)) {
		cout << "True" << endl;
	}
	else {
		cout << "False" << endl;
	}
	system("PAUSE");
	return 0;
}