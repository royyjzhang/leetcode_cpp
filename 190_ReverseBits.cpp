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
	uint32_t reverseBits(uint32_t n) {		
		uint32_t result=0, tmp;		
		for (int i = 0; i < 32; i++) {
			tmp = n & 1;
			result = (result << 1) + tmp;
			n = n >> 1;
		}
		return result;
	}
};

int main() {
	uint32_t n = 4;
	Solution v;
	cout << v.reverseBits(n) << endl;
	system("PAUSE");
	return 0;
}