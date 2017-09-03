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
		unordered_map<int, int> frequency;
		int curh = 0, cites = 0, i;
		if (citations.size() == 0)
			return 0;
		for (i = 0; i < citations.size(); i++) {
			if (citations[i] > curh) {
				if (cites - frequency[curh] >= curh) {
					cites += 1 - frequency[curh];
					curh++;
				}
				else {
					cites++;
				}
			}
			else if (citations[i]==curh) {
				cites++;
			}
			frequency[citations[i]]++;
		}
		return curh;
	}
};

int main() {
	Solution solution;
	vector<int> citations = { 3,0,6,1,5 };
	cout << solution.hIndex(citations) << endl;
	system("PAUSE");
	return 0;
}