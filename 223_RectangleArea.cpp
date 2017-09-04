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
private:
	int difference(int l1, int r1, int l2, int r2) {
		if ((r1 <= l2) || (r2 <= l1)) {
			return 0;
		}
		else if (((l1 < l2) && (r1 > l2) && (r1 < r2)) || ((l2 > l1) && (l2 < r1) && (r2 > r1))) {
			return abs(r1 - l2);
		}
		else if (((l1 > l2) && (l1 < r2) && (r1 > r2)) || ((l2 < l1) && (r2 > l1) && (r2 < r1))) {
			return abs(r2 - l1);
		}
		else if ((l1 >= l2) && (r1 <= r2)) {
			return r1 - l1;
		}
		else if ((l2 >= l1) && (r2 <= r1)) {
			return r2 - l2;
		}
	}
public:
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		int differX, differY;
		differX = difference(A, C, E, G);
		differY = difference(B, D, F, H);
		return (C-A)*(D-B)+(G-E)*(H-F)-differX*differY;
	}
};

int main() {
	Solution solution;
	//int A = -3, B = 0, C = 3, D = 4, E = 0, F = -1, G = 9, H = 2;
	//int A = -2, B = -2, C = 2, D = 2, E = -2, F = -2, G = 2, H = 2;
	int A = -2, B = -2, C = 2, D = 2, E = -1, F = -1, G = 1, H = 1;
	cout << solution.computeArea(A, B, C, D, E, F, G, H) << endl;
	system("PAUSE");
	return 0;
}