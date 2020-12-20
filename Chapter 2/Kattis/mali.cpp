#include <iostream>
#include <vector>
#include <algorithm>
#include "stdio.h"

using namespace std;

int calc(vector<int> v1, vector<int> v2) {
    int i1 = 0, i2 = 100;
    int least = 0;
    bool done = false;

    while (true) {
        while (v1[i1] == 0) {
            i1++;
            if (i1 > 100) {
                done = true;
                break;
            }
        }
        while (v2[i2] == 0) {
            i2--;
            if (i2 < 0) {
                done = true;
                break;
            }
        }
        if (done) break;

        least = max(least, i1 + i2);
        int m = min(v1[i1], v2[i2]);
        v1[i1] -= m;
        v2[i2] -= m;
    }
    return least;
}

int main() {
    int N, a, b;
    vector<int> as(101);
    vector<int> bs(101);
    scanf("%d", &N);
    while (N--) {
        scanf("%d%d", &a, &b);
        as[a]++;
        bs[b]++;
        int ans = calc(as, bs);
        printf("%d\n", ans);
    }
    return 0;
}