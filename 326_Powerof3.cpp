#include<iostream>
#include<vector>
#include<queue>
#include<stdlib.h>
#include<string>
#include<algorithm>
#include<map>
#include<math.h>
using namespace std;

class Solution {
public:
	bool isPowerOfThree(int n) {
		if (n < 1)
			return false;
		if (1162261467 % n == 0)
			return true;
		else
			return false;
	}
};

int main() {
	int n = 3;
	Solution v;
	if (v.isPowerOfThree(n))
		cout << "yes";
	else
		cout << "no";
	system("PAUSE");
	return 0;
}