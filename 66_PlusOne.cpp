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
	vector<int> plusOne(vector<int>& digits) {
		int len = digits.size(), i;
		vector<int> result;
		bool flag = false;
		digits[len - 1]++;
		for (i = len-1; i >= 0; i--) {
			if (flag)
				digits[i]++;
			if (digits[i] > 9) {
				flag = true;
				digits[i] = digits[i] % 10;
			}
			else
				flag = false;
		}
		if (!flag)
			result = digits;
		else {
			result.resize(len + 1, 0);
			result[0] = 1;
			for (i = 0; i < len; i++)
				result[i + 1] = digits[i];
		}
		return result;
	}
};

int main() {
	vector<int> digits = { 9, 9 },result;
	Solution s;
	result = s.plusOne(digits);
	for (int i = 0; i < result.size();i++)
		cout << result[i];
	system("PAUSE");
	return 0;
}