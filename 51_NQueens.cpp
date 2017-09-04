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
private:
	vector<vector<string>> result;
	vector<int> place;
public:
	void printPlace(int n) {
		vector<string> s;
		string line;
		int i;
		for (i = 1; i < n; i++) {
			line.clear();
			line.assign(n-1,'.');
			line[place[i] - 1] = 'Q';
			s.push_back(line);
		}
		result.push_back(s);
	}
	bool isLegal(int row, int col) {
		for (int i = 1; i < row; i++) {
			if ((place[i] == col) || (abs(row - i) == abs(col - place[i])))
				return false;
		}
		return true;
	}
	void placeQueen(int row, int n) {
		if (row == n) {
			printPlace(n);
			return;
		}
		for (int i = 1; i < n; i++) {
			place[row] = i;
			if (isLegal(row, i)) {
				placeQueen(row + 1, n);
			}
		}
	}
	vector<vector<string>> solveNQueens(int n) {
		place.resize(n + 1, 0);
		placeQueen(1, n + 1);
		return result;
	}
};

int main() {
	Solution v;
	vector<vector<string>> result;
	vector<string> s;
	string line;
	result = v.solveNQueens(4);
	for (int i = 0; i < result.size(); i++) {
		s = result[i];
		for (int j = 0; j < s.size(); j++) {
			line = s[j];
			cout << line << endl;
		}
		cout << endl;
	}
	system("PAUSE");
	return 0;
}