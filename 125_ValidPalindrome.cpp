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
	bool isPalindrome(string s) {
		string test = "";
		int len = s.length(), sum = 0;
		if (len == 0) {
			return true;
		}
		for (int i = 0; i < len; i++) {
			if (((s[i] >= 'a') && (s[i] <= 'z')) || ((s[i] >= '0') && (s[i] <= '9'))) {
				sum++;
				test += s[i];
			}
			if ((s[i] >= 'A') && (s[i] <= 'Z')) {
				sum++;
				test += s[i] - 'A' + 'a';
			}
		}
		for (int i = 0; i < sum / 2; i++) {
			if (test[i] != test[sum - 1 - i]) {
				return false;
			}
		}
		return true;
	}
};

int main() {
	Solution s;
	string str = "0P";
	if (s.isPalindrome(str)) {
		cout << "True" << endl;
	}
	else {
		cout << "False" << endl;
	}
	system("PAUSE");
	return 0;
}