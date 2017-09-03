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
	int integerReplacement(int n) {
		int result = 0;
		long long now = n;
		while (now > 1) {
			if (now == 3) {
				now--;
			}
			else {
				if ((now & 0b11) == 0b11) {
					now++;
				}
				else if ((now & 0b01) == 0b01) {
					now--;
				}
				else {
					now = now >> 1;
				}
			}
			result++;
		}
		return result;
	}
};

int main() {
	Solution s;
	cout << s.integerReplacement(7) << endl;
	system("PAUSE");
	return 0;
}