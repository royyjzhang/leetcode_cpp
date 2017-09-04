#include<iostream>
#include<vector>
#include<queue>
#include<stdlib.h>
#include<string>
#include<algorithm>
#include<map>
#include<math.h>
using namespace std;

class Solution {
public:
	int maxProduct(vector<string>& words) {
		int len = words.size();
		vector<int> check(len, 0);
		int result = 0;
		string s;
		if (len < 2)
			return 0;
		for (int i = 0; i < len; i++) {
			s = words[i];
			for (int j = 0; j < s.length(); j++) {
				check[i] = check[i] | (1 << (s[j] - 'a'));
			}
		}
		for (int i = 0; i < len; i++) {
			for (int j = i + 1; j < len; j++) {
				if (((check[i] & check[j]) == 0) && (words[i].length()*words[j].length()>result)) {
					result = words[i].length()*words[j].length();
				}
			}
		}
		return result;
	}
};

int main() {
	vector<string> words = { "abcw", "baz", "foo", "bar", "xtfn", "abcdef" };
	Solution v;
	cout << v.maxProduct(words) << endl;
	system("PAUSE");
	return 0;
}