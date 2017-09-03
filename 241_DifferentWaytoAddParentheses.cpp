#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<stdlib.h>
#include<queue>
#include<ctype.h>
#include<sstream>
using namespace std;

class Solution {
public:
	vector<int> dfs(string input, bool finalflag) {
		vector<int> result;
		for (int i = 0; i < input.length(); i++) {
			if (!isdigit(input[i])) {
				vector<int> left = dfs(input.substr(0, i), false);
				vector<int> right = dfs(input.substr(i + 1, input.length()), false);
				for (int l = 0; l < left.size(); l++) {
					for (int r = 0; r < right.size(); r++) {
						if (input[i] == '+') {
							result.push_back(left[l] + right[r]);
						}
						else if (input[i] == '-') {
							result.push_back(left[l] - right[r]);
						}
						else if (input[i] == '*') {
							result.push_back(left[l] * right[r]);
						}
					}
				}
			}
		}
		if (result.empty()) {
			int num;
			stringstream ss;
			ss << input;
			ss >> num;
			result.push_back(num);
		}
		return result;
	}
	vector<int> diffWaysToCompute(string input) {
		return dfs(input, true);
	}
};

int main()
{
	Solution s;
	vector<int> result;
	string input = "2-1-1";
	result = s.diffWaysToCompute(input);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	cout << endl;
	system("PAUSE");
	return 0;
}