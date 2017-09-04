#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int result = 0;
		int crt[32] = { 0 };
		for (int i = 0; i < nums.size(); i++) {
			for (int j = 0; j < 32; j++) {
				crt[j] = crt[j] + ((nums[i] >> j) & 1);
				crt[j] = crt[j] % 3;
			}
		}
		for (int i = 0; i < 32; i++) {
			result = result + (crt[i] << i);
		}
		return result;
	}
};

int main() {
	vector<int> nums = {1,1,1,2,2,2,3};
	Solution s;
	cout << s.singleNumber(nums) << endl;
	//cout << sizeof(int) << endl;
	system("PAUSE");
	return 0;
}