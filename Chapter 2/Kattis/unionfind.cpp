#include <iostream>
#include <vector>
#include "stdio.h"

using namespace std;

int findSet(int i, int* v) {
    if (v[i] == i) {
        return i;
    }
    else {
        v[i] = findSet(v[i], v);
        return v[i];
    }
}

bool isSameSet(int i, int j, int* v) {
    return (findSet(i, v) == findSet(j, v));
}

void unionSet(int i, int j, int* v, int* r) {
    if (isSameSet(i, j, v)) {
        return;
    }
    int x = findSet(i, v), y = findSet(j, v);
    if (r[x] > r[y]) {
        swap(x, y);
    }
    v[x] = y;
    if (r[x] == r[y]) {
        r[y]++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, Q;
    scanf("%d%d\n", &N, &Q);

    int p[N];
    for (int i = 0; i < N; i++) {
        p[i] = i;
    }
    int rank[N];

    int a, b;

    for (int i = 0; i < Q; i++) {
        char ch;
        scanf("%c", &ch);
        if (ch == '=') {
            scanf("%d%d\n", &a, &b);
            unionSet(a, b, p, rank);
        }
        else if (ch == '?') {
            scanf("%d%d\n", &a, &b);
            if (isSameSet(a, b, p)) {
                printf("yes\n");
            }
            else {
                printf("no\n");
            }
        }
    }
    return 0;
}