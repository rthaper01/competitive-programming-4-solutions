#include <iostream>
#include <vector>
#include "stdio.h"
#include <algorithm>

using namespace std;

long merge(vector<int>& result, vector<int>& v1, vector<int>& v2) {
    int m = v1.size(), n = v2.size();
    int i = 0, j = 0;
    long inversions = 0;
    while (i < m && j < n) {
        if (v1[i] > v2[j]) {
            result.push_back(v2[j]);
            inversions += m - i;
            j++;
        }
        else {
            result.push_back(v1[i]);
            i++;
        }
    }
    while (i < m) {
        result.push_back(v1[i]);
        i++;
    }
    while (j < n) {
        result.push_back(v2[j]);
        j++;
    }
    return inversions;
}

long inversion_index(vector<int>& perm) {
    int n = perm.size();
    if (n <= 1) {
        return 0;
    }
    else {
        vector<int> v1(n / 2);
        vector<int> v2;
        if (n % 2 == 0) {
            v2.resize(n / 2);
        }
        else {
            v2.resize(n / 2 + 1);
        }
        copy(perm.begin(), perm.begin() + n / 2, v1.begin());
        copy(perm.begin() + n / 2, perm.end(), v2.begin());
        long ans = inversion_index(v1) + inversion_index(v2);
        perm.clear();
        ans += merge(perm, v1, v2);
        return ans;
    }
}

int main() {
    int N;
    scanf("%d", &N);
    vector<int> start(N);
    vector<int> end(N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &start[i]);
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &end[i]);
    }
    if ((inversion_index(end) - inversion_index(start)) % 2 == 0) {
        printf("Possible\n");
    }
    else {
        printf("Impossible\n");
    }
    return 0;
}