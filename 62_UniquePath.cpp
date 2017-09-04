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
using namespace std;

class Solution {
public:
	int uniquePaths(int m, int n) {
		long up = 1, i, j;
		if ((m == 1) && (n == 1))
			return 1;
		if (m < n) {
			j = n;
			n = m;
			m = j;
		}
		j = 1;
		for (i = m; i < (m + n - 1); i++) {
			up *= i;
			up /= j;
			j++;
		}
		return up;
	}
};

int main() {
	Solution s;
	int m = 1, n = 100;
	cout << s.uniquePaths(m, n) << endl;
	system("PAUSE");
	return 0;
}