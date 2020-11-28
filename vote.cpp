#include "../../cpfacilities.h"

using namespace std;

int vector_sum(vector<int> v) {
	int sum = 0;
	for (auto elem : v) {
		sum += elem;
	}
	return sum;
}

int main() {
	int T, n;
	vector<int> votes(10);
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		int max_index = -1, max = -1;
		for (int i = 0; i < n; i++) {
			scanf("%d", &votes[i]);
			if (votes[i] > max) {
				 max = votes[i];
				 max_index = i;
			}
		}
		if (count(votes.begin(), votes.end(), max) > 1) {
			printf("no winner\n");
		}
		else {
			int sum = vector_sum(votes);
			if (max > sum / 2) {
				printf("majority winner %d\n", max_index + 1);
			}
			else {
				printf("minority winner %d\n", max_index + 1);
			}
		}
	}
	return 0;
}