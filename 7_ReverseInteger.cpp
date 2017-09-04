#include<iostream>
#include<vector>
#include<queue>
#include<stdlib.h>
#include<string>
#include<algorithm>
#include<map>
#include<math.h>
#include<stdint.h>
using namespace std;

class Solution {
public:
	int reverse(int x) {
		int len = 0, d, result=0;
		long result_tmp = 0;
		vector<int> digit;
		bool flag = true;
		if (x < 0) {
			flag = false;
			x = -x;
		}
		while (x > 0) {
			d = x % 10;
			x = x / 10;
			digit.push_back(d);
			len++;
		}
		for (int i = 0; i < len; i++) {
			result_tmp = result_tmp * 10 + digit[i];
		}
		if (result_tmp > 2147483647)
			return 0;
		if (flag) {
			result = (int)result_tmp;
			return result;
		}
		else {
			result = (int)-result_tmp;
			return result;
		}
	}
};

int main() {
	int n = -123;
	Solution v;
	cout << v.reverse(n) << endl;
	system("PAUSE");
	return 0;
}