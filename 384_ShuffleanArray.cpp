#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<stdlib.h>
using namespace std;

class Solution {
private:
	vector<int> origin, output;
public:
	Solution(vector<int> nums) {
		origin = nums;
		output = nums;
	}

	/** Resets the array to its original configuration and return it. */
	vector<int> reset() {
		output = origin;
		return output;
	}

	/** Returns a random shuffling of the array. */
	vector<int> shuffle() {
		int len = int(output.size()), r;
		for (int i = 0; i < len; i++) {
			r = rand() % len;
			swap(output[i], output[r]);
		}
		return output;
	}
};

/**
* Your Solution object will be instantiated and called as such:
* Solution obj = new Solution(nums);
* vector<int> param_1 = obj.reset();
* vector<int> param_2 = obj.shuffle();
*/

int main()
{
	vector<int> nums = { 1,2,3 }, result;
	Solution s(nums);
	result = s.shuffle();
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	cout << endl; 
	result = s.shuffle();
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	cout << endl;
	result = s.reset();
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	cout << endl;
	system("PAUSE");
	return 0;
}