#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;

class NumMatrix {
private:
	vector<vector<int>> nummatrix;
public:
	NumMatrix(vector<vector<int>> &matrix) {
		int col_len, row_len, sum;
		row_len = matrix.size();
		if (row_len != 0)
		{
			vector<int> rows = matrix[0], tmp, last_row;
			col_len = rows.size();
			for (int i = 0; i <= col_len; i++)
				tmp.push_back(0);
			nummatrix.push_back(tmp);
			for (int i = 0; i < row_len; i++)
			{
				tmp.clear();
				rows = matrix[i];
				last_row = nummatrix[i];
				tmp.push_back(0);
				for (int j = 0; j < col_len; j++)
				{
					sum = tmp[j] + last_row[j + 1] + rows[j] - last_row[j];
					tmp.push_back(sum);
				}
				nummatrix.push_back(tmp);
			}
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		int sum;
		vector<int> rows1=nummatrix[row1];
		vector<int> rows2=nummatrix[row2+1];
		sum = rows2[col2 + 1] - rows1[col2 + 1] + rows1[col1] - rows2[col1];
		return sum;
	}
};

int main()
{
	vector<vector<int>> nums;
	vector<int> rows;
	int num;
	int a, b, c, d;
	for (int i = 0; i < 5; i++)
	{
		rows.clear();
		for (int j = 0; j < 5; j++)
		{
			cin >> num;
			rows.push_back(num);
		}
		nums.push_back(rows);
	}
	cout << nums.size() << endl;
	rows = nums[0];
	cout << rows.size() << endl;
	NumMatrix numarray(nums);
	while (true)
	{
		cout << "input index" << endl;
		cin >> a >> b >> c >> d;
		cout << numarray.sumRegion(a, b, c, d) << endl;
	}
	system("PAUSE");
	return 0;
}