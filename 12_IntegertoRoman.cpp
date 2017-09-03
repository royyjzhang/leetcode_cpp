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
	string intToRoman(int num) {
		int nums[] = { 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000 };
		string rom[] = { "I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M" };
		string result;
		int i = 12;
		while (i >= 0) {
			if (num >= nums[i]) {
				result = result + rom[i];
				num = num - nums[i];
			}
			else
				i--;
		}
		return result;
	}
};

int main() {
	int num = 11;
	Solution s;
	cout << s.intToRoman(num) << endl;
	system("PAUSE");
	return 0;
}