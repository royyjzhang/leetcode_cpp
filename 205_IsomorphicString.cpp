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
using namespace std;

class Solution {
public:
	bool isIsomorphic(string s, string t) {
		vector<int> CheckS(255, 0), CheckT(255, 0);
		for (int i = 0; i < s.length(); i++) {
			CheckS[s[i]] = t[i];
			CheckT[t[i]] = s[i];
		}
		for (int i = 0; i < s.length(); i++) {
			if ((CheckS[s[i]] != t[i]) || (CheckT[t[i]] != s[i]))
				return false;
		}
		return true;
	}
};

int main() {
	Solution s;
	string ss = "paper", t = "title";
	if (s.isIsomorphic(ss, t))
		cout << "True" << endl;
	else
		cout << "False" << endl;
	system("PAUSE");
	return 0;
}