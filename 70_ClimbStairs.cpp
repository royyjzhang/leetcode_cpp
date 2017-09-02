#include<iostream>
#include<vector>
#include<queue>
#include<stdlib.h>
using namespace std;

class Solution {
public:
	int climbStairs(int n) {
		int a = 1, b = 2, c;
		if (n == 1)
			return 1;
		if (n == 2)
			return 2;
		for (int i = 3; i <= n; i++) {
			c = a + b;
			a = b;
			b = c;
		}
		return c;
	}
};

int main() {
	Solution s;
	cout << s.climbStairs(3) << endl;
	system("PAUSE");
	return 0;
}