#include <iostream>
#include <unordered_set>
#include <algorithm>
#include "stdio.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, M, a, b;
    while (true) {
        cin >> N >> M;
        if (N == 0 && M == 0) {
            break;
        }

        unordered_set<int> jack;

        int common = 0;

        while (N--) {
            cin >> a;
            jack.insert(a);
        }
        while (M--) {
            cin >> b;
            if (jack.count(b) > 0) {
                common++;
                jack.erase(b);
            }
        }
        cout << common << endl;
    }
    return 0;
}