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
#include<set>
#include<algorithm>
#include<sstream>
using namespace std;

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> result;
		vector<int> now, previous;
		int currentlevel;
		if (numRows < 1) {
			return result;
		}
		else if (numRows == 1) {
			now.push_back(1);
			result.push_back(now);
			return result;
		}
		else if (numRows == 2) {
			now.push_back(1);
			result.push_back(now);
			now.push_back(1);
			result.push_back(now);
			return result;
		}
		else {
			now.push_back(1);
			result.push_back(now);
			now.push_back(1);
			result.push_back(now);
			previous = now;
			now.clear();
			currentlevel = 3;
			while (currentlevel <= numRows) {
				now.resize(currentlevel);
				now[0] = 1;
				for (int j = 1; j < currentlevel - 1; j++) {
					now[j] = previous[j - 1] + previous[j];
				}
				now[currentlevel - 1] = 1;
				result.push_back(now);
				previous = now;
				now.clear();
				currentlevel++;
			}
			return result;
		}
	}
};

int main() {
	Solution s;
	int num = 5;
	vector<vector<int>> result;
	result = s.generate(num);
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j] << ",";
		}
		cout << endl;
	}
	system("PAUSE");
	return 0;
}