#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		unordered_map<int, int> dict;
		vector<int> result;
		for (int i = 0; i < int(nums1.size()); i++) {
			if (dict.find(nums1[i]) == dict.end())
				dict[nums1[i]] = 1;
			else
				dict[nums1[i]]++;
		}
		for (int i = 0; i < int(nums2.size()); i++) {
			if ((dict.find(nums2[i]) != dict.end()) && (dict[nums2[i]]>0)) {
				result.push_back(nums2[i]);
				dict[nums2[i]]--;
			}
		}
		return result;
	}
};

int main()
{
	Solution s;
	vector<int> num1 = { 1,2,2,1 }, num2 = { 2 }, result;
	result = s.intersect(num1, num2);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	cout << endl;
	system("PAUSE");
	return 0;
}