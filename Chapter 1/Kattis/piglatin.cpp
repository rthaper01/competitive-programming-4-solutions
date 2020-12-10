#include <iostream>
#include <string>

using namespace std;

char vowels[6] = {'a', 'e', 'i', 'o', 'u', 'y'};

string convert(string s) {
	for (int i = 0; i <= 5; i++) {
		if (s[0] == vowels[i]) {
			return s + "yay";
		}
	}
	string first;
	string second;
	for (int i = 0; i < s.length(); i++) {
		for (int j = 0; j <= 5; j++) {
			if (s[i] == vowels[j]) {
				first = s.substr(0, i) + "ay";
				second = s.substr(i);
				return second + first;
			}
		}
	}
	return s;
}

int main() {
	string input;
	while (cin >> input) {
		cout << convert(input) << " ";
		if (input == "\n") {
			cout << "\n";
		}
	}
	return 0;
}