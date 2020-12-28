#include <iostream>
#include <vector>
#include "stdio.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string s;
    cin >> s;

    vector<int> freqs(4);
    for (int i = 0; i < s.length(); i++) {
        int val = int(s[i]);
        if (33 <= val && val <= 64) {
            freqs[3]++;
        }
        else if (65 <= val && val <= 90) {
            freqs[2]++;
        }
        else if (91 <= val && val <= 94) {
            freqs[3]++;
        }
        else if (val == 95) {
            freqs[0]++;
        }
        else if (val == 96) {
            freqs[3]++;
        }
        else if (97 <= val && val <= 122) {
            freqs[1]++;
        }
        else {
            freqs[3]++;
        }
    }

    for (int i = 0; i < 4; i++) {
        cout << (double) freqs[i] / (double) s.length() << endl;
    }
    
    return 0;
}