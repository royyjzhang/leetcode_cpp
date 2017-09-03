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
	string countAndSay(int n) {
		string result = "", temp;
		int cur, sum;
		if (n == 0) {
			return result;
		}
		result = "1";
		for (int i = 1; i < n; i++) {
			cur = 0;
			temp = "";
			while (cur < result.length()) {
				sum = 1;
				while ((cur < result.length()) && (result[cur] == result[cur + 1])) {
					sum++;
					cur++;
				}
				temp += to_string(sum) + result[cur];
				cur++;
			}
			result = temp;
		}
		return result;
	}
};

int main() {
	Solution s;
	int n = 5;
	cout << s.countAndSay(n) << endl;
	system("PAUSE");
	return 0;
}