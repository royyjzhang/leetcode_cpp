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
	bool isValid(string s) {
		stack<char> st;
		char now;
		if (s.length() == 0)
			return true;
		for (int i = 0; i < s.length(); i++) {
			if ((s[i] == '(') || (s[i] == '{') || (s[i] == '[')) {
				st.push(s[i]);
			}
			else if (s[i] == ')') {
				if (st.empty())
					return false;
				now = st.top();
				st.pop();
				if (now != '(') {
					return false;
				}
			}
			else if (s[i] == '}') {
				if (st.empty())
					return false;
				now = st.top();
				st.pop();
				if (now != '{') {
					return false;
				}
			}
			else if (s[i] == ']') {
				if (st.empty())
					return false;
				now = st.top();
				st.pop();
				if (now != '[') {
					return false;
				}
			}
		}
		if (st.empty()) {
			return true;
		}
		else {
			return false;
		}
	}
};

int main() {
	Solution s;
	string ss = "({[})]";
	if (s.isValid(ss)) {
		cout << "True" << endl;
	}
	else {
		cout << "False" << endl;
	}
	system("PAUSE");
	return 0;
}