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
	int result = 0;
	vector<int> place;
public:
	bool isLegal(int row,int col) {
		for (int i = 1; i < row; i++) {
			if ((place[i] == col) || (abs(row - i) == abs(col - place[i])))
				return false;
		}
		return true;
	}
	void placeQueen(int row,int n) {
		if (row == n) {
			result++;
			return;
		}
		for (int i = 1; i < n; i++) {
			place[row] = i;
			if (isLegal(row,i)) {
				placeQueen(row + 1, n);
			}
		}
	}
	int totalNQueens(int n) {
		place.resize(n + 1, 0);
		placeQueen(1,n+1);
		return result;
	}
};

int main() {
	Solution v;
	cout << v.totalNQueens(5) << endl;
	system("PAUSE");
	return 0;
}