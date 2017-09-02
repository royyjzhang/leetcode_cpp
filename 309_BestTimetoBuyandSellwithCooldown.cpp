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
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int len = prices.size(), max=0;
		vector<int> result(len + 2, 0);
		for (int i = 3; i < len+2; i++) {
			max = 0;
			for (int j = 2; j < i; j++) {
				if (result[j - 2] + prices[i - 2] - prices[j - 2]>max)
					max = result[j - 2] + prices[i - 2] - prices[j - 2];
				else if (result[j]>max)
					max = result[j];
			}
			result[i] = max;
		}
		max = 0;
		for (int i = 3; i < len + 2; i++) {
			if (result[i]>max)
				max = result[i];
		}
		return max;
	}
};

int main() {
	int result;
	vector<int> prices = { 6,1,6,4,3,0,2 };
	Solution s;
	cout << s.maxProfit(prices) << endl;
	system("PAUSE");
	return 0;
}