#include<iostream>
#include<math.h>
using namespace std;

class Solution {
public:
	int integerBreak(int n) {
		if (n == 2)
			return 1;
		if (n == 3)
			return 2;
		if (n == 4)
			return 4;
		int prev, rest;
		prev = n / 3;
		rest = n % 3;
		if (rest == 0)
			return int(pow(3, prev));
		else if (rest == 1)
			return int(pow(3, prev - 1) * 4);
		else
			return int(pow(3, prev) * 2);
	}
};

int main()
{
	Solution s;
	int n;
	n = 10;
	cout << s.integerBreak(n) << endl;
	system("PAUSE");
	return 0;
}