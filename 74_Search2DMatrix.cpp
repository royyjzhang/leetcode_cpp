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
		int m, n, left, right, row, mid;
		m = matrix.size();
		if (m == 0) {
			return false;
		}
		n = matrix[0].size();
		if (n == 0) {
			return false;
		}
		left = 0;
		right = m - 1;
		while (left <= right) {
			mid = (left + right) >> 1;
			if (matrix[mid][0] == target) {
				return true;
			}
			else if (matrix[mid][0] > target) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		if ((right < 0) || (right >= m)) {
			return false;
		}
		row = right;
		left = 0;
		right = n - 1;
		while (left <= right) {
			mid = (left + right) >> 1;
			if (matrix[row][mid] == target) {
				return true;
			}
			else if (matrix[row][mid] > target) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		return false;
	}
};

int main() {
	Solution solution;
	//vector<vector<int>> matrix = { {1,3,5,7},{10,11,16,20},{23,30,34,50} };
	vector<vector<int>> matrix = { {1} };
	if (solution.searchMatrix(matrix, 2)) {
		cout << "True" << endl;
	}
	else {
		cout << "False" << endl;
	}
	system("PAUSE");
	return 0;
}