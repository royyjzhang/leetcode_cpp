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
	int trailingZeroes(int n) {
		int result = 0;
		long long now = 5;
		while (now <= n) {
			result = result + n / now;
			now = now * 5;
		}
		return result;
	}
};

int main() {
	Solution s;
	int n = 75;
	cout << s.trailingZeroes(n) << endl;
	system("PAUSE");
	return 0;
}