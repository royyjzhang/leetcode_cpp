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
	int maxArea(vector<int>& height) {
		int i = 0, j, k, result = 0, temp, n = height.size();
		if (n == 0) {
			return 0;
		}
		j = n - 1;
		while (i < j) {
			temp = (j - i)*min(height[i], height[j]);
			if (temp > result) {
				result = temp;
			}
			if (height[i] > height[j]) {
				k = j - 1;
				while ((k>=0) && height[j] >= height[k]) {
					k--;
				}
				j = k;
			}
			else {
				k = i + 1;
				while ((k<n) && (height[i] >= height[k])) {
					k++;
				}
				i = k;
			}
		}
		return result;
	}
};

int main() {
	Solution solution;
	vector<int> height = { 1,2,3,4,5,6 };
	cout << solution.maxArea(height) << endl;
	system("PAUSE");
	return 0;
}