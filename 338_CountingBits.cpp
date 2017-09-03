#include<map>
#include<vector>
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	vector<int> countBits(int num) {
		vector<int> result(num+1, 0);
		int check = 2, bits = 2;
		result[1] = 1;
		for (int i = 2; i <= num; i++) {
			if (i == check) {
				result[i] = 1;
				bits = check;
				check = check << 1;
			}
			else {
				result[i] = result[i - bits] + 1;
			}
		}
		return result;
	}
};

int main() {
	int nums = 5;
	Solution s;
	vector<int> result;
	result = s.countBits(nums);
	for (int i = 0; i < result.size();i++)
		cout << result[i] << endl;
	system("PAUSE");
	return 0;
}