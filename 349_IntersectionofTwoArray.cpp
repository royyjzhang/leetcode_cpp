#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;

class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		unordered_map<int, int> checklist;
		vector<int> result;
		int i;
		for (i = 0; i < nums1.size(); i++) {
			if (checklist.find(nums1[i]) == checklist.end())
				checklist[nums1[i]] = 1;
		}
		for (i = 0; i < nums2.size(); i++) {
			if ((checklist.find(nums2[i]) != checklist.end()) && (checklist[nums2[i]] == 1)) {
				result.push_back(nums2[i]);
				checklist[nums2[i]] = 0;
			}
		}
		return result;
	}
};

int main()
{
	Solution s;
	vector<int> nums1 = { 1,2,2,1 }, nums2 = { 2,2 }, result;
	result = s.intersection(nums1, nums2);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	cout << endl;
	system("PAUSE");
	return 0;
}