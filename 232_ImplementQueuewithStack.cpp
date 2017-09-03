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

class Queue {
private:
	stack<int> output, input;
public:
	// Push element x to the back of queue.
	void push(int x) {
		if (output.empty()) {
			input.push(x);
		}
		else {
			while (!output.empty()) {
				input.push(output.top());
				output.pop();
			}
			input.push(x);
		}
	}

	// Removes the element from in front of queue.
	void pop(void) {
		if (input.empty()) {
			output.pop();
		}
		else {
			while (!input.empty()) {
				output.push(input.top());
				input.pop();
			}
			output.pop();
		}
	}

	// Get the front element.
	int peek(void) {
		if (input.empty()) {
			return output.top();
		}
		else {
			while (!input.empty()) {
				output.push(input.top());
				input.pop();
			}
			return output.top();
		}
	}

	// Return whether the queue is empty.
	bool empty(void) {
		if ((input.empty()) && (output.empty())) {
			return true;
		}
		else {
			return false;
		}
	}
};

int main() {
	Queue q;
	q.push(1);
	q.push(2);
	q.push(3);
	cout << q.peek() << endl;
	q.pop();
	cout << q.empty() << endl;
	cout << q.peek() << endl;
	q.pop();
	cout << q.peek() << endl;
	q.pop();
	cout << q.empty() << endl;
	system("PAUSE");
	return 0;
}