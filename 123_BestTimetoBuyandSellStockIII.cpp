#include<iostream>
#include<vector>
#include<queue>
#include<stdlib.h>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int profit = 0, tmp = 0;
		int len = prices.size();
		if (len == 0)
			return 0;
		vector<int> nowmin(len, 0), nowmax(len, 0);
		nowmin[0] = prices[0];
		for (int i = 1; i < len; i++) {
			if (nowmin[i - 1] < prices[i])
				nowmin[i] = nowmin[i - 1];
			else
				nowmin[i] = prices[i];
		}
		nowmax[len - 1] = prices[len - 1];
		for (int i = len - 2; i >= 0; i--) {
			if (nowmax[i + 1]>prices[i])
				nowmax[i] = nowmax[i + 1];
			else
				nowmax[i] = prices[i];
		}
		for (int i = 0; i < len; i++) {
			if (tmp < (prices[i] - nowmin[i]))
				tmp = prices[i] - nowmin[i];
			if (profit < (tmp + nowmax[i] - prices[i]))
				profit = tmp + nowmax[i] - prices[i];
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