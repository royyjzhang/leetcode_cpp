#include<iostream>
#include<vector>
#include<queue>
#include<stdlib.h>
#include<string>
#include<algorithm>
#include<map>
#include<math.h>
#include<stdint.h>
using namespace std;

class Solution {
public:
	int hammingWeight(uint32_t n) {
		int result = 0;
		for (int i = 0; i < 32; i++) {
			if ((n & 1) == 1)
				result++;
			n = n >> 1;
		}
		return result;
	}
};

int main() {
	uint32_t n = 11;
	Solution v;
	cout << v.hammingWeight(n) << endl;
	system("PAUSE");
	return 0;
}