#include <iostream>
#include <unordered_map>
#include "stdio.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    unordered_map<string, int> votes;

    string name;
    int max = -1;
    int prev_max = -1;
    string max_name = "";
    while (true) {
        getline(cin, name);
        if (name == "***") {
            break;
        }
        votes[name]++;
        if (votes[name] >= max) {
            prev_max = max;
            max = votes[name];
            max_name = name;
        }
    }
    if (prev_max == max) {
        cout << "Runoff!" << endl;
    }
    else {
        cout << max_name << endl;
    }
    return 0;
}