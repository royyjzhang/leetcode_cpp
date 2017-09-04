#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
	int getSum(int a, int b) {
		int c;
		while (a && b) {
			c = a^b;
			b = (a&b) << 1;
			a = c;
		}
		return (a | b);
	}
};

int main()
{
	Solution s;
	int a = 10, b = 2;
	cout << s.getSum(a,b) << endl;
	system("PAUSE");
	return 0;
}