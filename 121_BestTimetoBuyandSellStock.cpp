#include<iostream>
#include<vector>
#include<queue>
#include<stdlib.h>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int profit = 0, min;
		if (prices.size() == 0)
			return 0;
		min = prices[0];
		for (int i = 1; i < prices.size(); i++) {
			if (prices[i] < min) {
				min = prices[i];
			}
			if (prices[i] - min>profit)
				profit = prices[i] - min;
		}
		return profit;
	}
};

int main() {
	vector<int> prices = { 1, 2, 3, 2, 3, 4, 1, 1 };
	Solution s;
	cout << s.maxProfit(prices) << endl;
	system("PAUSE");
	return 0;
}