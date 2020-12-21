#include <iostream>

using namespace std;

int main() {
    int n;
    while (scanf("%d", &n) && n != 0) {
        int k = 0, a = 0;
        for (int i = 0; i < 31; i++) {
            if (n & (1 << i)) {
                k++;
                if (k % 2 == 1) {
                    a += (1 << i);
                }
            }
        }
        int b = n - a;
        printf("%d %d\n", a, b);
    }
    return 0;
}