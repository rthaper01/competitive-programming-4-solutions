#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	int k, c = 1;
	while (scanf("%d", &k) != EOF) {
		int i, max = -1e7, min = 1e7;
		while (k--) {
			scanf("%d", &i);
			if (i > max) {
				max = i;
			}
			if (i < min) {
				min = i;
			}
		}
		printf("Case %d: %d %d %d\n", c++, min, max, max - min);
	}
	return 0;
}
