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
#include<sstream>
#include<unordered_map>
using namespace std;

class Solution {
public:
	int countPrimes(int n) {
		vector<bool> IsPrime(n + 1, true);
		int i, j, result = 0;
		for (i = 2; i < n; i++) {
			if (IsPrime[i]) {
				result++;
				for (j = 2; i * j <= n; j++) {
					IsPrime[i*j] = false;
				}
			}
		}
		return result;
	}
};

int main() {
	Solution s;
	int n = 2;
	cout << s.countPrimes(n) << endl;
	system("PAUSE");
	return 0;
}