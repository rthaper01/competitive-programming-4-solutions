#include <iostream>
#include "stdio.h"

using namespace std;

int main() {
    int N, t, res = 0;
    scanf("%d", &N);
    while (N--) {
        scanf("%d", &t);
        if (t < 0) {
            res++;
        }
    }
    printf("%d\n", res);
    return 0;
}