#include<iostream>
#include<vector>
#include<queue>
#include<stdlib.h>
#include<string>
#include<algorithm>
#include<map>
#include<math.h>
using namespace std;

class Solution {
public:
	bool isPowerOfTwo(int n) {
		int check = 1;
		if (n <= 0)
			return false;
		for (int i = 0; i < 31; i++) {
			if ((n^check) == 0)
				return true;
			check = check << 1;
		}
		return false;
	}
};

int main() {	
	int n = 128;
	Solution v;
	if (v.isPowerOfTwo(n))
		cout << "yes";
	else
		cout << "no";
	system("PAUSE");
	return 0;
}