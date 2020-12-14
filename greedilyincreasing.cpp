#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, a;
	scanf("%d", &N);
	int perm[N];
	for (int i = 0; i < N; i++) {
		scanf("%d", &perm[i]);
	}
	vector<int> gis;
	gis.push_back(perm[0]);
	int index = 0;
	while (perm[index] <= N) {
		if (perm[index] > gis.back()) {
			gis.push_back(perm[index]);
		}
		index++;
	}
	int g = gis.size();
	printf("%d\n", g);
	for (int i = 0; i < g; i++) {
		printf("%d ", gis[i]);
	}
	return 0;
}