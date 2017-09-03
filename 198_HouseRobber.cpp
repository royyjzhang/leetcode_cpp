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
using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		int len = nums.size(), max = 0;
		if (len <= 0)
			return 0;
		vector<int> result(len + 2, 0);
		for (int i = 2; i < len + 2; i++) {
			if (result[i - 2] + nums[i - 2]>result[i - 1])
				result[i] = result[i - 2] + nums[i - 2];
			else
				result[i] = result[i - 1];
		}
		return result[len + 1];
	}
};

int main() {
	vector<int> line = {1,2,3,4,5};
	Solution s;
	cout << s.rob(line) << endl;
	system("PAUSE");
	return 0;
}