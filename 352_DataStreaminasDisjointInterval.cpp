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
#include<set>
#include<algorithm>
using namespace std;

/**
* Definition for an interval.*/
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class SummaryRanges {
private:
	vector<Interval> intervals;
	int binarysearch(int val) {
		int start = 0, end = intervals.size(), mid;
		while (start < end) {
			if ((start == end - 1) && (intervals[start].start <= val))
				return start;
			mid = (start + end) >> 1;
			if (intervals[mid].start == val)
				return mid;
			else if (intervals[mid].start <= val) {
				start = mid;
			}
			else {
				end = mid;
			}
		}
		return -1;
	}
public:
	/** Initialize your data structure here. */
	SummaryRanges() {
		intervals.reserve(10);
	}

	void addNum(int val) {
		int index = binarysearch(val);
		if ((index != -1) && (intervals[index].end >= val)) {
			return;
		}
		if ((index != -1) && (intervals[index].end + 1 == val)) {
			intervals[index].end = val;
		}
		else if ((index != intervals.size() - 1) && (intervals[index + 1].start == val + 1)) {
			intervals[index + 1].start = val;
		}
		else {
			//index++;
			intervals.insert(intervals.begin() + (index + 1), Interval(val, val));
		}
		if ((index != -1) && (intervals[index].end + 1== intervals[index + 1].start)) {
			intervals[index].end = intervals[index + 1].end;
			intervals.erase(intervals.begin() + index + 1);
		}
		return;
	}

	vector<Interval> getIntervals() {
		return intervals;
	}
};

/**
* Your SummaryRanges object will be instantiated and called as such:
* SummaryRanges obj = new SummaryRanges();
* obj.addNum(val);
* vector<Interval> param_2 = obj.getIntervals();
*/

int main() {
	SummaryRanges s;
	vector<Interval> result;
	s.addNum(1);
	result = s.getIntervals();
	for (int i = 0; i < result.size(); i++) {
		cout << "[" << result[i].start << ", " << result[i].end << "]";
	}
	cout << endl;
	s.addNum(3);
	result = s.getIntervals();
	for (int i = 0; i < result.size(); i++) {
		cout << "[" << result[i].start << ", " << result[i].end << "]";
	}
	cout << endl;
	s.addNum(2);
	result = s.getIntervals();
	for (int i = 0; i < result.size(); i++) {
		cout << "[" << result[i].start << ", " << result[i].end << "]";
	}
	cout << endl;
	s.addNum(7);
	result = s.getIntervals();
	for (int i = 0; i < result.size(); i++) {
		cout << "[" << result[i].start << ", " << result[i].end << "]";
	}
	cout << endl;
	s.addNum(6);
	result = s.getIntervals();
	for (int i = 0; i < result.size(); i++) {
		cout << "[" << result[i].start << ", " << result[i].end << "]";
	}
	cout << endl;
	system("PAUSE");
	return 0;
}