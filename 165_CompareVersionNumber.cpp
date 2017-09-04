#include<iostream>
#include<sstream>
#include<string>
using namespace std;

class Solution {
public:
	int compareVersion(string version1, string version2) {
		istringstream ver1(version1), ver2(version2);
		int val1 = 0, val2 = 0;
		char dot = '.';
		while (ver1.good() || ver2.good()) {
			if (ver1.good())
				ver1 >> val1 >> dot;
			if (ver2.good())
				ver2 >> val2 >> dot;
			if (val1 > val2)
				return 1;
			else if (val1 < val2)
				return -1;
			val1 = val2 = 0;
		}
		return 0;
	}
};

int main() {
	string v1 = "1.0", v2 = "1.1";
	Solution s;
	cout << s.compareVersion(v1, v2) << endl;
	system("PAUSE");
	return 0;
}