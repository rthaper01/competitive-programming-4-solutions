#include <iostream>
#include <vector>
#include <unordered_map>
#include "stdio.h"
#include <utility>

using namespace std;

unordered_map<int, vector<int>> build_AL(vector<int>& v) {
    unordered_map<int, vector<int>> AL;
    for (int i = 0; i < v.size(); i++) {
        AL[v[i]].push_back(i);
    }
    return AL;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while (true) {
        int N, M;
        cin >> N;
        if (cin.eof()) {
            break;
        }
        cin >> M;
        vector<int> arr(N);

        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        unordered_map<int, vector<int>> AL = build_AL(arr);

        int k, v;
        while (M--) {
            cin >> k >> v;
            if (k <= AL[v].size()) {
                cout << AL[v][k - 1] + 1 << endl;
            }
            else {
                cout << 0 << endl;
            }
        }
    }
    return 0;
}