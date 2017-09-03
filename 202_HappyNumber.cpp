#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	bool isHappy(int n) {
		int check[810] = { 0 };
		int sum, tmp;
		if (n == 1)
			return true;
		if (n < 810)
			check[n-1] += 1;
		while (n != 1) {
			sum = 0;
			tmp = n;
			while (tmp != 0) {
				sum = sum + (tmp % 10) * (tmp % 10);
				tmp = tmp / 10;
			}
			if (check[sum - 1] != 0)
				return false;
			check[sum - 1] = 1;
			n = sum;
		}
		return true;
	}
};

int main() {
	int n = 19;
	Solution s;
	if (s.isHappy(n)) {
		cout << "yes" << endl;
	}
	else
		cout << "no" << endl;
	system("PAUSE");
	return 1;
}