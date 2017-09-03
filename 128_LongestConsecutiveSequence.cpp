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

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		int n = nums.size(), result = 0, now, ans, next;
		if (n == 0)
			return 0;
		unordered_set<int> s(nums.begin(),nums.end());
		unordered_set<int>::iterator iter;
		while (!s.empty()) {
			iter = s.begin();
			ans = 1;
			now = *iter;
			next = *iter + 1;
			while (s.find(next)!=s.end()) {
				s.erase(next);
				next++;
				ans++;				
			}
			next = *iter - 1;
			while (s.find(next) != s.end()) {
				s.erase(next);
				next--;
				ans++;
			}
			if (result < ans) {
				result = ans;
			}
			s.erase(now);
		}
		return result;
	}
};

int main() {
	Solution solution;
	vector<int> nums = { 100,99,4,3,1,2 };
	cout << solution.longestConsecutive(nums) << endl;
	system("PAUSE");
	return 0;
}