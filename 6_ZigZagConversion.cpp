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
	string convert(string s, int numRows) {
		string result = "";
		int j = 0, index1, index2;
		int CircleSize = 2 * (numRows - 1);
		if (CircleSize <= 0) {
			return s;
		}
		for (int i = 0; i < numRows; i++) {
			j = 0;
			while (true) {
				index1 = j*CircleSize + i;
				if (index1 < s.size()) {
					result += s[index1];
					if ((i != 0) && (i != numRows - 1)) {
						index2 = index1 + CircleSize - (i << 1);
						if (index2 < s.size()) {
							result += s[index2];
						}
						else {
							break;
						}
					}
				}
				else {
					break;
				}
				j++;
			}
		}
		return result;
	}
};

int main() {
	Solution s;
	int n = 3;
	string ss = "PAYPALISHIRING";
	cout << s.convert(ss, n) << endl;
	system("PAUSE");
	return 0;
}