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

class Solution {
public:
	vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
		unordered_map<string, int> map;
		int n = equations.size(), m=queries.size(), nodes, a, b;
		vector<double> result;
		if (m == 0) {
			return result;
		}
		result.resize(m);
		for (int i = 0; i < m; i++) {
			result[i] = -1.0;
		}
		if (n == 0) {
			return result;
		}
		vector<vector<double>> graph(2*n,vector<double>(2*n,-1.0));
		vector<vector<bool>> linked(2 * n, vector<bool>(2 * n, false));
		nodes = 0;
		for (int i = 0; i < n; i++) {
			if (map.find(equations[i].first) == map.end()) {
				map[equations[i].first] = nodes;
				a = nodes;
				nodes++;
				graph[a][a] = 1;
				linked[a][a] = true;
			}
			else {
				a = map[equations[i].first];
			}
			if (map.find(equations[i].second) == map.end()) {
				map[equations[i].second] = nodes;
				b = nodes;
				nodes++;
				graph[b][b] = 1;
				linked[b][b] = true;
			}
			else {
				b = map[equations[i].second];
			}
			graph[a][b] = values[i];
			graph[b][a] = 1 / values[i];
			linked[a][b] = true;
			linked[b][a] = true;
		}
		for (int k = 0; k < nodes; k++) {
			for (int i = 0; i < nodes; i++) {
				for (int j = 0; j < nodes; j++) {
					if ((linked[i][k]) && (linked[k][j])) {
						graph[i][j] = graph[i][k] * graph[k][j];
						linked[i][j] = true;
					}
				}
			}
		}
		for (int i = 0; i < m; i++) {
			if ((map.find(queries[i].first) != map.end()) && (map.find(queries[i].second) != map.end())) {
				a = map[queries[i].first];
				b = map[queries[i].second];
				result[i] = graph[a][b];
			}
		}
		return result;
	}
};

int main() {
	Solution solution;
	vector<pair<string, string>> equations;
	vector<pair<string, string>> queries;
	vector<double> values = { 1.0,1.0 }, result;
	pair<string, string> temp;
	temp.first = "a";
	temp.second = "b";
	equations.push_back(temp);
	temp.first = "c";
	temp.second = "d";
	equations.push_back(temp);
	temp.first = "a";
	temp.second = "c";
	queries.push_back(temp);
	temp.first = "b";
	temp.second = "d";
	queries.push_back(temp);
	temp.first = "b";
	temp.second = "a";
	queries.push_back(temp);
	temp.first = "d";
	temp.second = "d";
	queries.push_back(temp);
	result = solution.calcEquation(equations, values, queries);
	int n = result.size();
	for (int i = 0; i < n; i++) {
		cout << result[i] << " ";
	}
	cout << endl;
	system("PAUSE");
	return 0;
}