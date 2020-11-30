#include <iostream>
#include <cstdio>
#include <string>
#include "string.h"
#include <algorithm>

using namespace std;

int main() {
	char s[1000000];
	scanf("%s", s);

	string result;
	for (int i = 0, j = 0; s[i]; i++, j++) {
		switch (s[i]) {
			case 'R':
			result += 'S';
			break;
			case 'B':
			result += 'K';
			break;
			case 'L':
			result += 'H';
		}
		if (j >= 2) {
			string combo = result.substr(j - 2, 3);
			sort(combo.begin(), combo.end());
			if (combo == "HKS") {
				result[j - 2] = 'C';
				result.erase(j - 1, 2);
				j -= 2;
			}
		}
	}
	printf("%s", result.c_str());
	return 0;
}