#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;

class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		int count[26] = { 0 };
		if (ransomNote.length() > magazine.length())
			return false;
		if (ransomNote.length() == 0)
			return true;
		for (int i = 0; i <  magazine.length(); i++) {
			count[magazine[i] - 'a']++;
		}
		for (int i = 0; i < ransomNote.length(); i++) {
			if (count[ransomNote[i] - 'a'] == 0)
				return false;
			else
				count[ransomNote[i] - 'a']--;
		}
		return true;
	}
};

int main()
{
	Solution s;
	string ransomnote = "aa", magazine = "aab";
	cout << s.canConstruct(ransomnote, magazine) << endl;
	system("PAUSE");
	return 0;
}