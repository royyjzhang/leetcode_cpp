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
using namespace std;

class Stack {
private:
	queue<int> stacklike;
public:
	// Push element x onto stack.
	void push(int x) {
		queue<int> q;
		q.push(x);
		while (!stacklike.empty()) {
			q.push(stacklike.front());
			stacklike.pop();
		}
		stacklike = q;
	}

	// Removes the element on top of the stack.
	void pop() {
		stacklike.pop();
	}

	// Get the top element.
	int top() {
		return stacklike.front();		
	}

	// Return whether the stack is empty.
	bool empty() {
		return stacklike.empty();
	}
};

int main() {
	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	s.pop();
	system("PAUSE");
	return 0;
}