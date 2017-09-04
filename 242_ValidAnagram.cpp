#include<iostream>
#include<vector>
#include<queue>
#include<stdlib.h>
#include<string>
using namespace std;

class Solution {
public:
	bool isAnagram(string s, string t) {
		int check[26] = { 0 };
		if (s.length() != t.length())
			return false;
		int len = s.length();
		char c;
		for (int i = 0; i < s.length(); i++) {
			c = s[i];
			check[c - 97]++;
			c = t[i];
			check[c - 97]--;
		}
		for (int i = 0; i < 26; i++)
			if (check[i] != 0)
				return false;
		return true;
	}
};

int main() {
	string s = "anagram", t = "nagbram";
	Solution v;
	if (v.isAnagram(s, t))
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	system("PAUSE");
	return 0;
}