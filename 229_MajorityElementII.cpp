#include<iostream>
#include<vector>
#include<queue>
#include<stdlib.h>
#include<string>
#include<algorithm>
#include<map>
using namespace std;

class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {
		int count1 = 0, count2 = 0, num1 = 0, num2 = 0;
		int len = nums.size();
		vector<int> result;
		if (len == 0)
			return result;
		for (int i = 0; i < len; i++) {  //select two nums showing the most time until i
			if ((count1 == 0) && (num2!=nums[i]))
				num1 = nums[i];
			else if ((count2 == 0) && (num1 != nums[i]))
				num2 = nums[i];
			if (nums[i] == num1)
				count1++;
			else if (nums[i] == num2)
				count2++;
			else {
				count1--;
				count2--;
			}
		}
		if (count(nums.begin(), nums.end(), num1) > len / 3)
			result.push_back(num1);
		if ((count(nums.begin(), nums.end(), num2) > len / 3) && (num1!=num2))
			result.push_back(num2);
		return result;
	}
};

int main() {
	vector<int> nums = { 1, 2, 2, 3, 2, 1, 1, 3 }, result;
	Solution v;
	result = v.majorityElement(nums);
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << endl;
	system("PAUSE");
	return 0;
}