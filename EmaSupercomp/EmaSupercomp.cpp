#include <iostream>
#include <fstream> 
#include <string>
#include <vector>
#include <algorithm>
#include <time.h>

using  namespace std;

vector<string> split_string(string);

// Complete the twoPluses function below.
int twoPluses(const vector<string>& grid) 
{
	return 0;
}

int main()
{
	//ifstream fin("D:\\projects\\hacker_rank\\EmaSupercomp\\input00.txt", std::ofstream::in);
	ifstream fin("D:\\projects\\hacker_rank\\EmaSupercomp\\input01.txt", std::ofstream::in);

	string nm_temp;
	getline(fin, nm_temp);

	vector<string> nm = split_string(nm_temp);

	int n = stoi(nm[0]);

	int m = stoi(nm[1]);

	vector<string> grid(n);

	for (int i = 0; i < n; i++) {
		string grid_item;
		getline(fin, grid_item);

		grid[i] = grid_item;
	}

	int result = twoPluses(grid);

	cout << result << "\n";

	return 0;
}

vector<string> split_string(string input_string) {
	string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
		return x == y and x == ' ';
	});

	input_string.erase(new_end, input_string.end());

	while (input_string[input_string.length() - 1] == ' ') {
		input_string.pop_back();
	}

	vector<string> splits;
	char delimiter = ' ';

	size_t i = 0;
	size_t pos = input_string.find(delimiter);

	while (pos != string::npos) {
		splits.push_back(input_string.substr(i, pos - i));

		i = pos + 1;
		pos = input_string.find(delimiter, i);
	}

	splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

	return splits;
}
