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
using namespace std;

class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		vector<bool> check(9,false);
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (board[i][j] != '.') {
					if (check[board[i][j] - '1']) {
						return false;
					}
					else {
						check[board[i][j] - '1'] = true;
					}
				}
			}
			for (int k = 0; k < 9; k++) {
				check[k] = false;
			}
		}
		for (int k = 0; k < 9; k++) {
			check[k] = false;
		}
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (board[j][i] != '.') {
					if (check[board[j][i] - '1']) {
						return false;
					}
					else {
						check[board[j][i] - '1'] = true;
					}
				}
			}
			for (int k = 0; k < 9; k++) {
				check[k] = false;
			}
		}
		for (int k = 0; k < 9; k++) {
			check[k] = false;
		}
		for (int r = 0; r < 3; r++) {
			for (int c = 0; c < 3; c++) {
				for (int i = 3*r; i < 3*r+3; i++) {
					for (int j = 3*c; j < 3*c+3; j++) {
						if (board[i][j] != '.') {
							if (check[board[i][j] - '1']) {
								return false;
							}
							else {
								check[board[i][j] - '1'] = true;
							}
						}
					}
				}
				for (int k = 0; k < 9; k++) {
					check[k] = false;
				}
			}
		}
		return true;
	}
};

int main() {
	Solution s;
	vector<vector<char>> board = { {'5','3','.','.','7','.','.','.','.'},{ '6','.','.','1','9','5','.','.','.' },
	{ '.','9','8','.','.','.','.','6','.' },{ '8','.','.','.','6','.','.','.','3' },{ '4','.','.','8','.','3','.','.','1' },
	{ '7','.','.','.','2','.','.','.','6' },{ '.','6','.','.','.','.','2','8','.' },{ '.','.','.','4','1','9','.','.','5' },
	{ '.','.','.','.','8','.','.','7','9' } };
	if (s.isValidSudoku(board)) {
		cout << "True" << endl;
	}
	else {
		cout << "False" << endl;
	}
	system("PAUSE");
	return 0;
}