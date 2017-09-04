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
#include<set>
#include<algorithm>
using namespace std;

class Solution {
public:
	string reverseVowels(string s) {
		const set<char> VOWEL = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };
		int BeginPointer=0, EndPointer=s.length();
		char temp;
		while (BeginPointer < EndPointer) {
			while (VOWEL.find(s[BeginPointer]) == VOWEL.end()) {
				BeginPointer++;
			}
			while (VOWEL.find(s[EndPointer]) == VOWEL.end()) {
				EndPointer--;
			}
			if (BeginPointer < EndPointer) {
				temp = s[BeginPointer];
				s[BeginPointer] = s[EndPointer];
				s[EndPointer] = temp;
				BeginPointer++;
				EndPointer--;
			}
		}
		return s;
	}
};

int main() {
	string s = "leetcode";
	Solution t;
	cout << t.reverseVowels(s) << endl;
	system("PAUSE");
	return 0;
}