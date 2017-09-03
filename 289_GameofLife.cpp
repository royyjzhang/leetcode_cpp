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
	void gameOfLife(vector<vector<int>>& board) {
		int m, n, i, j, count;
		m = board.size();
		if (m == 0) {
			return;
		}
		n = board[0].size();
		if (n == 0) {
			return;
		}
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				count = 0;
				if ((i > 0) && (j > 0)) {
					count += board[i - 1][j - 1] & 1;
				}
				if ((j > 0)) {
					count += board[i][j - 1] & 1;
				}
				if ((j < n - 1)) {
					count += board[i][j + 1] & 1;
				}
				if ((i > 0) && (j < n - 1)) {
					count += board[i - 1][j + 1] & 1;
				}
				if ((i > 0)) {
					count += board[i - 1][j] & 1;
				}
				if ((i < m - 1)) {
					count += board[i + 1][j] & 1;
				}
				if ((i < m - 1) && (j < n - 1)) {
					count += board[i + 1][j + 1] & 1;
				}
				if ((i < m - 1) && (j > 0)) {
					count += board[i + 1][j - 1] & 1;
				}
				if ((count | board[i][j]) == 3) {
					board[i][j] |= 2;
				}
			}
		}
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				board[i][j] >>= 1;
			}
		}
	}
};

int main() {
	Solution solution;
	//vector<vector<int>> board = { {1,0,1},{0,1,0},{1,0,1} };
	vector<vector<int>> board = { { 1 },{ 0 },{ 0 },{1},{0},{0},{1},{0},{0},{1} };
	solution.gameOfLife(board);
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[0].size(); j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	system("PAUSE");
	return 0;
}