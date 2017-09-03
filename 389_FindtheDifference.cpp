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
	char findTheDifference(string s, string t) {
		int sums = 0, sumt = 0;
		char result;
		for (int i = 0; i < s.length(); i++) {
			sums += s[i];
			sumt += t[i];
		}
		sumt += t[t.length() - 1];
		result = sumt - sums;
		return result;
	}
};

int main() {
	Solution s;
	string ss = "abcd", t = "abcde";
	cout << s.findTheDifference(ss, t) << endl;
	system("PAUSE");
	return 0;
}