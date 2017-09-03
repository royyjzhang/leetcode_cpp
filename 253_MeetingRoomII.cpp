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
using namespace std;

struct Interval {
	int start;
	int end;
	Interval() {
		start = 0;
		end = 0;
	}
	Interval(int s, int e) {
		start = s;
		end = e;
	}
};

bool compare_start(Interval a, Interval b) {
	return a.start < b.start;
}

struct mini_heap {
	bool operator()(int a, int b) {
		return a > b;
	}
};

class Solution {
public:
	int minMeetingRooms(vector<Interval>& intervals) {
		int n = intervals.size(), result = 0;
		priority_queue<int, vector<int>, mini_heap> endTimeCheck;
		if (n == 0)
			return result;
		sort(intervals.begin(), intervals.end(), compare_start);
		endTimeCheck.push(intervals[0].end);
		result++;
		for (int i = 1; i < intervals.size(); i++) {
			if (endTimeCheck.top() > intervals[i].start) {
				result++;
				endTimeCheck.push(intervals[i].end);
			}
			else {
				endTimeCheck.pop();
				endTimeCheck.push(intervals[i].end);
			}
		}
		return result;
	}
};


int main() {
	Solution solution;
	vector<Interval> intervals;
	Interval now;
	now.start = 0;
	now.end = 30;
	intervals.push_back(now);
	now.start = 0;
	now.end = 30;
	intervals.push_back(now);
	now.start = 5;
	now.end = 10;
	intervals.push_back(now);
	now.start = 15;
	now.end = 20;
	intervals.push_back(now);
	cout << solution.minMeetingRooms(intervals) << endl;
	system("PAUSE");
	return 0;
}