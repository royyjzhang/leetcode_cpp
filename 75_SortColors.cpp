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
	void sortColors(vector<int>& nums) {
		int n = nums.size(), numr = 0, numw = 0, numb = 0;
		if (n == 0)
			return;
		for (int i = 0; i < n; i++) {
			if (nums[i] == 0) {
				numr++;
			}
			else if (nums[i] == 1) {
				numw++;
			}
			else if (nums[i] == 2) {
				numb++;
			}
		}
		for (int i = 0; i < numr; i++) {
			nums[i] = 0;
		}
		for (int i = numr; i < numr + numw; i++) {
			nums[i] = 1;
		}
		for (int i = numr + numw; i < n; i++) {
			nums[i] = 2;
		}
	}
};

int main() {
	Solution solution;
	vector<int> nums = { 0,2,2,2,1,0 };
	solution.sortColors(nums);
	for (int i = 0; i < nums.size(); i++) {
		cout << nums[i] << " ";
	}
	cout << endl;
	system("PAUSE");
	return 0;
}