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
#include<sstream>
using namespace std;

class Solution {
private:
	int getNumber(string &s, int &begin) {
		int num = 0;
		while (begin < s.length() && isdigit(s[begin])) {
			num = num * 10 + (s[begin] - '0');
			begin++;
		}
		begin--;
		return num;
	}
	string decoding(string s, int &begin) {
		int m = 0, now;
		string numpart, rest, inter, result = "";
		char temp;
		while (begin < s.length()) {
			temp = s[begin];
			if (temp == '[') {
				begin++;
				inter = decoding(s, begin);
				for (int i = 0; i < m; i++) {
					result = result + inter;
				}
				m = 0;
			}
			else if (isdigit(temp)) {
				m = getNumber(s, begin);
			}
			else if (temp == ']') {
				return result;
			}
			else {
				result += s[begin];
			}
			begin++;
		}
		return result;
	}
public:
	string decodeString(string s) {	
		int begin = 0;
		return decoding(s, begin);
	}
};

int main() {
	Solution s;
	string st = "3[a4[d]p]2[bc]";
	cout << s.decodeString(st) << endl;
	system("PAUSE");
	return 0;
}