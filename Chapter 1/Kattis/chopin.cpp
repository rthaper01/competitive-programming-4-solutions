#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

int main() {
	string input;
	int i = 1;
	while (!getline(cin, input).eof()) {
		string result;
		if (input[1] == '#') {
			if (input[0] == 'G') {
				result += "A";
			}
			else {
				char letter = input[0] + 1;
				result += letter;
			}
			result += 'b';
			result += input.substr(2, 6);
		}
		else if (input[1] == 'b') {
			if (input[0] == 'A') {
				result += "G";
			}
			else {
				char letter = input[0] - 1;
				result += letter;
			}
			result += '#';
			result += input.substr(2, 6);
		}
		else {
			result = "UNIQUE";
		}
		cout << "Case " << i << ": " << result << endl;
		i++;
	}
	return 0;
}