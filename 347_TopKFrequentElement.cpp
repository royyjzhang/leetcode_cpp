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
#include<algorithm>
using namespace std;

class Solution {
private:
	struct Node {
		int num = 0;
		int times = 0;
	};
	static bool cmp(const Node &a, const Node &b) {
		return a.times > b.times;
	}
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end());
		Node now;
		vector<Node> frequency;
		vector<int> result;
		now.num = nums[0];
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == now.num) {
				now.times++;
			}
			else {
				frequency.push_back(now);
				now.num = nums[i];
				now.times = 1;
			}
		}
		frequency.push_back(now);
		sort(frequency.begin(), frequency.end(), cmp);
		for (int i = 0; i < k; i++) {
			result.push_back(frequency[i].num);
		}
		return result;
	}
};

int main() {
	vector<int> s = { 1, 1, 1, 2, 2, 3 },result;
	int k = 2;
	Solution t;
	result = t.topKFrequent(s, k);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}
	system("PAUSE");
	return 0;
}