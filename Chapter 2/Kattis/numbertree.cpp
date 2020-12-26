#include <iostream>
#include <vector>
#include <cmath>
#include "stdio.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int H;
    cin >> H;

    int index = 0;

    char ch;
    cin.get(ch);
    while (cin.get(ch) && !isspace(ch)) {
        if (ch == 'L') {
            index = index * 2 + 1;
        }
        else {
            index = index * 2 + 2;
        }
    }

    cout << (long) pow(2, H + 1) - 1 - index << endl;

    return 0;
}