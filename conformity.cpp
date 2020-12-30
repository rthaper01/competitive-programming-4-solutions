#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>
#include <algorithm>
#include "stdio.h"

using namespace std;

int main() {
    int N;
    cin >> N;

    unordered_map<string, int> courses;
    int max = -1;
    set<int> max_set;
    while (N--) {
        vector<string> v(5);
        for (int i = 0; i < 5; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        string s;
        for (int i = 0; i < 5; i++) {
            s += v[i];
        }
        courses[s]++;
        if (courses[s] >= max) {
            max = courses[s];
        }
    }
    int total = 0;
    for (auto perm : courses) {
        if (perm.second == max) {
            total += perm.second;
        }
    }
    cout << total << endl;
    return 0;
}