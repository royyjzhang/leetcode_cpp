#include<iostream>
using namespace std;

class Solution {
public:
	int countNumbersWithUniqueDigits(int n) {
		if (n == 0)
			return 1;
		if (n == 1)
			return 10;
		int sum = 10, temp, now;
		for (int i = n; i >= 2; i--) {
			temp = 9;
			now = 9;
			for (int j = i - 1; j > 0; j--) {
				temp = temp*now;
				now--;
			}
			sum += temp;
		}
		return sum;
	}
};

int main()
{
	Solution s;
	int n;
	n = 3;
	cout << s.countNumbersWithUniqueDigits(n) << endl;
	system("PAUSE");
	return 0;
}