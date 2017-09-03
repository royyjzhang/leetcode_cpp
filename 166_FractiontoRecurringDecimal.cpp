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
#include<unordered_set>
#include<time.h>
#include<thread>
#include<mutex>
#include<Windows.h>
using namespace std;

class Solution {
public:
	string fractionToDecimal(int numerator, int denominator) {
		if ((numerator == 0) || (denominator == 0))
			return "0";
		long numer = abs((long)numerator), denom = abs((long)denominator), n;
		n = 10 * (numer%denom);
		string result;
		unordered_map<int, int> shown;
		if (n == 0) {
			result = "";
		}
		else {
			result = ".";
		}
		while (n != 0) {
			if (shown.find(n) != shown.end()) {
				result = result.substr(0, shown[n]) + '(' + result.substr(shown[n]) + ')';
				break;
			}
			shown[n] = result.length();
			result.push_back('0' + n / denom);
			n = 10 * (n%denom);
		}
		if (((numerator < 0) ^ (denominator < 0)) != 0) {
			result = '-' + to_string(numer / denom) + result;
		}
		else {
			result = to_string(numer / denom) + result;
		}
		return result;
	}
};

int main() {
	Solution solution;
	int numerator = -1, denominator = -300;
	string result;
	result = solution.fractionToDecimal(numerator, denominator);
	cout << result << endl;
	system("PAUSE");
	return 0;
}