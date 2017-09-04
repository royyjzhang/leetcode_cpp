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
	void setZeroes(vector<vector<int>>& matrix) {
		bool firstRow = false, firstCol = false;
		int i, j, m, n;
		m = matrix.size();
		if (m == 0) {
			return;
		}
		n = matrix[0].size();
		if (n == 0) {
			return;
		}
		for (i = 0; i < m; i++) {
			if (matrix[i][0] == 0) {
				firstCol = true;
			}
		}
		for (i = 0; i < n; i++) {
			if (matrix[0][i] == 0) {
				firstRow = true;
			}
		}
		for (i = 1; i < m; i++) {
			for (j = 1; j < n; j++) {
				if (matrix[i][j] == 0) {
					matrix[i][0] = 0;
					matrix[0][j] = 0;
				}
			}
		}
		for (i = 1; i < m; i++) {
			if (matrix[i][0] == 0) {
				for (j = 1; j < n; j++) {
					matrix[i][j] = 0;
				}
			}
		}
		for (j = 1; j < n; j++) {
			if (matrix[0][j] == 0) {
				for (i = 1; i < m; i++) {
					matrix[i][j] = 0;
				}
			}
		}
		if (firstRow) {
			for (i = 0; i < n; i++) {
				matrix[0][i] = 0;
			}
		}
		if (firstCol) {
			for (i = 0; i < m; i++) {
				matrix[i][0] = 0;
			}
		}
	}
};

int main() {
	Solution solution;
	vector<vector<int>> matrix = { {1,1,1,0,1},{1,1,1,1,1},{0,1,1,1,1} };
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[0].size(); j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	solution.setZeroes(matrix);
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[0].size(); j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	system("PAUSE");
	return 0;
}