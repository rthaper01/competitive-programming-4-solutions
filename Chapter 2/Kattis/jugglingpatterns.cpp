#include <iostream>
#include "stdio.h"
#include <string>
#include <set>

using namespace std;

int main() {
    string s;
    while (cin >> s && !cin.eof()) {
        cout << s << ": ";
        int sum = 0;
        for (int i = 0; i < s.length(); i++) {
            sum += (s[i] - '0');
        }
        if (sum % s.length() != 0) {
            cout << "invalid # of balls" << endl;
            continue;
        }
        else {
            int balls = sum / s.length();
            set<int> st;
            for (int i = 0; i < s.length(); i++) {
                st.insert(((s[i] - '0') + i) % s.length());
            }
            if (st.size() == s.length()) {
                cout << "valid with " << balls << " balls" << endl;
                continue;
            }
            else {
                cout << "invalid pattern" << endl;
                continue;
            }
        }
    }
    return 0;
}