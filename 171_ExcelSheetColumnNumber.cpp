#include<iostream>
#include<vector>
#include<queue>
#include<stdlib.h>
#include<string>
using namespace std;

class Solution {
public:
	int titleToNumber(string s) {
		int len = s.length(), digit = 1, result = 0;
		char c;
		if (len == 0)
			return 0;
		for (int i = len - 1; i >= 0; i--) {
			c = s[i];
			result = result + digit*(c - 64);
			digit *= 26;
		}
		return result;
	}
};

int main() {
	string s = "AA";
	Solution v;
	cout << v.titleToNumber(s) << endl;
	system("PAUSE");
	return 0;
}