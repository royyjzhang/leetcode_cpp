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
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int tail1 = m - 1, tail2 = n - 1, tail = m + n - 1;
		while (tail >= 0) {
			if (tail1 < 0) {
				nums1[tail] = nums2[tail2];
				tail2--;
			}
			else if (tail2 < 0) {
				nums1[tail] = nums1[tail1];
				tail1--;
			}
			else if (nums1[tail1] > nums2[tail2]) {
				nums1[tail] = nums1[tail1];
				tail1--;
			}
			else {
				nums1[tail] = nums2[tail2];
				tail2--;
			}
			tail--;
		}
	}
};

int main() {
	Solution s;
	int m = 5, n = 2;
	vector<int> nums1 = { 1,2,3,4,5,0,0 }, nums2 = { 6,7 };
	s.merge(nums1, m, nums2, n);
	for (int i = 0; i < nums1.size(); i++) {
		cout << nums1[i] << " ";
	}
	cout << endl;
	system("PAUSE");
	return 0;
}