#include "../../cpfacilities.h"

using namespace std;

int main() {
	int L, x, n, curr = 0, denied = 0;
	scanf("%d%d", &L, &x);
	char event[10];
	while (x--) {
		scanf("%s%d", event, &n);
		if (event[0] == 'e') {
			curr += n;
			if (curr > L) {
				denied++;
				curr -= n;
			}
		}
		else {
			curr -= n;
		}
	}
	printf("%d", denied);
	return 0;
}
