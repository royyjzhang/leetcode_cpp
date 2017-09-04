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
	vector<int> getRow(int rowIndex) {
		vector<int> result;
		int CurrentLevel, origin, prev;
		if (rowIndex < 0) {
			return result;
		}
		else if (rowIndex == 0) {
			result.push_back(1);
			return result;
		}
		else if (rowIndex == 1) {
			result.push_back(1);
			result.push_back(1);
			return result;
		}
		else {
			CurrentLevel = 2;
			result.push_back(1);
			result.push_back(1);
			while (CurrentLevel <= rowIndex) {
				prev = 1;
				for (int i = 1; i < CurrentLevel; i++) {
					origin = result[i];
					result[i] = result[i] + prev;
					prev = origin;
				}
				result.push_back(1);
				CurrentLevel++;
			}
			return result;
		}
	}
};

int main() {
	Solution s;
	int num = 3;
	vector<int> result;
	/*for (num = 1; num < 10; num++) {
		result = s.getRow(num);
		for (int i = 0; i < result.size(); i++) {
			cout << result[i] << ",";
		}
		cout << endl;
	}*/
	result = s.getRow(num);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << ",";
	}
	cout << endl;
	system("PAUSE");
	return 0;
}