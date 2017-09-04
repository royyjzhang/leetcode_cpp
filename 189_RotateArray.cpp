#include<iostream>
#include<vector>
#include<queue>
#include<stdlib.h>
#include<string>
#include<algorithm>
#include<map>
#include<math.h>
using namespace std;

class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		int len = nums.size();
		if (len == 0)
			return;
		int maxindex = k % len, j, value, tmp, next;
		for (int i = 0; i < maxindex; i++) {
			j = i;
			value = nums[j];
			do {
				next = (j + k) % len;
				tmp = nums[next];
				nums[next] = value;
				value = tmp;
				if ((next < maxindex) && (next != i))
					maxindex = next;
				j = next;
			} while (j != i);
		}
	}
};

int main() {
	vector<int> nums = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int k = 3;
	Solution v;
	v.rotate(nums,k);
	for (int i = 0; i < nums.size(); i++)
		cout << nums[i] << " ";
	system("PAUSE");
	return 0;
}