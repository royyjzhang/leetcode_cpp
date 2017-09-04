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
	int sumLongestPath(string input) {
		stringstream ss(input);
		int result = 0, count, pos;
		string current, ext;
		vector<int> level;
		vector<bool> checked;
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
					checked.push_back(false);
				}
				else if (level.size() < count + 1) {
					level.push_back(level[count - 1] + current.length() - count);
					checked.push_back(false);
				}
				else {
					level[count] = level[count - 1] + current.length() - count;
					checked[count] = false;
				}
			}
			else {
				ext = current.substr(pos + 1,current.length());
				if (ext == "ext") {
					if ((!(level.size() == 0)) && (checked[count - 1]==false)) {
						result += level[count - 1];
						checked[count - 1] = true;
					}
				}
			}
		}
		return result;
	}
};

int main() {
	Solution s;
	string input = "dir\n\tsubdir1\n\t\tfile1.ext\n\tfile3.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext\n\tfile4.ext";
	cout << s.sumLongestPath(input) << endl;
	system("PAUSE");
	return 0;
}