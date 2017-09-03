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
#include<sstream>
#include<unordered_map>
#include<unordered_set>
#include<time.h>
#include<thread>
#include<mutex>
#include<Windows.h>
using namespace std;

/**
* Definition for an interval.*/
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool lessinterval(const Interval a, const Interval b) {
	return ((a.start < b.start) || ((a.start == b.start) && (a.end < b.end)));
}

class Solution {
public:
	vector<Interval> merge(vector<Interval>& intervals) {
		int n = intervals.size(), i;
		if ((n == 0) || (n==1)) {
			return intervals;
		}
		sort(intervals.begin(), intervals.end(), lessinterval);
		vector<Interval> result;
		for (i = 1; i < n; i++) {
			if (intervals[i - 1].end < intervals[i].start) {
				result.push_back(intervals[i - 1]);
			}
			else if (intervals[i - 1].end >= intervals[i].start) {
				intervals[i].start = intervals[i - 1].start;
				intervals[i].end = max(intervals[i].end, intervals[i - 1].end);
			}
			if (i + 1 == n) {
				result.push_back(intervals[i]);
			}
		}
		return result;
	}
};

int main() {
	Solution solution;
	vector<Interval> intervals, result;
	Interval now;
	now.start = 1;
	now.end = 3;
	intervals.push_back(now);
	now.start = 2;
	now.end = 6;
	intervals.push_back(now);
	now.start = 8;
	now.end = 10;
	intervals.push_back(now);
	now.start = 15;
	now.end = 18;
	intervals.push_back(now);
	result = solution.merge(intervals);
	for (int i = 0; i < result.size(); i++) {
		cout << "[" << result[i].start << "," << result[i].end << "]" << endl;
	}
	system("PAUSE");
	return 0;
}