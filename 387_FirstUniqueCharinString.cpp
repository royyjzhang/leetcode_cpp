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
#include<set>
#include<algorithm>
using namespace std;

class Solution {
public:
	int firstUniqChar(string s) {
		vector<int> check(26);
		int result = -1;
		for (int i = 0; i < 26; i++) {
			check[i] = 0;
		}
		for (int i = 0; i < s.length(); i++) {
			check[s[i] - 'a']++;
		}
		for (int i = 0; i < s.length(); i++) {
			if (check[s[i] - 'a'] == 1) {
				result = i;
				break;
			}
		}
		return result;
	}
};

int main() {
	Solution s;
	string ss = "leetcode";
	cout << s.firstUniqChar(ss) << endl;
	system("PAUSE");
	return 0;
}