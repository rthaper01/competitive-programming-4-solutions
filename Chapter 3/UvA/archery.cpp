#include <iostream>
#include "stdio.h"

using namespace std;

int best, n, s, points[60], solution[1000], current[1000];

void backtrack(int num_arrows, int idx, int targ) {
    bool better = false;
    int i, j, k;
    if (targ < 0 || num_arrows > best) return;
    if (targ == 0) {
        if (num_arrows < best) {
            for (i = 0; i < num_arrows; i++) {
                solution[i] = current[i];
            }
            best = num_arrows;
            return;
        }
        for (i = 0; i < num_arrows; i++) {
            if (current[i] > solution[i]) {
                better = true;
                break;
            }
            else if (current[i] < solution[i]) {
                break;
            }
        }
        if (better) {
            for (i = 0; i < num_arrows; i++) {
                solution[i] = current[i];
            }
        }
        return;
    }
    if (idx >= n) return;
    for (j = targ / points[idx]; j >= 0; j--) {
        for (k = num_arrows; k < num_arrows + j; k++) {
            current[k] = points[idx];
        }
        backtrack(num_arrows + j, idx + 1, targ - j * points[idx]);
    }
}

int main() {
    int T, i, j;
    scanf("%d", &T);

    for (i = 1; i <= T; i++) {
        scanf("%d %d", &n, &s);
        for (j = 1; j <= n; j++) {
            scanf("%d", &points[n - j]);
        }
        best = (1<<29);
        backtrack(0, 0, s);
        printf("Case %d: ", i);
        if (best == (1<<29)) {
            printf("impossible\n");
            continue;
        }
        printf("[%d]", best);
        for (j = 0; j < best; j++) {
            printf(" %d", solution[j]);
        }
        printf("\n");
    }
    return 0;
}
