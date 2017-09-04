#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	bool isUgly(int num) {
		if (num <= 0)
			return false;
		while (num % 2 == 0) {
			num /= 2;
		}
		while (num % 3 == 0) {
			num /= 3;
		}
		while (num % 5 == 0) {
			num /= 5;
		}
		return (num == 1);
	}
};

int main() {
	int n = 6;
	Solution s;
	if (s.isUgly(n)) {
		cout << "yes" << endl;
	}
	else
		cout << "no" << endl;
	system("PAUSE");
	return 1;
}