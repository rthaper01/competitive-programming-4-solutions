#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N, t;
	long sum = 0;
	scanf("%d%d", &N, &t);
	int arr[N];
	string result;
	vector<int> vec(3);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	switch (t) {
		case 1:
			printf("%d", 7);
			break;
		case 2:
			if (arr[0] > arr[1]) {
				printf("Bigger");
			}
			else if (arr[0] == arr[1]) {
				printf("Equal");
			}
			else {
				printf("Smaller");
			}
			break;
		case 3:
			for (int i = 0; i <= 2; i++) {
				vec[i] = arr[i];
			}
			sort(vec.begin(), vec.end());
			printf("%d", vec[1]);
			break;
		case 4:
			for (int i = 0; i < N; i++) {
				sum += arr[i];
			}
			printf("%d", sum);
			break;
		case 5:
			for (int i = 0; i < N; i++) {
				if (arr[i] % 2 == 0) {
					sum += arr[i];
				}
			}
			printf("%d", sum);
			break;
		case 6:
			for (int i = 0; i < N; i++) {
				arr[i] = arr[i] % 26;
				if (arr[i] < 0) {
					arr[i] += 26;
				}
				arr[i] += 97;
				char ch = arr[i];
				result += ch;
			}
			printf("%s", result.c_str());
			break;
		case 7:
			int i = 0;
			for (int j = 1; j <= N; j++) {
				i = arr[i];
				if (i == N - 1) {
					printf("Done");
					break;
				}
				if (i < 0 || i >= N) {
					printf("Out");
					break;
				}
				if (j == N) {
					printf("Cyclic");
					break;
				}
		}

	}
	return 0;
}