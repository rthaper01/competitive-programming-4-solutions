#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    while (N--) {
        int n, k;
        scanf("%d%d", &n, &k);
        printf("%d\n", k^(k>>1));
    }
    return 0;
}