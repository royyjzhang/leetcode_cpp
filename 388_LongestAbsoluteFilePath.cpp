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
	int lengthLongestPath(string input) {
		stringstream ss(input);
		int result = 0, count, pos;
		string current;
		vector<int> level;
		while (getline(ss, current, '\n')) {
			count = 0;
			pos = current.find_last_of('\t');
			if (pos == string::npos) {
				count = 0;
			}
			else {
				count = pos + 1;
			}
			pos = current.find('.');
			if (pos == string::npos) {
				if (level.size() == 0) {
					level.push_back(current.length() - count);
				}
				else if (level.size() < count + 1) {
					level.push_back(level[count - 1] + current.length() - count);
				}
				else {
					level[count] = level[count - 1] + current.length() - count;
				}
			}
			else {
				if (level.size() == 0) {
					if (result < (int)(current.length())) {
						result = (int)(current.length());
					}
				}				
				else if (level.size() >= count) {
					if (result < (int)(level[count - 1] + current.length())) {
						result = (int)(level[count - 1] + current.length());
					}
				}
			}
		}
		return result;
	}
};

int main() {
	Solution s;
	string input = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext";
	cout << s.lengthLongestPath(input) << endl;
	system("PAUSE");
	return 0;
}