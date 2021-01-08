#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

char cards[13][5];

bool are_valid(char c1, char c2, char c3) {
    if (c1 == c2 && c2 == c3) {
        return true;
    }
    else if (c1 != c2 && c2 != c3 && c1 != c3) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    char ch;
    for (int i = 0; i < 12; i++) {
        scanf("%s", cards[i]);
        scanf("%c", &ch);
    }
    bool exists_set = false;
    for (int i = 0; i < 12; i++) {
        for (int j = i + 1; j < 12; j++) {
            for (int k = j + 1; k < 12; k++) {
                bool is_set = true;
                for (int l = 0; l < 4; l++) {
                    if (!are_valid(cards[i][l], cards[j][l], cards[k][l])) is_set = false;
                }
                if (is_set) {
                    printf("%d %d %d\n", i + 1, j + 1, k + 1);
                    exists_set = true;
                }
            }
        }
    }
    if (!exists_set) {
        printf("no sets\n");
    }
    return 0;
}