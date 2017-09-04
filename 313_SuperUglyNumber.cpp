#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int nthSuperUglyNumber(int n, vector<int>& primes) {
		int len = primes.size();
		int result, tmp;
		int locater[100];
		int list[100000];
		if (n == 1)
			return 1;
		list[0] = 1;
		for (int i = 0; i < len; i++)
			locater[i] = 0;
		for (int i = 1; i < n; i++) {
			tmp = primes[0] * list[locater[0]];
			for (int j = 1; j < len; j++) {
				if ((primes[j] * list[locater[j]]) < tmp)
					tmp = primes[j] * list[locater[j]];
			}
			list[i] = tmp;
			for (int j = 0; j < len; j++) {
				if ((primes[j] * list[locater[j]]) <= list[i])
					locater[j]++;
			}
		}
		result = list[n - 1];
		return result;
	}
};

int main() {
	int n = 12;
	vector<int> primes = { 2, 7, 13, 19 };
	Solution s;
	cout << s.nthSuperUglyNumber(n, primes) << endl;
	system("PAUSE");
	return 1;
}