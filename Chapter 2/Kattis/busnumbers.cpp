#include <iostream>
#include "stdio.h"

using namespace std;

bool nums[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    while (N--) {
        int n;
        cin >> n;
        nums[n] = true;
    }

    for (int i = 1; i <= 1000; i++) {
        if (nums[i] == true) {
            cout << i;
            int j = i;
            while (j <= 1000 && nums[j] == true) {
                j++;
            }
            if (j == i + 2) {
                i = j - 2;
            }
            else if (j > i + 2) {
                cout << "-" << j - 1;
                i = j - 1;
            }
            cout << " ";
        }
    }
    cout << endl;
    return 0;
}