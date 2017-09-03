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
	vector<int> lexicalOrder(int n) {
		stack<int> s;
		int i, cur, next;
		vector<int> result;
		for (i = 9; i > 0; i--) {
			s.push(i);
		}
		while (!s.empty()) {
			cur = s.top();
			s.pop();
			if (cur <= n) {
				result.push_back(cur);
				for (i = 9; i >= 0; i--) {
					next = cur * 10 + i;
					if (next <= n) {
						s.push(next);
					}
				}
			}			
		}
		return result;
	}
};

int main() {
	Solution solution;
	vector<int> result;
	int n = 80;
	result = solution.lexicalOrder(n);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	cout << endl;
	system("PAUSE");
	return 0;
}