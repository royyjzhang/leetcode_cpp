#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;

class NumArray {
private:
	vector<int> numarray;
public:
	NumArray(vector<int> &nums) {
		numarray.push_back(0);
		for (int i = 0; i < nums.size(); i++)
		{
			numarray.push_back(nums[i] + numarray[i]);
		}
	}

	int sumRange(int i, int j) {
		int sum;
		sum = numarray[j + 1]-numarray[i];
		return sum;
	}
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);

int main()
{
	vector<int> nums;
	int num;
	int a, b;
	for (int i = 0; i < 10; i++)
	{
		cin >> num;
		nums.push_back(num);
	}
	NumArray numarray(nums);
	while (true)
	{
		cout << "input two index" << endl;
		cin >> a >> b;
		if (a < 0)
			break;
		cout << numarray.sumRange(a,b)<< endl;
	}
	return 0;
}