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
using namespace std;

class Solution {
private:
	vector<int> nums;
public:
	Solution(vector<int> nums) {
		this->nums = nums;
		srand(time(NULL));
	}

	int pick(int target) {
		int count = 0;
		int index = -1;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == target) {
				count++;
				if (rand() % count == 0) {
					index = i;
				}
			}
		}
		return index;
	}
};

/**
* Your Solution object will be instantiated and called as such:
* Solution obj = new Solution(nums);
* int param_1 = obj.pick(target);
*/

int main() {	
	vector<int> nums = { 0,0,1,2,2,3 };
	Solution solution(nums);
	for (int i = 0; i < 20; i++) {
		cout << solution.pick(2) << endl;
	}
	system("PAUSE");
	return 0;
}