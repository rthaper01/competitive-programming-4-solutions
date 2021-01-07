#include <iostream>
#include "stdio.h"

using namespace std;

int freqs[7][100];

int main() {
    int n, a;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        freqs[a][i]++;
    }

    int max_person = 0;
    for (int i = 1; i <= 6; i++) {
        int num = 0, current_max_person = -1;
        for (int j = 0; j < n; j++) {
            if (freqs[i][j] == 1) {
                num++;
                current_max_person = j + 1;
            }
        }
        if (num == 1) {
            max_person = current_max_person;
        }
    }
    if (max_person == 0) {
        printf("none\n");
    }
    else {
        printf("%d\n", max_person);
    }
}
