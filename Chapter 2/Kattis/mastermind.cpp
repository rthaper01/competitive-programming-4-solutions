#include <iostream>
#include <vector>
#include <algorithm>
#include "stdio.h"

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<char> code(n);
	vector<char> guess(n);
	scanf(" ");
	for (int i = 0; i < n; i++) {
		scanf("%c", &code[i]);
	}
	scanf(" ");
	for (int i = 0; i < n; i++) {
		scanf("%c", &guess[i]);
	}
	int r = 0, s = 0;
	for (int i = 0; i < guess.size(); i++) {
		if (code[i] == guess[i]) {
			r++;
			code.erase(code.begin() + i);
			guess.erase(guess.begin() + i);
			i--;
		}
	}
	for (int i = 0; i < guess.size(); i++) {
		if (find(code.begin(), code.end(), guess[i]) != code.end()) {
			s++;
			code.erase(find(code.begin(), code.end(), guess[i]));
		}
	}
	printf("%d %d", r, s);
	return 0;
}
