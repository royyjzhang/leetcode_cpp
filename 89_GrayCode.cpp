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
	vector<int> grayCode(int n) {
		int total = int(pow(2, n)), current;
		vector<int> result(total);
		for (int i = 0; i < total; i++) {
			current = i ^ (i >> 1);
			result[i] = current;
		}
		return result;
	}
};

int main() {
	Solution s;
	int n = 2;
	vector<int> result;
	result = s.grayCode(n);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}
	system("PAUSE");
	return 0;
}