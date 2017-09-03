#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<stdlib.h>
#include<queue>
using namespace std;

class Solution {
public:
	struct Node {
		int value;
		int rownum;
		int colnum;
	};
	struct cmp {
		bool operator() (const Node a, const Node b) {
			return a.value > b.value;
		}
	};
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		priority_queue<Node, vector<Node>,cmp> heap;
		int i, n, m, v, r, c;
		vector<int> line;
		Node cur;
		n = matrix.size();
		line = matrix[0];
		m = line.size();
		for (i = 0; i < m; i++) {
			cur.value = matrix[0][i];
			cur.rownum = 0;
			cur.colnum = i;
			heap.push(cur);
		}
		for (i = 0; i < k - 1; i++) {
			cur = heap.top();
			heap.pop();
			r = cur.rownum;
			v = cur.value;
			c = cur.colnum;
			if (r < n - 1) {
				cur.value = matrix[r + 1][c];
				cur.rownum = r + 1;
				cur.colnum = c;
				heap.push(cur);
			}
		}
		cur = heap.top();
		return cur.value;
	}
};

int main()
{
	Solution s;
	vector<vector<int>> matrix;
	int k = 8, i;
	vector<int> line;
	/*line.push_back(1);
	line.push_back(5);
	line.push_back(9);
	matrix.push_back(line);
	line.clear();
	line.push_back(10);
	line.push_back(11);
	line.push_back(13);
	matrix.push_back(line);
	line.clear();
	line.push_back(12);
	line.push_back(13);
	line.push_back(15);
	matrix.push_back(line);
	line.clear();
	for (i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}*/
	line.push_back(-5);
	matrix.push_back(line);
	k = 1;
	cout << s.kthSmallest(matrix, k) << endl;
	system("PAUSE");
	return 0;
}