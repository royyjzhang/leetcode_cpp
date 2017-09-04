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
	void rotate(vector<vector<int>>& matrix) {
		int n = matrix.size(), tmp1, tmp2,tmp3;
		if ((n == 0) || (n == 1))
			return;
		for (int i = 0; i < n / 2; i++) {
			for (int j = 0; j < n / 2; j++) {
				tmp1 = matrix[j][n - 1 - i];
				matrix[j][n - 1 - i] = matrix[i][j];
				tmp2 = matrix[n - 1 - i][n - 1 - j];
				matrix[n - 1 - i][n - 1 - j] = tmp1;
				tmp3 = matrix[n - 1 - j][i];
				matrix[n - 1 - j][i] = tmp2;
				matrix[i][j] = tmp3;
			}
		}
		if (n % 2 == 1) {
			for (int i = 0; i < n / 2; i++) {
				tmp1 = matrix[i][(n - 1) / 2];
				matrix[i][(n - 1) / 2] = matrix[(n - 1) / 2][i];
				tmp2 = matrix[(n - 1) / 2][n - 1 - i];
				matrix[(n - 1) / 2][n - 1 - i] = tmp1;
				tmp3 = matrix[n - 1 - i][(n - 1) / 2];
				matrix[n - 1 - i][(n - 1) / 2] = tmp2;
				matrix[(n - 1) / 2][i] = tmp3;
			}
		}
	}
};

int main() {
	Solution solution;
	//vector<vector<int>> matrix = { {1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30} };
	//vector<vector<int>> matrix = { {1,1} };
	vector<vector<int>> matrix = { { 1,2,3,4,5 },{ 6,7,8,9,10 },{ 11,12,13,14,15 },{ 16,17,18,19,20 },{ 21,22,23,24,25 } };
	solution.rotate(matrix);
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[0].size(); j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	system("PAUSE");
	return 0;
}