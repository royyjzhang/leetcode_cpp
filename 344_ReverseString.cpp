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
using namespace std;

class Solution {
public:
	string reverseString(string s) {
		int len = s.length();
		string result;
		for (int i = len - 1; i >= 0; i--) {
			result = result + s[i];
		}
		return result;
	}
};

int main() {
	string s = "Hello.";
	Solution t;
	cout << t.reverseString(s) << endl;
	system("PAUSE");
	return 0;
}