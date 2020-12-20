#include <iostream>
#include <vector>
#include "stdio.h"

using namespace std;

const int MAX_AGE = 101;

void print_vec(vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void counting_sort(vector<int>& ages) {
    vector<int> freqs(MAX_AGE);
    vector<int> sorted(ages.size());
    for (int age : ages) {
        freqs[age]++;
    }
    for (int i = 1; i < MAX_AGE; i++) {
        freqs[i] += freqs[i - 1];
    }
    for (int i = ages.size() - 1; i >= 0; i--) {
        sorted[freqs[ages[i]] - 1] = ages[i];
        freqs[ages[i]]--;
    }
    ages = sorted;
}

void solve() {
    int N, age;
    vector<int> ages;
    while (scanf("%d", &N) && N != 0) {
        ages.resize(N);
        for (int i = 0; i < N; i++) {
            scanf("%d", &ages[i]);
        }
        counting_sort(ages);
        for (int i = 0; i < ages.size() - 1; i++) {
            printf("%d ", ages[i]);
        }
        printf("%d\n", ages[ages.size() - 1]);
    }
}

int main() {
    solve();
    return 0;
}