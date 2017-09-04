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
#include<unordered_set>
using namespace std;

class Solution {
public:
	bool validUtf8(vector<int>& data) {
		int n = data.size(), i, count = 0;
		if (n == 0)
			return true;
		for (i = 0; i < data.size(); i++) {
			if (count == 0) {
				if (data[i] >> 5 == 0b110) {
					count = 1;
				}
				else if (data[i] >> 4 == 0b1110) {
					count = 2;
				}
				else if (data[i] >> 3 == 0b11110) {
					count = 3;
				}
				else if (data[i] >> 7 != 0) {
					return false;
				}
			}
			else {
				if (data[i] >> 6 != 0b10) {
					return false;
				}
				count--;
			}
		}
		if (count == 0) {
			return true;
		}
		else {
			return false;
		}
	}
};

int main() {
	Solution solution;
	vector<int> data = { 235,140,4 };
	if (solution.validUtf8(data)) {
		cout << "True" << endl;
	}
	else {
		cout << "False" << endl;
	}
	system("PAUSE");
	return 0;
}