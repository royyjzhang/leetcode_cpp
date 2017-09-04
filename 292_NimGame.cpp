#include<iostream>
using namespace std;

class Solution {
public:
	bool canWinNim(int n) {
		return (n % 4 != 0);
	}
};

int main() {
	int n = 5;
	Solution s;
	if (s.canWinNim(n))
		cout << "win" << endl;
	else
		cout << "loose" << endl;
	system("PAUSE");
	return 0;
}