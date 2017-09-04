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
	bool isPerfectSquare(int num) {
		int e = 1;
		while (num > 0) {
			num -= e;
			e += 2;
		}
		if (num == 0)
			return true;
		else
			return false;
	}
};

int main() {
	Solution s;
	int n = 17;
	if (s.isPerfectSquare(n))
		cout <<  "True" << endl;
	else
		cout << "False" << endl;
	system("PAUSE");
	return 0;
}