#include<iostream>
#include<vector>
#include<queue>
#include<stdlib.h>
using namespace std;

class Solution {
public:
	int maxProfit(int k, vector<int>& prices) {
		int len = prices.size(), profit = 0;
		if ((k == 0) || (len == 0))
			return 0;
		if (k > len / 2) {
			for (int i = 1; i < len; i++) {
				if (prices[i] - prices[i - 1]>0)
					profit += prices[i] - prices[i - 1];
			}
			return profit;
		}
		else {
			vector<int> prev(len, 0), cur(len, 0);
			int newlowest;
			for (int j = 0; j < k; j++) {
				newlowest = prices[0];
				for (int i = 1; i < len; i++) {
					if (cur[i - 1] < prices[i] - newlowest)
						cur[i] = prices[i] - newlowest;
					else
						cur[i] = cur[i - 1];
					if (newlowest>prices[i] - prev[i - 1])
						newlowest = prices[i] - prev[i - 1];
				}
				prev = cur;
			}
			return cur[len - 1];
		}
	}
};

int main() {
	vector<int> prices = { 1, 2, 3, 2, 3, 4, 1, 1 };
	Solution s;
	int k = 2;
	cout << s.maxProfit(k, prices) << endl;
	system("PAUSE");
	return 0;
}