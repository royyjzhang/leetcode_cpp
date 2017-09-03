#include<iostream>
#include<queue>
#include<vector>
#include<cstdlib>
#include<functional>
using namespace std;

class Solution {
public:
	int mySqrt(int x) {
		if (x <= 1)
			return x;
		int low = 1, high = x/2;
		while (low <= high)
		{
			long mid = (low + high) / 2;
			if (mid*mid == x)
				return static_cast<int> (mid);
			else if (mid*mid < x)
				low = mid + 1;
			else
				high = mid - 1;
		}
		return low < high ? low : high;
	}
};

int main()
{
	int x;
	Solution s;
	cin >> x;
	cout << s.mySqrt(x) << endl;
	system("PAUSE");
	return 0;
}