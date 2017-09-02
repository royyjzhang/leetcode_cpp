#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int addDigits(int num) {
		int rest;
		rest = (num - 1) / 9;
		return num - rest * 9;
	}
};

int main() {
	int n = 10;
	Solution s;
	cout << s.addDigits(n) << endl;
	system("PAUSE");
	return 1;
}