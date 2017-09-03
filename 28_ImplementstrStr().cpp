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
	int strStr(string haystack, string needle) {
		int n = haystack.length(), m = needle.length(), i, j;
		if (m == 0) {
			return 0;
		}
		if (n == 0) {
			return -1;
		}
		j = 0;
		i = 0;
		while (i + j < n) {
			if (haystack[i + j] != needle[j]) {
				j = 0;
				i++;
			}
			else {
				j++;
			}
			if (j == m) {
				return i;
			}
		}
		return -1;
	}
};

int main() {
	Solution s;
	string haystack = "Hello World", needle = "lo";
	cout << s.strStr(haystack, needle) << endl;
	system("PAUSE");
	return 0;
}