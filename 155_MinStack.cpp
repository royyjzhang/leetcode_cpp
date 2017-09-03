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
using namespace std;

class MinStack {
private:
	stack<int> s;
	int min;
public:
	/** initialize your data structure here. */
	MinStack() {
		min = 0;
	}

	void push(int x) {
		if (s.empty()) {
			s.push(x);
			min = x;
		}
		else if ((x<min) ||(x==min)) {
			s.push(min);
			s.push(x);
			min = x;
		}
		else {
			s.push(x);
		}
	}

	void pop() {
		if (s.empty()) {
			return;
		}
		else if (s.top() == min) {
			s.pop();
			if (!s.empty()) {
				min = s.top();
				s.pop();
			}
		}
		else {
			s.pop();
		}
	}

	int top() {
		return s.top();
	}

	int getMin() {
		return min;
	}
};

/**
* Your MinStack object will be instantiated and called as such:
* MinStack obj = new MinStack();
* obj.push(x);
* obj.pop();
* int param_3 = obj.top();
* int param_4 = obj.getMin();
*/

int main() {
	MinStack m;
	m.push(1);
	m.push(10);
	m.push(-10);
	cout << m.top() << endl;
	cout << m.getMin() << endl;
	m.pop();
	cout << m.top() << endl;
	cout << m.getMin() << endl;
	system("PAUSE");
	return 0;
}