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
	int lengthOfLastWord(string s) {
		int len = s.length(), i, result = 0;
		if (len == 0) {
			return 0;
		}
		i = len - 1;
		while ((i >= 0) && (s[i] == ' ')) {
			i--;
		}
		while ((i >= 0) && (s[i] != ' ')) {
			i--;
			result++;
		}
		return result;
	}
};

int main() {
	Solution s;
	string str = "   ";
	cout << s.lengthOfLastWord(str) << endl;
	system("PAUSE");
	return 0;
}