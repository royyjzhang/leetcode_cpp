#include<iostream>
#include<vector>
#include<queue>
#include<stdlib.h>
using namespace std;

class Solution {
public:
	int numTrees(int n) {
		vector<int> bstn(n + 1, 0);
		bstn[0] = 1;
		bstn[1] = 1;
		if (n == 1)
			return 1;
		for (int i = 2; i <= n; i++) {
			for (int j = 1; j <= i; j++) {
				bstn[i] = bstn[i] + bstn[j - 1] * bstn[i - j];
			}
		}
		return bstn[n];
	}
};

int main() {
	int n = 3;
	Solution s;
	cout << s.numTrees(n) << endl;
	system("PAUSE");
	return 0;
}