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
#include<set>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		int ending, len=numbers.size(), i, current, mid, start, end;
		bool flag = false;
		vector<int> result;
		for (i = len - 1; i >= 0; i--) {
			current = target - numbers[i];
			end = i;
			start = 0;
			flag = false;
			while (end >= start) {
				mid = (start + end) / 2;
				if (current == numbers[mid]) {
					flag = true;
					break;
				}
				else if (current > numbers[mid]) {
					start = mid + 1;
				}
				else {
					end = mid - 1;
				}
			}
			if (flag) {
				result.push_back(mid + 1);
				result.push_back(i + 1);
				break;
			}
		}
		return result;
	}
};

int main() {
	Solution s;
	vector<int> numbers = { -3,3,4,9 }, result;
	int target = 0;
	result = s.twoSum(numbers, target);
	cout << result[0] << " " << result[1] << endl;
	system("PAUSE");
	return 0;
}