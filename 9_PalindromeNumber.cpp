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
	bool isPalindrome(int x) {
		//long input = x;
		int input = x;
		int len = (int)log10(abs(input)), first, last, digit;
		if (x < 0)
			return false;
		if (x == 0)
			return true;
		if (len == 0)
			return true;
		for (int j = 0; j < len; j = j + 2) {
			digit = (int)pow(10, double(len - j));
			first = input / digit;
			input = input % digit;
			last = input % 10;
			if (first != last)
				return false;
			input = input / 10;
		}
		return true;
	}
};

int main() {
	int x = -2147483648;
	Solution s;
	if (s.isPalindrome(x))
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	system("PAUSE");
	return 0;
}