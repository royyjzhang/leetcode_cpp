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
	bool isValidSerialization(string preorder) {
		int diff = 1, i, pos;
		if (preorder.length() == 0)
			return false;
		i = 0;
		while (i < preorder.length()) {
			pos = preorder.find(',', i);
			if (pos == string::npos) {
				diff--;
				if (preorder[i] != '#') {
					diff += 2;
				}
				break;
			}
			else {
				diff--;
				if (preorder[i] != '#') {
					diff += 2;
				}
				i = pos + 1;;
			}
			if (diff <= 0) {
				return false;
			}
		}
		return diff == 0;
	}
};

int main() {
	Solution solution;
	string preorder = "9,3,4,#,#,1,#,#,2,#,6,#,#";
	//string preorder = "1,#";
	//string preorder = "9,#,#,1";
	if (solution.isValidSerialization(preorder)) {
		cout << "True" << endl;
	}
	else {
		cout << "False" << endl;
	}
	system("PAUSE");
	return 0;
}