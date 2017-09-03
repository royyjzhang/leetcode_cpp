#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		if (nums.size() == 0)
			return 0;
		vector<int> maxseq;
		maxseq.reserve(nums.size());
		maxseq.push_back(nums[0]);
		for (int i = 1; i < nums.size(); i++)
		{
			int now = nums[i], low = 0, high = maxseq.size(), mid;
			while (low < high)
			{
				mid = (low + high) / 2;
				if (now <= maxseq[mid])
					high = mid;
				else
					low = mid + 1;
			}
			if (high == maxseq.size())
				maxseq.push_back(now);
			else
				maxseq[high] = now;
		}
		return maxseq.size();
	}
};

int main()
{
	vector<int> nums;
	int num;
	Solution so;
	for (int i = 0; i < 8; i++)
	{
		cin >> num;
		nums.push_back(num);
	}
	cout << so.lengthOfLIS(nums) << endl;
	system("PAUSE");
	return 0;
}