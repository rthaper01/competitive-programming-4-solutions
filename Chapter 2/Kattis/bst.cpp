#include <iostream>
#include <set>
#include <vector>
#include "stdio.h"
#include <utility>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> distance(N + 1, 0);

    long counter = 0;
    set<int> elems;

    for (int i = 0; i < N; i++) {
        int elem;
        cin >> elem;

        elems.insert(elem);
        auto it1 = elems.find(elem);
        auto it2 = elems.find(elem);

        int depth = 0;

        if (it1 != elems.begin()) {
            it1--;
            depth = max(depth, distance[*it1]);
        }
        if (it2 != elems.end()) {
            it2++;
            if (it2 != elems.end()) {
                depth = max(depth, distance[*it2]);
            }
        }

        counter += depth;
        distance[elem] = depth + 1;

        cout << counter << endl;
    }
    return 0;
}