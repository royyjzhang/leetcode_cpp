#include<iostream>
#include<queue>
#include<vector>
#include<cstdlib>
#include<functional>
using namespace std;

class Solution {
private:
	vector<int> num_b;
public:
	double myPow(double x, int n) {
		if (n == 0)
			return 1;
		bool flag = false;
		if (n < 0)
			flag = true;
		int abs_n = abs(n);
		while (abs_n > 0)
		{
			num_b.push_back(abs_n % 2);
			abs_n = abs_n / 2;
		}
		double result = 1, pow_tmp = x;
		for (int i = 0; i < num_b.size(); i++)
		{
			if (num_b[i] == 1)
				result = result*pow_tmp;
			pow_tmp = pow_tmp*pow_tmp;
		}
		if (flag)
			return 1 / result;
		else
			return result;
	}
};

int main()
{
	double x;
	int n;
	Solution s;
	cin >> x >> n;
	cout << s.myPow(x, n) << endl;
	system("PAUSE");
	return 0;
}