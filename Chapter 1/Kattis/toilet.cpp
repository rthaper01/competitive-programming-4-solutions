#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

void swap(vector<char>& v, int i) {
	if (v[i] == 'D') {
		v[i] = 'U';
	}
	else if (v[i] == 'U') {
		v[i] = 'D';
	}
}

int main() {
	vector<int> policies(3);
	string s;
	cin >> s;
	vector<char> pos(3);
	pos[0] = pos[1] = pos[2] = s[0];
	for (int i = 1; i < s.length(); i++) {
		if (s[i] != pos[0]) {
			policies[0]++;
			swap(pos, 0);
		}
		if (s[i] != pos[1]) {
			policies[1]++;
			swap(pos, 1);
		}
		if (s[i] != pos[2]) {
			policies[2]++;
			swap(pos, 2);
		}
		if (pos[0] == 'D') {
			policies[0]++;
			swap(pos, 0);
		}
		if (pos[1] == 'U') {
			policies[1]++;
			swap(pos, 1);
		}
	}
	cout << policies[0] << "\n" << policies[1] << "\n" <<
			policies[2];
	return 0;
}