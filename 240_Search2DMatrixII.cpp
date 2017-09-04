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
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int col, row, m, n;
		n = matrix.size();
		if (n == 0)
			return false;
		m = matrix[0].size();
		if (m == 0)
			return false;
		col = m - 1;
		row = 0;
		while ((col >= 0) && (row < n)) {
			if (matrix[row][col] == target) {
				return true;
			}
			else if (matrix[row][col] > target) {
				col--;
			}
			else {
				row++;
			}
		}
		return false;
	}
};

int main() {
	Solution solution;
	//vector<vector<int>> matrix = { {1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30} };
	//vector<vector<int>> matrix = { {1,1} };
	vector<vector<int>> matrix = { {1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25} };
	if (solution.searchMatrix(matrix, 19)) {
		cout << "True" << endl;
	}
	else {
		cout << "False" << endl;
	}
	system("PAUSE");
	return 0;
}