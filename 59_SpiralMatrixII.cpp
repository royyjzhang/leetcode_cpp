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
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> matrix(n, vector<int>(n, 0));
		int now, length, starter, goal = n*n;
		starter = 0;
		now = 1;
		length = n;
		while (now < goal) {
			//right
			for (int i = 0; i < length; i++) {
				matrix[starter][starter + i] = now;
				now++;
			}
			//down
			for (int i = 0; i < length - 1; i++) {
				matrix[starter + i + 1][starter + length - 1] = now;
				now++;
			}
			//left
			for (int i = 0; i < length - 1; i++) {
				matrix[starter + length - 1][starter + length - 2 - i] = now;
				now++;
			}
			//up
			for (int i = 0; i < length - 2; i++) {
				matrix[starter + length - 2 - i][starter] = now;
				now++;
			}
			starter++;
			length -= 2;
		}
		if (n % 2 == 1) {
			matrix[n / 2][n / 2] = goal;
		}
		return matrix;
	}
};

int main() {
	Solution s;
	vector<vector<int>> result;
	int n = 4;
	result = s.generateMatrix(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	system("PAUSE");
	return 0;
}