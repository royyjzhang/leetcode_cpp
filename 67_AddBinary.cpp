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
using namespace std;

class Solution {
public:
	string addBinary(string a, string b) {
		int len, i, j;
		string result;
		bool flag_inc;
		flag_inc = false;
		i = a.length();
		j = b.length();
		while ((i >= 0) && (j>=0)) {
			if ((!flag_inc) && (a[i] == '0') && (b[j] == '0')) {
				flag_inc = false;
				result = "0" + result;
			}
			else if ((flag_inc) && (a[i] == '0') && (b[j] == '0')) {
				flag_inc = false;
				result = "1" + result;
			}
			else if ((!flag_inc) && (a[i] == '1') && (b[j] == '1')) {
				flag_inc = true;
				result = "0" + result;
			}
			else if ((flag_inc) && (a[i] == '1') && (b[j] == '1')) {
				flag_inc = true;
				result = "1" + result;
			}
			else if ((!flag_inc) && ((a[i] == '1') || (b[j] == '1'))) {
				flag_inc = false;
				result = "1" + result;
			}
			else if ((flag_inc) && ((a[i] == '1') || (b[j] == '1'))) {
				flag_inc = true;
				result = "0" + result;
			}
			i--;
			j--;
		}
		while (i >= 0) {
			if ((!flag_inc) && (a[i] == '0')) {
				flag_inc = false;
				result = "0" + result;
			}
			else if ((flag_inc) && (a[i] == '0')) {
				flag_inc = false;
				result = "1" + result;
			}
			else if ((!flag_inc) && (a[i] == '1')) {
				flag_inc = false;
				result = "1" + result;
			}
			else if ((flag_inc) && (a[i] == '1')) {
				flag_inc = true;
				result = "0" + result;
			}
			i--;
		}
		while (j >= 0) {
			if ((!flag_inc) && (b[j] == '0')) {
				flag_inc = false;
				result = "0" + result;
			}
			else if ((flag_inc) && (b[j] == '0')) {
				flag_inc = false;
				result = "1" + result;
			}
			else if ((!flag_inc) && (b[j] == '1')) {
				flag_inc = false;
				result = "1" + result;
			}
			else if ((flag_inc) && (b[j] == '1')) {
				flag_inc = true;
				result = "0" + result;
			}
			j--;
		}
		if (flag_inc)
			result = "1" + result;
		return result;
	}
};

int main() {
	string a = "100", b = "110010";
	Solution s;
	cout << s.addBinary(a,b) << endl;
	system("PAUSE");
	return 0;
}