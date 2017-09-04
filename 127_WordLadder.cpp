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

struct Node {
	string word;
	int step;
};

class Solution {
public:
	int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
		queue<Node> q;
		int i;
		Node nowWord, nWord;
		char c;
		string newWord;
		unordered_set<string> checkList;
		if (beginWord == endWord) {
			return 0;
		}
		nowWord.word = beginWord;
		nowWord.step = 1;
		q.push(nowWord);
		checkList.insert(beginWord);
		while (!q.empty()) {
			nowWord = q.front();
			q.pop();
			if (nowWord.word == endWord) {
				return nowWord.step;
			}
			for (i = 0; i < nowWord.word.length(); i++) {
				newWord = nowWord.word;
				for (c = 'a'; c <= 'z'; c++) {
					newWord[i] = c;
					if (newWord == endWord) {
						return nowWord.step + 1;
					}
					if ((wordList.find(newWord) != wordList.end()) && (checkList.find(newWord)==checkList.end())) {
						nWord.word = newWord;
						nWord.step = nowWord.step + 1;
						checkList.insert(newWord);
						q.push(nWord);
					}
				}
			}
		}
		return 0;
	}
};

int main() {
	Solution solution;
	string beginWord = "hit", endWord = "cog";
	unordered_set<string> wordList = { "hot","dot","dog","lot","log" };
	cout << solution.ladderLength(beginWord, endWord, wordList) << endl;
	system("PAUSE");
	return 0;
}