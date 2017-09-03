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
using namespace std;

class Solution {
public:
	int hIndex(vector<int>& citations) {
		int n, i, now, start, end;
		n = citations.size();
		if (n == 0) {
			return 0;
		}
		start = 0;
		end = n - 1;
		if (citations[n - 1] == 0)
			return 0;
		if (citations[0] > end) {
			return n;
		}
		while (end - start > 1) {
			now = (start + end) >> 1;
			if (citations[n - 1 - now] > now) {
				start = now;
			}
			else {
				end = now;
			}
		}
		return start + 1;
	}
};

int main() {
	Solution solution;
	vector<int> citations = { 0,0,1,2,2,3 };
	cout << solution.hIndex(citations) << endl;
	system("PAUSE");
	return 0;
}