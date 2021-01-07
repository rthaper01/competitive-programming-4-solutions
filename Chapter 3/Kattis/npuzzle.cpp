#include <iostream>
#include "stdio.h"

using namespace std;

char solved[4][4] = {{'A','B','C','D'},{'E','F','G','H'},
                     {'I','J','K','L'},{'M','N','O','.'}};

int main() {
    int scatter = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            char ch;
            scanf("%c", &ch);
            if (ch != '.') {
                for (int r = 0; r < 4; r++) {
                    for (int c = 0; c < 4; c++) {
                        if (solved[r][c] == ch) {
                            scatter += abs(r - i) + abs(c - j);
                        }
                    }
                }
            }
        }
        scanf("\n");
    }
    printf("%d", scatter);
    return 0;
}
