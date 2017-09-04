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
#include<set>
#include<algorithm>
#include<sstream>
using namespace std;

class Solution {
public:
	bool isPowerOfFour(int num) {
		if (num == 1)
			return true;
		if ((num > 0) && ( ((num&(num - 1)) == 0)&& ((num & 0x55555555) != 0))) {
			return true;
		}
		else {
			return false;
		}
	}
};

int main() {
	Solution s;
	int num = 15;
	if (s.isPowerOfFour(num)) {
		cout << "True" << endl;
	}
	else {
		cout << "False" << endl;
	}
	system("PAUSE");
	return 0;
}