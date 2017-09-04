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
	int maxRotateFunction(vector<int>& A) {
		int result, sum, now, n = A.size();
		if (n == 0) {
			return 0;
		}
		sum = 0;
		now = 0;
		for (int i = 0; i < n; i++) {
			sum += A[i];
			now += i*A[i];
		}
		result = now;
		for (int i = n - 1; i >= 0; i--) {
			now += sum - n*A[i];
			if (now > result)
				result = now;
		}
		return result;
	}
};

int main() {
	Solution s;
	vector<int> A = { 4,3,2,6 };
	cout << s.maxRotateFunction(A) << endl;
	system("PAUSE");
	return 0;
}