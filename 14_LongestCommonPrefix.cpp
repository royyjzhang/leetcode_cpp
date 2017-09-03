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
	string longestCommonPrefix(vector<string>& strs) {
		int i, j;
		string result = "";
		char now;
		bool flag = true;
		if (strs.size() == 0) {
			return result;
		}
		for (i = 0; i < strs[0].size(); i++) {
			now = strs[0][i];
			for (j = 0; j < strs.size(); j++) {
				if ((strs[j][i] != now) || (strs[j][i] == '\0')) {
					flag = false;
					break;
				}
			}
			if (flag) {
				result += now;
			}
			else {
				break;
			}
		}
		return result;
	}
};

int main() {
	Solution s;
	vector<string> strs = { "previous","pretend","protect" };
	cout << s.longestCommonPrefix(strs) << endl;
	system("PAUSE");
	return 0;
}