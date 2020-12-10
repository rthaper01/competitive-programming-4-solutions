#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>
#include <cstdio>
#include <utility>
#include <sstream>
#include <string>

using namespace std;

const unordered_map<int, string> rows = {{0,"A"},{1,"B"},{2,"C"},{3,"D"},{4,"E"},{5,"F"},{6,"G"},{7,"H"}};
const unordered_map<char, int> rows_reverse = {{'A',0},{'B',1},{'C',2},{'D',3},{'E',4},{'F',5},{'G',6},{'H',7}};

bool in_bounds(pair<int, int> square) {
	if (square.first <= 7 && square.second <= 7 && square.first >= 0 &&
		square.second >= 0) {
		return true;
	}
	else {
		return false;
	}
}

string convert_to_string(pair<int, int> cell) {
	if (cell.first == -1) {
		return "";
	}
	else {
		stringstream ss;
		ss << cell.second + 1;
		string result = rows[cell.first] + " " + ss.str();
		return result;
	}
}

pair<int, int> convert_to_pair(string square) {
	pair<int, int> result;
	result.first = rows_reverse[square[0]];
	result.second = square[2] - '1';
	return result;
}

set<pair<int, int>> generate_diagonals(string s1) {
	pair<int, int> cell = convert_to_pair(s1);
	set<pair<int, int>> result;
	for (int i = 0; i < 8; i++) {
		if (in_bounds({cell.first + i, cell.second + i})) {
			result.insert({cell.first + i, cell.second + i});
		}
		if (in_bounds({cell.first - i, cell.second + i})) {
			result.insert({cell.first - i, cell.second + i});
		}
		if (in_bounds({cell.first + i, cell.second - i})) {
			result.insert({cell.first + i, cell.second - i});
		}
		if (in_bounds({cell.first - i, cell.second - i})) {
			result.insert({cell.first - i, cell.second - i});
		}
	}
	return result;
}

pair<int, int> find_common(string s1, string s2) {
	set<pair<int, int>> diag_one = generate_diagonals(s1);
	set<pair<int, int>> diag_two = generate_diagonals(s2);

	pair<int, int> common = {-1, -1};
	for (auto diag : diag_one) {
		if (diag_two.count(diag) > 0) {
			common = diag;
			break;
		}
	}
	return common;
}

int main() {
	int T;
	string s;
	cin >> T;
	scanf("\n");
	while (T--) {
		getline(cin, s);
		string square_one = s.substr(0, 3);
		string square_two = s.substr(4);
		string ans = convert_to_string(find_common(square_one, square_two));
		if (ans.empty()) {
			cout << "Impossible" << endl;
		}
		else if (ans == square_one && ans == square_two) {
			cout << "0 " << ans << endl;
		}
		else if ((ans == square_one && ans != square_two) ||
				  (ans != square_one && ans == square_two)) {
			cout << "1 " << square_one << " " << square_two << endl;
		}
		else {
			cout << "2 " << square_one << " " << ans << " " << square_two << endl; 
		}
	}
	return 0;
}

