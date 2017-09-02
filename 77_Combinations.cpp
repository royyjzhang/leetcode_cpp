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
#include<sstream>
#include<unordered_map>
using namespace std;

class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> result;
		vector<int> line(k, 0);
		int i = 0;
		while (i >= 0) {
			line[i]++;
			if (line[i] > n) {
				i--;
			}
			else if (i == k - 1) {
				result.push_back(line);
			}
			else {
				i++;
				line[i] = line[i - 1];
			}
		}
		return result;
	}
};

int main() {
	Solution solution;
	int n = 4, k = 2;
	vector<vector<int>> result;
	result = solution.combine(n, k);
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < k; j++) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	system("PAUSE");
	return 0;
}