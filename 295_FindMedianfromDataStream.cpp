#include<iostream>
#include<queue>
#include<vector>
#include<cstdlib>
#include<functional>
using namespace std;

class MedianFinder {
private:
	priority_queue<int> first_half;
	priority_queue<int, vector<int>, greater<int>> second_half;
public:

	// Adds a number into the data structure.
	void addNum(int num) {
		first_half.push(num);
		while ((second_half.empty()) || (!first_half.empty() && first_half.top() > second_half.top()))
		{
			second_half.push(first_half.top());
			first_half.pop();
		}
		while (first_half.size() < second_half.size())
		{
			first_half.push(second_half.top());
			second_half.pop();
		}
		while (first_half.size() > second_half.size() + 1)
		{
			second_half.push(first_half.top());
			first_half.pop();
		}
	}

	// Returns the median of current data stream
	double findMedian() {
		if (first_half.size() == second_half.size())
			return static_cast<double> (first_half.top() + second_half.top()) / 2.0;
		else
			return static_cast<double> (first_half.top());
	}
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();

int main()
{
	MedianFinder mf;
	int num;
	for (int i = 0; i < 10; i++)
	{
		cin >> num;
		mf.addNum(num);
		cout << "Median is " << mf.findMedian() << endl;
	}
}