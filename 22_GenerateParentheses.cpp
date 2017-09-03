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
	vector<string> generateParenthesis(int n) {
		vector<string> result;
		string s="";
		if (n <= 0)
			return result;
		generating(n, n, result, s);
		return result;
	}
	void generating(int left, int right, vector<string> &result, string s) {
		if ((left == 0) && (right == 0)) {
			result.push_back(s);
			return;
		}
		if (left > 0) {
			generating(left - 1, right, result, s + '(');
		}
		if (right > 0) {
			if (left < right) {
				generating(left, right - 1, result, s + ')');
			}
		}
	}
};

int main() {
	int n = 3;
	vector<string> result;
	Solution s;
	result = s.generateParenthesis(n);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}
	system("PAUSE");
	return 0;
}