#include<iostream>
#include<vector>
#include<queue>
#include<stdlib.h>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

class Solution {
public:
	static bool compare(pair<long, int> a, pair<long, int>b) {
		return a.first < b.first;
	}
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		int len = nums.size(), j;
		vector<pair<long, int>> check;
		if (len == 0)
			return false;
		for (int i = 0; i < len; i++)
			check.push_back(pair<long, int>((long)nums[i], i));
		sort(check.begin(), check.end(), compare);
		for (int i = 0; i < len; i++) {
			j = i + 1;
			while ((j < check.size()) && (abs(check[i].first - check[j].first) <= t)) {
				if (abs(check[i].second - check[j].second) <= k)
					return true;
				j++;
			}
		}
		return false;
	}
};

int main() {
	vector<int> nums = { -1, 2147483647 };
	int k = 2, t = 0;
	Solution v;
	if (v.containsNearbyAlmostDuplicate(nums, k, t))
		cout << "true" << endl;
	else
		cout << "false" << endl;
	system("PAUSE");
	return 0;
}