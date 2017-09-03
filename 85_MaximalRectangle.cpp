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
#include<unordered_set>
#include<time.h>
using namespace std;

class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		int m = matrix.size(), result = 0, n, i, j, cur_left, cur_right;
		if (m == 0) {
			return result;
		}
		n = matrix[0].size();
		if (n == 0) {
			return result;
		}
		vector<int> left(n, 0), right(n, n), height(n, 0);
		for (i = 0; i < m; i++) {
			cur_left = 0;
			for (j = 0; j < n; j++) {
				if (matrix[i][j] == '1') {
					left[j] = max(left[j], cur_left);
					height[j]++;
				}
				else {
					left[j] = 0;
					cur_left = j + 1;
					height[j] = 0;
				}
			}
			cur_right = n;
			for (j = n - 1; j >= 0; j--) {
				if (matrix[i][j] == '1') {
					right[j] = min(right[j], cur_right);
				}
				else {
					right[j] = n;
					cur_right = j;
				}
			}
			for (j = 0; j < n; j++) {
				if (result < (right[j] - left[j])*height[j]) {
					result = (right[j] - left[j])*height[j];
				}
			}
		}
		return result;
	}
};

int main() {
	Solution solution;
	//vector<vector<char>> matrix = { {'1','0','1','0','0'},{ '1','0','1','1','1' } ,{ '1','1','1','1','1' } ,{ '1','0','0','1','0' } };
	vector<vector<char>> matrix = { {'1'} };
	cout << solution.maximalRectangle(matrix) << endl;
	system("PAUSE");
	return 0;
}