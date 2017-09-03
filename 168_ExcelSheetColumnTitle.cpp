#include<iostream>
#include<vector>
#include<queue>
#include<stdlib.h>
#include<string>
using namespace std;

class Solution {
public:
	string convertToTitle(int n) {
		string result="";
		char c;
		if (n <= 0)
			return result;
		while (n > 0) {
			c = ((n-1) % 26) + 65;
			result = c + result;
			n = (n-1) / 26;
		}
		return result;
	}
};

int main() {
	int s = 26;
	Solution v;
	cout << v.convertToTitle(s) << endl;
	system("PAUSE");
	return 0;
}