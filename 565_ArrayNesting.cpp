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
#include<time.h>
#include<iomanip>
using namespace std;

class Solution {
public:
	int arrayNesting(vector<int>& nums) {
		int maxsize = 0, size = 0, k = 0, current = 0;
		for (int i = 0; i < nums.size(); i++) {
			size = 0;
			k = i;
			while (nums[k] >= 0) {
				current = nums[k];
				nums[k] = -1;
				k = current;
				size++;
			}
			if (size > maxsize) {
				maxsize = size;
			}
		}
		return maxsize;
	}
};

int main() {
	Solution solution;
	vector<int> nums = { 5, 4, 0, 3, 1, 6, 2 };
	cout << solution.arrayNesting(nums) << endl;
	system("PAUSE");
	return 0;
}