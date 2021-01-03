#include <iostream>
#include "stdio.h"
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

set<long> divisors(long n) {
    set<long> divs;
    for (long i = 1; i <= (long) sqrt(n); i++) {
        if (n % i == 0) {
            divs.insert(i);
            divs.insert(n / i);
        }
    }
    return divs;
}

int main() {
    long N;
    scanf("%ld", &N);
    set<long> factors = divisors(N);
    for (auto factor : factors) {
        printf("%ld ", factor - 1);
    }
    printf("\n");
    return 0;
}