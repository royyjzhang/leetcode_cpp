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
	int myAtoi(string str) {
		//const int INT_MAXI = 2147483647, INT_MINI = -2147483648;
		int i = 0, result = 0, len = str.length(), sign = 1, max = INT_MAX;
		if (len == 0)
			return result;
		while ((str[i] == ' ') && (i < len))
			i++;
		if (str[i] == '-') {
			sign = -1;
			max = INT_MIN;
		}
		if ((str[i] == '-') || (str[i] == '+'))
			i++;
		for (; i < len;i++){
			if ((str[i]<'0') || (str[i]>'9'))
				break;
			if (((max - (str[i] - '0') * sign) / 10 * sign) >= result)
				result = result * 10 + str[i] - '0';
			else
				return max;
		}
		return sign*result;
	}
};

int main() {
	string str = "-123";
	Solution v;
	cout << v.myAtoi(str) << endl;
	system("PAUSE");
	return 0;
}