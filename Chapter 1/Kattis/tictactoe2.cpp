#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

set<vector<string>> grids;

bool win(vector<string>& grid) {
	for (int i = 0; i < 3; i++) {
		if (grid[i][0] != '.' && grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2]) {
			return true;
		}
		if (grid[0][i] != '.' && grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i]) {
			return true;
		}
	}
	if (grid[0][0] != '.' && grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) {
			return true;
	}
	if (grid[0][2] != '.' && grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]) {
			return true;
	}
	return false;
}

void process(vector<string>& grid, char ch) {
	if (win(grid)) {
		grids.insert(grid);
		return;
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (grid[i][j] == '.') {
				grid[i][j] = ch;
				grids.insert(grid);
				if (ch == 'X') {
					process(grid, 'O');
				}
				else {
					process(grid, 'X');
				}
				grid[i][j] = '.';
			}
		}
	}
}

void process(vector<string> grid) {
	process(grid, 'X');
}

int main() {	
	vector<string> start = {"...", "...", "..."};
	grids.insert(start);
	process(start);

	int N;

	cin >> N;

	while (N--) {
		vector<string> v(3);
		for (auto& s : v) {
			cin >> s;
		}
		if (grids.count(v) > 0) {
			cout << "yes" << endl;
		}
		else {
			cout << "no" << endl;
		}
	}
	return 0;
}