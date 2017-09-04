#include<iostream>
#include<vector>
#include<queue>
#include<stdlib.h>
#include<string>
#include<algorithm>
#include<map>
#include<math.h>
#include<stdint.h>
#include<stack>
using namespace std;

class Solution {
public:
	int romanToInt(string s) {
		int result = 0;
		int map[256];
		map['I'] = 1;
		map['V'] = 5;
		map['X'] = 10;
		map['L'] = 50;
		map['C'] = 100;
		map['D'] = 500;
		map['M'] = 1000;
		for (int i = 0; i < s.size(); i++)
			if ((i + 1 < s.size()) && (map[s[i]] < map[s[i + 1]]))
				result = result - map[s[i]];
			else
				result = result + map[s[i]];
		return result;
	}
};

int main() {
	string x = "XI";
	Solution s;
	cout << s.romanToInt(x) << endl;
	system("PAUSE");
	return 0;
}