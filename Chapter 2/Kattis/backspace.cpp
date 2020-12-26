#include <iostream>
#include <vector>
#include "stdio.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    char ch;
    vector<char> str;
    while (cin.get(ch) && !isspace(ch)) {
        if (ch != '<') {
            str.push_back(ch);
        }
        else {
            str.pop_back();
        }
    }
    for (int i = 0; i < str.size(); i++) {
        cout << str[i];
    }
    cout << endl;
    return 0;
}