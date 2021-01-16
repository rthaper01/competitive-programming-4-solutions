#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int num_quick_changes(string& s1, string& s2) {
    vector<int> freqs1(26);

    for (int i = 0; i < s1.length(); i++) {
        freqs1[s1[i] - 'A']++;
    }

    int quick_changes = 0;
    for (int i = 0; i < s2.length(); i++) {
        if (freqs1[s2[i] - 'A'] == 1) {
            quick_changes++;
        }
    }
    return quick_changes;
}

string routines[11];
int changes[11][11], perm[11];

int main() {
    int R;
    scanf("%d", &R);
    for (int i = 0; i < R; i++) {
        char rtn[27];
        scanf("%s", rtn);
        routines[i] = rtn;
    }

    for (int i = 0; i < R; i++) {
        for (int j = i + 1; j < R; j++) {
            changes[i][j] = num_quick_changes(routines[i], routines[j]);
            changes[j][i] = changes[i][j];
        }
    }

    for (int i = 0; i < R; i++) {
        perm[i] = i;
    }

    int min_quick_changes = 10000;

    do {
        int total = 0;
        for (int i = 0; i < R - 1; i++) {
            total += changes[perm[i]][perm[i + 1]];
        }
        if (total < min_quick_changes) min_quick_changes = total;
    } while (next_permutation(perm, perm + R));

    printf("%d\n", min_quick_changes);
    return 0;
}
