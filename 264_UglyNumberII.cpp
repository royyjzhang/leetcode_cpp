#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int min(int a, int b) {
		if (a < b)
			return a;
		else
			return b;
	}
	int getMin(int a, int  b, int  c) {
		int tmp = min(a, b);
		return min(tmp, c);
	}
	int nthUglyNumber(int n) {
		int *list = new int[n];
		int point2 = 0, point3 = 0, point5 = 0, result;
		if (n == 1)
			return 1;
		list[0] = 1;
		for (int i = 1; i < n; i++) {
			list[i] = getMin(list[point2] * 2, list[point3] * 3, list[point5] * 5);
			while (list[i] >= list[point2] * 2)
				point2++;
			while (list[i] >= list[point3] * 3)
				point3++;
			while (list[i] >= list[point5] * 5)
				point5++;
		}
		result = list[n - 1];
		delete list;
		return result;
	}
};

int main() {
	int n = 10;
	Solution s;
	cout << s.nthUglyNumber(n) << endl;
	system("PAUSE");
	return 1;
}